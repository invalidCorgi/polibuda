#version 330

in vec4 vertex;
in vec4 color;
in vec4 normal;

out vec4 gColor;

void main(void) {
    gColor=color;
    gl_Position=vertex;
}
