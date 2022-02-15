
#include "Renderer.h"

/**
* ________________________________________________________
* Project Created by Frazor Sharp : 19/01/2022
*
* Twitch : Mini Game Engine Programming in C/C++
*
* Contact Email : daocamberskies@googlemail.com
* Github		: https://github.com/Avengez/Amberskies.git
* Twitch		: frazorbladezsharp
* Youtube		: Frazor Sharp
*
* ______________________________________________________*/




#include <Platform/OpenGL/OpenGLShader.h>

namespace Amber
{

	Renderer::SceneData* Renderer::m_SceneData = new Renderer::SceneData;



	void Renderer::Initialize()
	{

		RenderCommand::Initialize();

	}



	void Renderer::OnWindowResize(
		u32 width, 
		u32 height)
	{

		RenderCommand::SetViewport(
			0,
			0,
			width,
			height
		);

	}



	void Renderer::BeginScene(
		PerspectiveCamera& camera
	)
	{

		m_SceneData->ViewProjectionMatrix =
			camera.GetProjection() * 
			camera.GetViewMatrix();

	}



	void Renderer::EndScene()
	{
		//Empty
	}



	void Renderer::Submit(
		const Ref<Shader>& shader,
		const Ref<VertexArray>& vertexArray,
		const glm::mat4& modelTransform
	)
	{

		shader->Bind();

		std::dynamic_pointer_cast<OpenGLShader>(
			shader)->UploadUniformMat4(
				"u_ViewProjection",
				m_SceneData->ViewProjectionMatrix			
		);

		std::dynamic_pointer_cast<OpenGLShader>(
			shader)->UploadUniformMat4(
				"u_ModelMatrix",
				modelTransform
		);

		vertexArray->Bind();

		RenderCommand::DrawIndexed(vertexArray);

	}

}