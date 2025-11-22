#version 330 core
#define MAX_LIGHTS 16

// ------------------------------------------------------------
// LIGHT AND MATERIAL STRUCTS
// ------------------------------------------------------------
struct Light {
    int type;                  // 0 = directional, 1 = point, 2 = spot
    bool isOn;                 // Light enabled?
    vec3 position;             // Position (point/spot)
    vec3 direction;            // Direction (directional/spot)
    vec3 color;                // Light color
    float constant;            // Attenuation: constant
    float linear;              // Attenuation: linear
    float quadratic;           // Attenuation: quadratic
    float cutOff;              // Spot inner angle (cos)
    float outerCutOff;         // Spot outer angle (cos)
};

struct Material {
    float ra;                  // Ambient factor
    float rd;                  // Diffuse factor
    float rs;                  // Specular factor
    float h;                   // Shininess exponent
};

// ------------------------------------------------------------
// UNIFORMS
// ------------------------------------------------------------
uniform Material material;
uniform Light lights[MAX_LIGHTS];
uniform int numberOfLights;

uniform vec3 viewPosition;        // Camera/world-space eye position
uniform sampler2D textureUnitID;  // Diffuse texture

// Light type constants
const int LIGHT_TYPE_DIRECTIONAL = 0;
const int LIGHT_TYPE_POINT = 1;
const int LIGHT_TYPE_SPOT = 2;

// ------------------------------------------------------------
// VERTEX INPUTS
// ------------------------------------------------------------
in vec4 worldPosition;     // Fragment world-space position
in vec3 worldNormal;       // Fragment normal (world-space)
in vec2 uv;                // Texture coordinates

// ------------------------------------------------------------
out vec4 fragColor;
// ------------------------------------------------------------

void main(void) {
    // Normalize normal and compute view direction
    vec3 norm = normalize(worldNormal);
    vec3 viewDir = normalize(viewPosition - worldPosition.xyz);

    // --------------------------------------------------------
    // AMBIENT LIGHTING
    // --------------------------------------------------------
    vec3 ambient = vec3(material.ra);
    vec3 result = ambient;

    // --------------------------------------------------------
    // LOOP OVER ALL LIGHTS
    // --------------------------------------------------------
    for (int i = 0; i < numberOfLights; i++) {
        if (!lights[i].isOn)
        continue;              // Skip inactive lights

        vec3 lightDir;             // Direction from fragment to light
        float attenuation = 1.0;   // Default attenuation for directional lights

        // ----------------------------------------------------
        // LIGHT DIRECTION AND ATTENUATION
        // ----------------------------------------------------
        if (lights[i].type == LIGHT_TYPE_DIRECTIONAL) {

            // Directional lights use only direction
            lightDir = normalize(-lights[i].direction);

        } else {
            // Compute vector from fragment to light position
            vec3 toLight = lights[i].position - worldPosition.xyz;
            lightDir = normalize(toLight);

            // Distance to light source
            float distance = length(toLight);

            // Point & spot light attenuation
            attenuation = 1.0 / (lights[i].constant +
            lights[i].linear * distance +
            lights[i].quadratic * distance * distance);

            // ------------------------------------------------
            // SPOTLIGHT INTENSITY
            // ------------------------------------------------
            if (lights[i].type == LIGHT_TYPE_SPOT) {

                // Angle between light direction and fragment direction
                float theta = dot(lightDir, normalize(-lights[i].direction));

                // Smooth step between inner and outer cutoff
                float epsilon = lights[i].cutOff - lights[i].outerCutOff;
                float intensity = clamp((theta - lights[i].outerCutOff) / epsilon, 0.0, 1.0);

                attenuation *= intensity;
            }
        }

        // ----------------------------------------------------
        // DIFFUSE LIGHTING (Lambert)
        // ----------------------------------------------------
        float diff = max(dot(norm, lightDir), 0.0);
        vec3 diffuse = material.rd * diff * lights[i].color;

        // ----------------------------------------------------
        // SPECULAR LIGHTING (BLINN–PHONG)
        // ----------------------------------------------------
        // Halfway vector between light and eye
        vec3 halfwayDir = normalize(lightDir + viewDir);

        // Compute specular intensity
        float specAngle = max(dot(norm, halfwayDir), 0.0);
        float spec = pow(specAngle, material.h);

        vec3 specular = material.rs * spec * lights[i].color;

        // Add combined diffuse + specular, multiplied by attenuation
        result += attenuation * (diffuse + specular);
    }

    // --------------------------------------------------------
    // TEXTURE + FINAL COLOR
    // --------------------------------------------------------
    vec3 texColor = texture(textureUnitID, uv).rgb;

    fragColor = vec4(result * texColor, 1.0);
}
