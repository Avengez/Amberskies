
#include "OpenGLBuffer.h"

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
	OpenGLVertexBuffer::OpenGLVertexBuffer(
		float* vertices, 
		u32 size
	)
	{
		glCreateBuffers(
			1,
			&m_RendererID
		);

		glBindBuffer(
			GL_ARRAY_BUFFER,
			m_RendererID
		);

		glBufferData(
			GL_ARRAY_BUFFER,
			size,
			vertices,
			GL_STATIC_DRAW
		);

	}



	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{

		glDeleteBuffers(
			1,
			&m_RendererID
		);

	}



	void OpenGLVertexBuffer::Bind() const
	{

		glBindBuffer(
			GL_ARRAY_BUFFER,
			m_RendererID
		);

	}
	
	
	
	void OpenGLVertexBuffer::Unbind() const
	{

		glBindBuffer(
			GL_ARRAY_BUFFER,
			GL_FALSE
		);

	}



	// *******************************************************
	


	OpenGLIndexBuffer::OpenGLIndexBuffer(
		u32* indices, 
		u32 count
	) : 
		m_Count(count)
	{

		glCreateBuffers(
			1,
			&m_RendererID
		);

		glBindBuffer(
			GL_ELEMENT_ARRAY_BUFFER,
			m_RendererID
		);

		glBufferData(
			GL_ELEMENT_ARRAY_BUFFER,
			count * sizeof(u32),
			indices,
			GL_STATIC_DRAW
		);

	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{

		glDeleteBuffers(
			1,
			&m_RendererID
		);

	}

	void OpenGLIndexBuffer::Bind() const
	{

		glBindBuffer(
			GL_ELEMENT_ARRAY_BUFFER,
			m_RendererID
		);

	}
	
	
	
	void OpenGLIndexBuffer::Unbind() const
	{

		glBindBuffer(
			GL_ELEMENT_ARRAY_BUFFER,
			GL_FALSE
		);

	}

}
