#pragma once

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





#include "Common.h"
#include "Amberskies/Renderer/Buffer.h"



namespace Amber
{

	class OpenGLVertexBuffer : public VertexBuffer
	{

		u32 m_RendererID;

		BufferLayout m_Layout;

	public:

		OpenGLVertexBuffer(
			float* vertices,
			u32 size
		);

		virtual ~OpenGLVertexBuffer();

		virtual void Bind() const override;

		virtual void Unbind() const override;

		virtual const BufferLayout& GetLayout() const override { return m_Layout; };

		virtual void SetLayout(
			const BufferLayout& layout
		) override 
		{
			m_Layout = layout;
		}

	};



	// *******************************************************



	class OpenGLIndexBuffer : public IndexBuffer
	{

		u32 m_RendererID;

		u32 m_Count;

	public:

		OpenGLIndexBuffer(
			u32* indices,
			u32 count
		);

		virtual ~OpenGLIndexBuffer();

		virtual void Bind() const override;

		virtual void Unbind() const override;

		virtual u32 GetCount() const override { return m_Count; }
	};

}
