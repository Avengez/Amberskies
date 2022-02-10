#include "ShaderAPI.h"

/**
* ________________________________________________________
* Project Created by Frazor Sharp : 09/02/2022
*
* Twitch : Simple Server Programming in C/C++
*
* Contact Email : daocamberskies@googlemail.com
* Github		: https://github.com/Avengez/Amberskies.git
* Twitch		: frazorbladezsharp
* Youtube		: Frazor Sharp
*
* ______________________________________________________*/




#include "Amberskies/Renderer/RendererAPI.h"
#include <Platform/OpenGL/OpenGLShader.h>



namespace Amber
{

	Shader* Shader::Create(const std::string& filePath)
	{
		switch (RendererAPI::GetAPI())
		{

			case RendererAPI::API::None:
			{

				AMBER_ASSERT(
					false,
					"[ShaderAPI] no Renderer API specified."
				);

				break;

			}

			case RendererAPI::API::OpenGL:
			{

				return new OpenGLShader(
					filePath
				);

				break;

			}

			default:
			{

				AMBER_ASSERT(
					false,
					"[ShaderAPI] Unknown Renderer API."
				);

			}

		}

		return nullptr;
	}



	Shader* Shader::Create(
		const std::string& ShaderVertexSource,
		const std::string& ShaderFragmentSource)
	{

		switch (RendererAPI::GetAPI())
		{

			case RendererAPI::API::None:
			{

				AMBER_ASSERT(
					false,
					"[ShaderAPI] no Renderer API specified."
				);

				break;

			}

			case RendererAPI::API::OpenGL:
			{

				return new OpenGLShader(
					ShaderVertexSource,
					ShaderFragmentSource
				);

				break;

			}

			default:
			{

				AMBER_ASSERT(
					false,
					"[ShaderAPI] Unknown Renderer API."
				);

			}

		}

		return nullptr;

	}

}
