#pragma once
#include <cmath>
#include <algorithm>
#include <cstring>

namespace glm {
    // Vector types
    struct vec2 {
        float x, y;
        vec2() : x(0), y(0) {}
        vec2(float x, float y) : x(x), y(y) {}
        vec2 operator+(const vec2& v) const { return vec2(x + v.x, y + v.y); }
        vec2 operator-(const vec2& v) const { return vec2(x - v.x, y - v.y); }
        vec2 operator*(float s) const { return vec2(x * s, y * s); }
        float dot(const vec2& v) const { return x * v.x + y * v.y; }
    };

    struct vec3 {
        float x, y, z;
        vec3() : x(0), y(0), z(0) {}
        vec3(float x, float y, float z) : x(x), y(y), z(z) {}
        vec3 operator+(const vec3& v) const { return vec3(x + v.x, y + v.y, z + v.z); }
        vec3 operator-(const vec3& v) const { return vec3(x - v.x, y - v.y, z - v.z); }
        vec3 operator*(float s) const { return vec3(x * s, y * s, z * s); }
        float dot(const vec3& v) const { return x * v.x + y * v.y + z * v.z; }
        float length() const { return std::sqrt(dot(*this)); }
    };

    struct vec4 {
        float x, y, z, w;
        vec4() : x(0), y(0), z(0), w(0) {}
        vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
        vec4 operator+(const vec4& v) const { return vec4(x + v.x, y + v.y, z + v.z, w + v.w); }
        vec4 operator-(const vec4& v) const { return vec4(x - v.x, y - v.y, z - v.z, w - v.w); }
        vec4 operator*(float s) const { return vec4(x * s, y * s, z * s, w * s); }
    };

    // Matrix type
    struct mat4 {
        float m[4][4];
        mat4() { memset(m, 0, sizeof(m)); }
        mat4(float v) { 
            memset(m, 0, sizeof(m));
            m[0][0] = m[1][1] = m[2][2] = m[3][3] = v;
        }
        vec4 operator*(const vec4& v) const {
            return vec4(
                m[0][0]*v.x + m[0][1]*v.y + m[0][2]*v.z + m[0][3]*v.w,
                m[1][0]*v.x + m[1][1]*v.y + m[1][2]*v.z + m[1][3]*v.w,
                m[2][0]*v.x + m[2][1]*v.y + m[2][2]*v.z + m[2][3]*v.w,
                m[3][0]*v.x + m[3][1]*v.y + m[3][2]*v.z + m[3][3]*v.w
            );
        }
        vec3 operator[](int i) const { return vec3(m[i][0], m[i][1], m[i][2]); }
    };

    // Utility functions
    inline float length(const vec2& v) { return std::sqrt(v.x*v.x + v.y*v.y); }
    inline float length(const vec3& v) { return std::sqrt(v.x*v.x + v.y*v.y + v.z*v.z); }
    inline float distance(const vec2& a, const vec2& b) { return length(a - b); }
    inline float distance(const vec3& a, const vec3& b) { return length(a - b); }
}
