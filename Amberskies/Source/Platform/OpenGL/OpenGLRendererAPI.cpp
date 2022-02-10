
#include "OpenGLRendererAPI.h"

/**
* ________________________________________________________
* Project Created by Frazor Sharp : 20/01/2022
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

	void OpenGLRendererAPI::SetClearColor(const glm::vec4& color)
	{

		glClearColor(
			color.r,
			color.g,
			color.b,
			color.a
		);

	}



	void OpenGLRendererAPI::Clear()
	{

		glClear(
			GL_COLOR_BUFFER_BIT |
			GL_DEPTH_BUFFER_BIT
		);

	}



	void OpenGLRendererAPI::DrawIndexed(
		const Ref<VertexArray>& vertexArray
	)
	{

		glDrawElements(
			GL_TRIANGLES,
			vertexArray->GetIndexBuffer()->GetCount(),
			GL_UNSIGNED_INT,
			nullptr
		);

	}

}
