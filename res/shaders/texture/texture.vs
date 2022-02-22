#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aCol;
layout (location = 2) in vec2 aUV;

uniform mat4 transform;

out vec4 vCol;
out vec2 vUV;

void main()
{
    gl_Position = transform * vec4(aPos.x, aPos.y, aPos.z, 1.0);
    vCol = aCol;
    vUV = aUV;
}
