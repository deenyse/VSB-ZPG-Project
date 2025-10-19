#version 330 core

in vec4 worldPosition;
in vec3 worldNormal;

out vec4 fragColor;

uniform vec3 lightPosition;
uniform vec3 viewPosition;

void main(void) {
    // Material color
    vec3 objectColor = vec3(0.385, 0.647, 0.812);

    // Ambient lighting
    vec3 ambient = 0.1 * objectColor;

    // Diffuse lighting
    vec3 norm = normalize(worldNormal);
    vec3 lightDir = normalize(lightPosition - worldPosition.xyz);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * objectColor;

    // --- Blinn–Phong specular lighting ---
    float specularStrength = 0.5;
    vec3 viewDir = normalize(viewPosition - worldPosition.xyz);

    // Half-vector (between light direction and view direction)
    vec3 halfwayDir = normalize(lightDir + viewDir);

    // Specular term (Blinn–Phong)
    float spec = pow(max(dot(norm, halfwayDir), 0.0), 32.0);
    vec3 specular = specularStrength * spec * vec3(1.0);

    // Combine all
    vec3 result = ambient + diffuse + specular;
    fragColor = vec4(result, 1.0);
}
