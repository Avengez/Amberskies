
#include "Buffer.h"

/**
* ________________________________________________________
* Project Created by Frazor Sharp : 19/01/2022
*
* Twitch : Mini Game Engine Programming in C/C++
*
* Contact Email : daocamberskies@googlemail.com
* Github		: https://github.com/Avengez/Amberskies.git
* Twitch		: frazorbladezsharp
* Youtube		: Frazor Sharp
*
* ______________________________________________________*/




#include "Amberskies/Render3D/Renderer.h"

#include "Platform/OpenGL/OpenGLBuffer.h"


namespace Amber
{
	Ref<VertexBuffer> VertexBuffer::Create(
		float* vertices, 
		u32 size)
	{

		switch (Renderer::GetAPI())
		{

			case RendererAPI::API::None:	
			{

				AMBER_ASSERT(false, "[Buffer] no Renderer API specified.")

				break;

			}

			case RendererAPI::API::OpenGL:	
			{
				return CreateRef<OpenGLVertexBuffer>(
					vertices,
					size
				);

				break;
			}

			default:
			{

				AMBER_ASSERT(
					false, 
					"[Buffer] Unknown Renderer API."
				);

			}

		}

		return nullptr;
	
	}



	Ref<IndexBuffer> IndexBuffer::Create(
		u32* indices, 
		u32 size)
	{

		switch (Renderer::GetAPI())
		{

			case RendererAPI::API::None:	
			{

				AMBER_ASSERT(
					false,
					"[Buffer] no Renderer API specified."
				);

				break;

			}

			case RendererAPI::API::OpenGL:	
			{

				return CreateRef<OpenGLIndexBuffer>(
					indices,
					size
				);

				break;
			
			}

			default:
			{

				AMBER_ASSERT(
					false, 
					"[Buffer] Unknown Renderer API."
				);

			}

		}

		return nullptr;
	
	}

}