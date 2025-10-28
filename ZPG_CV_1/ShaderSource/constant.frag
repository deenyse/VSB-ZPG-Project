#version 330 core

out vec4 fragColor;

void main () {
    // Material color
    vec3 objectColor = vec3(0.385, 0.647, 0.812);

    // Ambient lighting
    vec3 ambient = 0.1 * objectColor;

    fragColor = vec4(ambient, 1.0);
}