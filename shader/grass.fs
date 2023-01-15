#version 330 core

out vec4 fragColor;

in vec2 texCoord;

uniform sampler2D tex;

void main() {
	vec4 pixel = texture(tex, texCoord);
	if (pixel.a < 0.05)
		discard;
	fragColor = pixel;
}
