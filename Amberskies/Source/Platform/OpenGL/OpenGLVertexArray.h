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

#include "Amberskies/Renderer/VertexArray.h"


namespace Amber
{

	class OpenGLVertexArray : public VertexArray
	{

		u32 m_RendererID = 0;

		std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers;

		std::shared_ptr<IndexBuffer> m_IndexBuffer;

	public:

		OpenGLVertexArray();

		virtual ~OpenGLVertexArray();

		virtual void Bind() const override;

		virtual void Unbind() const override;

		virtual void AddVertexBuffer(
			std::shared_ptr<VertexBuffer>& vertexBuffer
		) override;

		virtual void SetIndexBuffer(
			std::shared_ptr<IndexBuffer>& indexBuffer
		) override;

		virtual const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const { return m_VertexBuffers; }
		
		virtual const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const { return m_IndexBuffer; }
	};

}
