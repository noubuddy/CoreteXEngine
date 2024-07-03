#version 330 core

in vec3 color;
in vec2 texCoord;
flat in float texIndex;

out vec4 FragColor;

uniform sampler2D tex0;
uniform sampler2DArray texArray;

void main()
{
//    FragColor = texture(tex0, texCoord);
    FragColor = texture(texArray, vec3(texCoord, texIndex));
}