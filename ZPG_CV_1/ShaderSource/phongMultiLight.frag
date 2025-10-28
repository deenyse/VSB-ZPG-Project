#version 330 core
#define MAX_LIGHTS 4

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

const int LIGHT_TYPE_DIRECTIONAL = 0;
const int LIGHT_TYPE_POINT = 1;
const int LIGHT_TYPE_SPOT = 2;

uniform Light lights[MAX_LIGHTS];
uniform int numberOfLights;

uniform vec3 viewPosition;

in vec4 worldPosition;
in vec3 worldNormal;

out vec4 fragColor;

void main(void) {
    // Material color
    vec3 objectColor = vec3(0.385, 0.647, 0.812);

    // Ambient lighting
    vec3 ambient = 0.1 * objectColor;

    // Initialize result with ambient
    vec3 result = ambient;
    
    // Diffuse lighting
    vec3 norm = normalize(worldNormal);
    vec3 viewDir = normalize(viewPosition - worldPosition.xyz);
    
    
    for (int i = 0; i < numberOfLights; i++) {

        if (!lights[i].isOn) continue;
        vec3 lightDir;
        float attenuation = 1.0;

        if (lights[i].type == LIGHT_TYPE_DIRECTIONAL) {
            // Directional light
            lightDir = normalize(-lights[i].direction);
        }
        else if (lights[i].type == LIGHT_TYPE_POINT) {
            // Point light
            lightDir = normalize(lights[i].position - worldPosition.xyz);
            float distance = length(lights[i].position - worldPosition.xyz);
            attenuation = 1.0 / (lights[i].constant + lights[i].linear * distance +
                                 lights[i].quadratic * distance * distance);
        }
        else if (lights[i].type == LIGHT_TYPE_SPOT) {
            // Spot light
            lightDir = normalize(lights[i].position - worldPosition.xyz);
            float distance = length(lights[i].position - worldPosition.xyz);
            attenuation = 1.0 / (lights[i].constant + lights[i].linear * distance +
                                 lights[i].quadratic * distance * distance);

            float theta = dot(lightDir, normalize(-lights[i].direction));
            float epsilon = lights[i].cutOff - lights[i].outerCutOff;
            float intensity = clamp((theta - lights[i].outerCutOff) / epsilon, 0.0, 1.0);
            attenuation *= intensity; // Smooth edge falloff
        }

        // Diffuse component (Lambert)
        float diff = max(dot(norm, lightDir), 0.0);
        vec3 diffuse = diff * objectColor * lights[i].color;

        // Specular component
        float specularStrength = 0.5;
        vec3 reflectDir = reflect(-lightDir, norm);
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32.0);
        vec3 specular = specularStrength * spec * lights[i].color;

        // Add to result with attenuation
        result += attenuation * (diffuse + specular);
    }
    
    fragColor = vec4(result, 1.0);
}
