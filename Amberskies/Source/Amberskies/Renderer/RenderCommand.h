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

	class RenderCommand
	{

		static RendererAPI* s_RendererAPI;

	public:

		inline static void Initialize()
		{

			s_RendererAPI->Initialize();

		}

		inline static void SetClearColor(const glm::vec4& color)
		{

			s_RendererAPI->SetClearColor(
				color
			);

		}

		inline static void Clear()
		{

			s_RendererAPI->Clear();

		}


		inline static void DrawIndexed(
			const Ref<VertexArray>& vertexArray
		)
		{

			s_RendererAPI->DrawIndexed(
				vertexArray
			);

		}

		inline static void SetViewport(
			u32 x,
			u32 y,
			u32 width,
			u32 height)
		{

			s_RendererAPI->SetViewport(
				x,
				y,
				width,
				height
			);

		}

	};

}