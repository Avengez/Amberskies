
#include "Renderer.h"

/**
* ________________________________________________________
* Project Created by Frazor Sharp : 19/01/2022
*
* Twitch : Simple Server Programming in C/C++
*
* Contact Email : daocamberskies@googlemail.com
* Github		: https://github.com/Avengez/Amberskies.git
* Twitch		: frazorbladezsharp
* Youtube		: Frazor Sharp
*
* ______________________________________________________*/




namespace Amber
{

	Renderer::SceneData* Renderer::m_SceneData = new Renderer::SceneData;

	void Renderer::BeginScene(
		OrthographicCamera& camera
	)
	{

		m_SceneData->ViewProjectionMatrix =
			camera.GetViewProjectionMatrix();

	}



	void Renderer::EndScene()
	{
		//Empty
	}



	void Renderer::Submit(
		const std::shared_ptr<Shader>& shader,
		const std::shared_ptr<VertexArray>& vertexArray
	)
	{

		shader->Bind();

		shader->UploadUniformMat4(
			"u_ViewProjection",
			m_SceneData->ViewProjectionMatrix
		);

		vertexArray->Bind();

		RenderCommand::DrawIndexed(vertexArray);

	}

}