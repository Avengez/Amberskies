#pragma once

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





#include "Common.h"
#include "Amberskies/Renderer/RendererAPI.h"


namespace Amber
{

	class OpenGLRendererAPI : public RendererAPI
	{

	public:

		virtual void SetClearColor(
			const glm::vec4& color
		) override;

		virtual void Clear() override;

		virtual void DrawIndexed(
			const std::shared_ptr<VertexArray>& vertexArray
		) override;

	};

}
