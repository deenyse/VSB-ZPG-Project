#version 330 core
#define MAX_LIGHTS 16

struct Light {
    int type;            // LightType: 0 = directional, 1 = point, 2 = spot
    bool isOn;           // Is the light on?
    vec3 position;       // Podition (for point/spot)
    vec3 direction;      // direction(for directional/spot)
    vec3 color;          // Color
    float constant;      // Attenuation coefficient
    float linear;        // Linear attenuation coefficient  (more CLOSER distance influence)
    float quadratic;     // Quadratic attenuation coefficient (more FAR distance influence)
    float cutOff;        // Inner angle spot
    float outerCutOff;   // Outer angle spot
};

struct Material {
    vec3 color;
    float ra; // ambient
    float rd; // diffuse
    float rs; // specular
    float h;  // shininess
};

Material material = Material(
    vec3(0.385, 0.647, 0.812), // color
    0.1,  // ra (ambient)
    0.7,  // rd (diffuse)
    0.5,  // rs (specular)
    32.0  // h (shininess)
);

const int LIGHT_TYPE_DIRECTIONAL = 0;
const int LIGHT_TYPE_POINT = 1;
const int LIGHT_TYPE_SPOT = 2;

uniform Light lights[MAX_LIGHTS];
uniform int numberOfLights;

uniform vec3 viewPosition;
uniform sampler2D textureUnitID;

in vec4 worldPosition;
in vec3 worldNormal;
in vec2 uv;

out vec4 fragColor;

void main(void) {
    vec3 norm = normalize(worldNormal);
    vec3 viewDir = normalize(viewPosition - worldPosition.xyz);

    // Ambient
    vec3 ambient = material.ra * material.color;

    vec3 result = ambient;

    for (int i = 0; i < numberOfLights; i++) {
        if (!lights[i].isOn) continue;

        vec3 lightDir;
        float attenuation = 1.0;

        if (lights[i].type == LIGHT_TYPE_DIRECTIONAL) {
            lightDir = normalize(-lights[i].direction);
        } else {
            lightDir = normalize(lights[i].position - worldPosition.xyz);
            float distance = length(lights[i].position - worldPosition.xyz);
            attenuation = 1.0 / (lights[i].constant + lights[i].linear * distance +
                                 lights[i].quadratic * distance * distance);

            if (lights[i].type == LIGHT_TYPE_SPOT) {
                float theta = dot(lightDir, normalize(-lights[i].direction));
                float epsilon = lights[i].cutOff - lights[i].outerCutOff;
                float intensity = clamp((theta - lights[i].outerCutOff) / epsilon, 0.0, 1.0);
                attenuation *= intensity;
            }
        }

        // Diffuse
        float diff = max(dot(norm, lightDir), 0.0);
        vec3 diffuse = material.rd * diff * material.color * lights[i].color;

        // Specular
        vec3 reflectDir = reflect(-lightDir, norm);
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.h);
        vec3 specular = material.rs * spec * lights[i].color;

        result += attenuation * (diffuse + specular);
    }

    // Combine lighting with texture
    vec3 texColor = texture(textureUnitID, uv).rgb;
    fragColor = vec4(result * texColor, 1.0);

}
