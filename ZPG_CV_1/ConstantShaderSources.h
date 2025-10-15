#pragma once
const char* vertexShaderSource =
"#version 330 core\n"
"layout(location=0) in vec3 vp;"
"layout(location=1) in vec3 vc;"

"uniform mat4 modelMatrix;"

"out vec3 v_color;"

"void main () {"
"     gl_Position = modelMatrix * vec4 (vp, 1.0);"
"	  v_color = vc;"
"}";


const char* fragmentShaderSource =
"#version 330 core\n"
"in vec3 v_color;"
"out vec4 fragColor;"
"void main () {"
"     fragColor = vec4 (v_color, 1.0);"
"}";


const char* vertexCameraShaderSource =
"#version 330 core\n"
"layout(location=0) in vec3 vp;"
"layout(location=1) in vec3 vc;"

"uniform mat4 modelMatrix;"
"uniform mat4 viewMatrix;"
"uniform mat4 projectionMatrix;"
"out vec3 v_color;"

"void main () {"
"     gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4 (vp, 1.0);"
"	  v_color = vc;"
"}";
