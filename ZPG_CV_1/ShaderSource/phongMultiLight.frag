#version 330 core
#define MAX_LIGHTS 4


struct Light {
    vec3 position;
};

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

    // Diffuse lighting
    vec3 norm = normalize(worldNormal);
    vec3 result = ambient;
    for (int i = 0; i < numberOfLights; i++) {
        // Light direction
        vec3 lightDir = normalize(lights[i].position.xyz - worldPosition.xyz);
    
        // Diffuse component Lambert
        float diff = max(dot(norm, lightDir), 0.0);
        vec3 diffuse = diff * objectColor;

        // Specular lighting
        float specularStrength = 0.5;
        vec3 viewDir = normalize(viewPosition - worldPosition.xyz);
        vec3 reflectDir = reflect(-lightDir, norm);
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32.0);
        vec3 specular = specularStrength * spec * vec3(1.0);
    
        // Combine lighting
        result += diffuse + specular;
    }
    
    fragColor = vec4(result, 1.0);
}
