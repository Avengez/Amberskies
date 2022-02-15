#type vertex
#version 330 core
				
layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec2 a_TextureCoord;


uniform mat4 u_ViewProjection;
uniform mat4 u_ModelMatrix;

out vec2 v_TextureCoord;

void main()
{
	v_TextureCoord = a_TextureCoord;
	gl_Position = u_ViewProjection * u_ModelMatrix * vec4(a_Position, 1.0f);
}



#type fragment
#version 330 core
				
layout(location = 0) out vec4 f_Color;

in vec2 v_TextureCoord;

uniform vec4 u_Color;
uniform sampler2D u_Texture;



void main()
{
	f_Color = texture(u_Texture, v_TextureCoord) * u_Color;
}
