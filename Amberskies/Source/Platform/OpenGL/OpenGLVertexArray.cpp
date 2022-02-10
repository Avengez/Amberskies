
#include "OpenGLVertexArray.h"

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

	static GLenum ShaderDataTypeToOpenGLBaseType(
		ShaderDataType type
	)
	{

		switch (type)
		{

		case ShaderDataType::Float:   return GL_FLOAT;
		case ShaderDataType::Float2:  return GL_FLOAT;
		case ShaderDataType::Float3:  return GL_FLOAT;
		case ShaderDataType::Float4:  return GL_FLOAT;

		case ShaderDataType::Mat3:    return GL_FLOAT;
		case ShaderDataType::Mat4:    return GL_FLOAT;
		case ShaderDataType::Int:     return GL_FLOAT;

		case ShaderDataType::Int2:    return GL_INT;
		case ShaderDataType::Int3:    return GL_INT;
		case ShaderDataType::Int4:    return GL_INT;

		case ShaderDataType::Bool:    return GL_BOOL;

		}

		AMBER_ASSERT(false, "[Application] Unknown ShaderDataType!");
		return 0;

	}



	OpenGLVertexArray::OpenGLVertexArray() 
	{

		glCreateVertexArrays(
			1,
			&m_RendererID
		);

	}



	OpenGLVertexArray::~OpenGLVertexArray()
	{

		glDeleteVertexArrays(
			1,
			&m_RendererID
		);

	}



	void OpenGLVertexArray::Bind() const
	{

		glBindVertexArray(
			m_RendererID
		);

	}
	
	
	
	void OpenGLVertexArray::Unbind() const
	{

		glBindVertexArray(
			GL_FALSE
		);

	}
	
	
	
	void OpenGLVertexArray::AddVertexBuffer(
		Ref<VertexBuffer>& vertexBuffer
	)
	{
		int size = 
			(int)vertexBuffer->GetLayout().GetElements().size();

		AMBER_ASSERT(size != 0, "[OpenGLVertexArray] Vertex Buffer has no Layout");

		glBindVertexArray(
			m_RendererID
		);

		vertexBuffer->Bind();

		const auto& layout = vertexBuffer->GetLayout();

		u32 index =
			0;

		for (const auto& element : layout)
		{

			glEnableVertexAttribArray(
				index
			);

			glVertexAttribPointer(
				index,
				element.GetComponentCount(),
				ShaderDataTypeToOpenGLBaseType(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)element.Offset
			);

			index++;
		}

		m_VertexBuffers.push_back(
			vertexBuffer
		);

	}
	
	
	
	void OpenGLVertexArray::SetIndexBuffer(
		Ref<IndexBuffer>& indexBuffer
	)
	{

		glBindVertexArray(
			m_RendererID
		);

		indexBuffer->Bind();

		m_IndexBuffer = 
			indexBuffer;
	}
}
