
#include "VertexArray.h"

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




#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"



namespace Amber
{

	VertexArray* VertexArray::Create()
	{

		switch (Renderer::GetAPI())
		{

		case RendererAPI::API::None:	AMBER_ASSERT(false, "[VertexArray] no Renderer API specified.")

		case RendererAPI::API::OpenGL:	return new OpenGLVertexArray();

		}

		AMBER_ASSERT(false, "[VertexArray] Unknown Renderer API.");

		return nullptr;

		
	}

}
