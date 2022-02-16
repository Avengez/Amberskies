
#include "Render2D.h"

/**
* ________________________________________________________
* Project Created by Frazor Sharp : 15/02/2022
*
* Twitch : Mini Game Engine Programming in C/C++
*
* Contact Email : daocamberskies@googlemail.com
* Github		: https://github.com/Avengez/Amberskies.git
* Twitch		: frazorbladezsharp
* Youtube		: Frazor Sharp
*
* ______________________________________________________*/




#include "Amberskies/Render3D/VertexArray.h"
#include "Amberskies/Render3D/RenderCommand.h"



namespace Amber
{

	struct Render2DState
	{
		
		Ref<VertexArray> vertexArray;
		
		Ref<Shader> shader;

		Ref<Texture2D> whiteTexture;
		
	};

	static Render2DState s_State;

	void Render2D::Initialize()
	{

		s_State.vertexArray =
			VertexArray::Create();

		float squareVertices[5 * 4] =
		{
			-0.5f, -0.5f, 0.0f,			// btm left
			 0.0f,  0.0f,				// Texture coords
			 0.5f, -0.5f, 0.0f,			// btm right
			 1.0f,  0.0f,
			 0.5f,  0.5f, 0.0f,			// top right
			 1.0f,  1.0f,
			-0.5f,  0.5f, 0.0f,			// top left
			 0.0f,  1.0f
		};

		Ref<VertexBuffer> squareVertexBuffer;

		squareVertexBuffer =
			VertexBuffer::Create(
				squareVertices,
				sizeof(squareVertices)
		);
		
		squareVertexBuffer->SetLayout(
			{
				{ ShaderDataType::Float3, "a_Postion" },
				{ ShaderDataType::Float2, "a_TextureCoord"}
			}
		);

		s_State.vertexArray->AddVertexBuffer(
			squareVertexBuffer
		);

		// ***********************************

		u32 squareIndices[6] =
		{
			0, 1, 2, 2, 3, 0
		};

		Ref<IndexBuffer> squareIndexBuffer;

		squareIndexBuffer =
			IndexBuffer::Create(
				squareIndices,
				sizeof(squareIndices) / sizeof(u32)
		);
		
		s_State.vertexArray->SetIndexBuffer(
			squareIndexBuffer
		);

		// *********************************	

		s_State.whiteTexture =
			Amber::Texture2D::Create(
				1,
				1
			);

		u32 whiteTextureData =
			0xffffffff;

		s_State.whiteTexture->SetData(
			&whiteTextureData,
			sizeof(u32)
		);
		
		s_State.shader = Shader::Create(
			"../Amberskies/Assets/OpenGL_Shaders/Texture.glsl"
		);

		s_State.shader->Bind();

		s_State.shader->SetInt(
			"u_Texture",
			0
		);
		
	}



	void Render2D::Shutdown()
	{

	}



	void Render2D::BeginScene(const PerspectiveCamera& camera)
	{

		
		glm::mat4 viewProjectionMatrix =
			camera.GetProjection() *
			camera.GetViewMatrix();


		
		s_State.shader->Bind();

		s_State.shader->SetMat4(
			"u_ViewProjection", 
			viewProjectionMatrix
		);

	}



	void Render2D::EndScene()
	{

		// Empty

	}

	void Render2D::DrawQuad(
		const glm::vec3& position,
		const glm::vec2& size,
		const float rotationRad,
		const glm::vec4& color)
	{
		s_State.shader->SetFloat4(
			"u_Color",
			color
		);

		//s_State.whiteTexture->Bind();
		s_State.shader->SetInt(
			"u_HasTexture",
			0
		);
	
		glm::mat4 modelMatrix =
			glm::translate(
				glm::mat4(1.0f),
				position
			) *
			glm::rotate(
				glm::mat4(1.0),
				rotationRad,
				{ 0.0f, 0.0f ,1.0f }
			) *
			glm::scale(
				glm::mat4(1.0f),
				glm::vec3(
					size,
					1.0f
				)
			);

		s_State.shader->SetMat4(
			"u_ModelMatrix",
			modelMatrix
		);

		s_State.vertexArray->Bind();

		RenderCommand::DrawIndexed(
			s_State.vertexArray
		);

	}


	void Render2D::DrawQuad(
		const glm::vec3& position,
		const glm::vec2& size,
		const float rotationRad,
		const Ref<Texture2D> texture,
		const glm::vec4& color)
	{

		s_State.shader->SetFloat4(
			"u_Color",
			color
		);

		s_State.shader->SetInt(
			"u_HasTexture",
			1
		);

		glm::mat4 modelMatrix =
			glm::translate(
				glm::mat4(1.0f),
				position
			) *
			glm::rotate(
				glm::mat4(1.0),
				rotationRad,
				{0.0f, 0.0f, 1.0f}
			) *
			glm::scale(
				glm::mat4(1.0f),
				glm::vec3(
					size,
					1.0f
				)
		);

		s_State.shader->SetMat4(
			"u_ModelMatrix",
			modelMatrix
		);

		s_State.vertexArray->Bind();

		texture->Bind();

		RenderCommand::DrawIndexed(
			s_State.vertexArray
		);

	}

}
