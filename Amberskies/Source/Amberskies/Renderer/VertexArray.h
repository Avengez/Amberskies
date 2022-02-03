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

#include "Amberskies/Renderer/Buffer.h"



namespace Amber
{

	class VertexArray
	{

	public:

		virtual ~VertexArray() {}

		virtual void Bind() const = 0;

		virtual void Unbind() const = 0;

		virtual void AddVertexBuffer(
			std::shared_ptr<VertexBuffer>& vertexBuffer
		) = 0;

		virtual void SetIndexBuffer(
			std::shared_ptr<IndexBuffer>& indexBuffer
		) = 0;

		virtual const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const = 0;
		virtual const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const = 0;

		static VertexArray* Create();

	};

}
