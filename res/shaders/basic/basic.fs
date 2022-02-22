#version 330 core

in vec4 vCol;
in vec2 vUV;

out vec4 FragColor;

uniform sampler2D textureSampler;

void main()
{
//   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
//   FragColor = vCol;
   FragColor = texture(textureSampler, vUV);
}
