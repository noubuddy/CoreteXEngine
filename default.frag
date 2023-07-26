#version 330 core

out vec4 FragColor;
in vec3 color;
in vec2 texCoord;

uniform sampler2D tex0;
uniform sampler2D tex1;

void main()
{
    FragColor = texture(tex0, texCoord);
    
//    if (texCoord.y >= 0.95)  // Top face
//        FragColor = texture(tex1, texCoord);
//    else  // Side faces
//        FragColor = texture(tex1, texCoord);
}