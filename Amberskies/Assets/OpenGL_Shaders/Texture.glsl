#type vertex
#version 330 core
				
layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec2 a_TextureCoord;

uniform mat4 u_ModelMatrix;
uniform mat4 u_ViewProjection;


out vec2 v_TextureCoord;

void main()
{

	v_TextureCoord = a_TextureCoord;

	gl_Position = u_ViewProjection * u_ModelMatrix * vec4(a_Position, 1.0f);

}


// *****************************************************


#type fragment
#version 330 core
				
layout(location = 0) out vec4 f_Color;


uniform int u_HasTexture;
uniform vec4 u_Color;
uniform sampler2D u_Texture;

in vec2 v_TextureCoord;

void main()
{

	int textureScale = 1;
	if (u_HasTexture)
		f_Color = texture(u_Texture, v_TextureCoord * textureScale) * u_Color;
	else
		f_Color = u_Color;
}
