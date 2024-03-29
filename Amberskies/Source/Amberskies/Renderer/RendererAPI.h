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

#include <glm/glm.hpp>

#include "Amberskies/Renderer/VertexArray.h"


namespace Amber
{

	class RendererAPI
	{

		

	public:

		enum class API
		{

			None = 0,
			OpenGL

		};



		virtual void SetClearColor(const glm::vec4& color) = 0;

		virtual void Clear() = 0;

		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) = 0;

		inline static API GetAPI() { return s_API; }

	private:

		static API s_API;

	};

}