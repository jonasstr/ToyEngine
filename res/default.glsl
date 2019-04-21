#shader vertex
#version 330 core

layout (location = 0) in vec2 pos;
layout (location = 1) in vec2 texCoord;

out vec2 v_TexCoord;

void main() {
    gl_Position = vec4(pos, 0.0, 1.0);
    v_TexCoord = texCoord;
}

#shader fragment
#version 330 core

in vec2 v_TexCoord;

out vec4 color;

uniform vec4 u_Color;
uniform sampler2D u_Texture;

void main() {
    vec4 texColor = texture(u_Texture, v_TexCoord);
    color = texColor;
}