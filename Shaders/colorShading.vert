#version 130

in vec2 vertexPosition;
in vec4 vertexColor;
in vec2 vertexUV;

out vec4 fragmentColor;
out vec2 fragmentPosition;
out vec2 fragmentUV;

uniform mat4 P;

void main(){
    gl_Position = vec4( (P * vec4(vertexPosition, 0.0f, 1.0f)).xy, 0.0, 1.0);
    fragmentColor = vertexColor;
    fragmentPosition = vertexPosition;
    fragmentUV = vec2(vertexUV.x, 1.0 - vertexUV.y);
}