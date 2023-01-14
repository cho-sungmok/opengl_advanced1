#version 330 core

out vec4 fragColor;

in vec4 vertexColor;
in vec2 texCoord;

uniform sampler2D tex;

void main() {
	vec4 pixel = texture(tex, texCoord);
	fragColor = vec4(1.0 - pixel.rgb, 1.0);
}
