#pragma once

/**
* ________________________________________________________
* Project Created by Frazor Sharp : 20/01/2022
*
* Twitch : Mini Game Engine Programming in C/C++
*
* Contact Email : daocamberskies@googlemail.com
* Github		: https://github.com/Avengez/Amberskies.git
* Twitch		: frazorbladezsharp
* Youtube		: Frazor Sharp
*
* ______________________________________________________*/





#include "Common.h"

#include "Amberskies/Render3D/RendererAPI.h"


namespace Amber
{

	class OpenGLRendererAPI : public RendererAPI
	{

	public:

		virtual void Initialize() override;

		virtual void SetClearColor(
			const glm::vec4& color
		) override;

		virtual void Clear() override;

		virtual void DrawIndexed(
			const Ref<VertexArray>& vertexArray
		) override;

		virtual void SetViewport(
			u32 x,
			u32 y,
			u32 width,
			u32 height) override;

	};

}
