#version 330 core

layout(location = 0) in vec3 vp; // vertex position
layout(location = 1) in vec3 vn; // vertex normal
layout(location = 2) in vec2 vt;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

out vec4 worldPosition;
out vec3 worldNormal;
out vec2 uv;

void main(void) {
    // Transform vertex position to world space
    worldPosition = modelMatrix * vec4(vp, 1.0);

    // Transform normal correctly using transpose-inverse of model
    mat3 normalMatrix = transpose(inverse(mat3(modelMatrix)));
    worldNormal = normalize(normalMatrix * vn);

    // Compute clip-space position
    gl_Position = projectionMatrix * viewMatrix * worldPosition;
    uv=vt;

}
