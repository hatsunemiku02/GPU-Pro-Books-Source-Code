// Anisotropic Kuwahara Filtering on the GPU
// by Jan Eric Kyprianidis <www.kyprianidis.com>
#version 120
#extension GL_EXT_gpu_shader4 : enable

uniform sampler2D src;
uniform sampler2D K0123;
uniform sampler2D tfm;
uniform float radius;
uniform float q;
uniform float alpha;

const float PI = 3.14159265358979323846;
const int N = 8;

void main (void) {
    vec2 src_size = vec2(textureSize2D(src, 0));
    vec2 uv = gl_FragCoord.xy / src_size;

    vec4 m[8];
    vec3 s[8];
    for (int k = 0; k < N; ++k) {
        m[k] = vec4(0.0);
        s[k] = vec3(0.0);
    }

    vec4 t = texture2D(tfm, uv);
    float a = radius * clamp((alpha + t.w) / alpha, 0.1, 2.0); 
    float b = radius * clamp(alpha / (alpha + t.w), 0.1, 2.0);

    float cos_phi = cos(t.z);
    float sin_phi = sin(t.z);

    mat2 R = mat2(cos_phi, -sin_phi, sin_phi, cos_phi);
    mat2 S = mat2(0.5/a, 0.0, 0.0, 0.5/b);
    mat2 SR = S * R;

    int max_x = int(sqrt(a*a * cos_phi*cos_phi +
                          b*b * sin_phi*sin_phi));
    int max_y = int(sqrt(a*a * sin_phi*sin_phi +
                          b*b * cos_phi*cos_phi));

    {
        vec3 c = texture2D(src, uv).rgb;
        float w = texture2D(K0123, vec2(0.5, 0.5)).x;
        for (int k = 0; k < N; ++k) {
            m[k] +=  vec4(c * w, w);
            s[k] += c * c * w;
        }
    }

    for (int j = 0; j <= max_y; ++j)  {
        for (int i = -max_x; i <= max_x; ++i) {
            if ((j !=0) || (i > 0)) {
                vec2 v = SR * vec2(i,j);

                if (dot(v,v) <= 0.25) {
                    vec3 c0 = texture2D(src,uv + vec2(i,j)/src_size).rgb;
                    vec3 c1 = texture2D(src,uv - vec2(i,j)/src_size).rgb;

                    vec3 cc0 = c0 * c0;
                    vec3 cc1 = c1 * c1;

                    vec4 w0123 = texture2D(K0123, vec2(0.5, 0.5) + v);
                    for (int k = 0; k < 4; ++k) {
                        m[k] += vec4(c0 * w0123[k], w0123[k]);
                        s[k] += cc0 * w0123[k];
                    }
                    for (int k = 4; k < 8; ++k) {
                        m[k] += vec4(c1 * w0123[k-4], w0123[k-4]);
                        s[k] += cc1 * w0123[k-4];
                    }

                    vec4 w4567 = texture2D(K0123, vec2(0.5, 0.5) - v);
                    for (int k = 4; k < 8; ++k) {
                        m[k] += vec4(c0 * w4567[k-4], w4567[k-4]);
                        s[k] += cc0 * w4567[k-4];
                    }
                    for (int k = 0; k < 4; ++k) {
                        m[k] += vec4(c1 * w4567[k], w4567[k]);
                        s[k] += cc1 * w4567[k];
                    }
                }
            }
        }
    }

    vec4 o = vec4(0.0);
    for (int k = 0; k < N; ++k) {
        m[k].rgb /= m[k].w;
        s[k] = abs(s[k] / m[k].w - m[k].rgb * m[k].rgb);

        float sigma2 = s[k].r + s[k].g + s[k].b;
        float w = 1.0 / (1.0 + pow(255.0 * sigma2, 0.5 * q));

        o += vec4(m[k].rgb * w, w);
    }

    gl_FragColor =  vec4(o.rgb / o.w, 1.0);
}
