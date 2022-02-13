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
#include "Amberskies/Render2D/TextureAPI.h"
#include <Platform/OpenGL/OpenGLShader.h>




namespace Amber
{

	Ref<Shader> Shader::Create(const std::string& filePath)
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

				return std::make_shared<OpenGLShader>(
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



	Ref<Shader> Shader::Create(
		const std::string& shaderName,
		const std::string& shaderVertexSource,
		const std::string& shaderFragmentSource)
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

				return std::make_shared<OpenGLShader>(
					shaderName,
					shaderVertexSource,
					shaderFragmentSource
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


	// ****************************************************


	void ShaderLibrary::Initialize()
	{

		Load(
			"../Amberskies/Assets/OpenGL_Shaders/FlatColor.glsl"
		);
		
		Load(
			"../Amberskies/Assets/OpenGL_Shaders/Texture.glsl"
		);

		//int slot =
		//	0;

		//std::dynamic_pointer_cast<OpenGLShader>(
		//	textureShader
		//	)->Bind();

		//std::dynamic_pointer_cast<OpenGLShader>(
		//	textureShader)->UploadUniformInt(
		//		"u_Texture", slot
		//	);

	}



	void ShaderLibrary::Add(const Ref<Shader>& shader)
	{

		auto& name = 
			shader->GetName();

		AMBER_ASSERT(
			!Exists(name),
			"[ShaderAPI] Add : Shader already exists"
		);

		m_Shaders[name] = 
			shader;

	}



	Ref<Shader> ShaderLibrary::Load(
		const std::string& filePath)
	{
		
		auto shader = 
			Shader::Create(
				filePath	
		);

		Add(
			shader
		);

		return shader;

	}



	Ref<Shader> ShaderLibrary::Load(
		const std::string& shaderName, 
		const std::string& filePath)
	{

		auto shader =
			Shader::Create(
				filePath
			);

		AMBER_ASSERT(
			!Exists(shaderName),
			"[ShaderAPI] Load : Shader already exists"
		);

		m_Shaders[shaderName] =
			shader;

		return shader;
	
	}



	Ref<Shader> ShaderLibrary::Get(
		const std::string& shaderName)
	{

		AMBER_ASSERT(
			Exists(shaderName),
			"[ShaderAPI] Get : Shader does not exist"
		);

		return m_Shaders[shaderName];
	
	}



	bool ShaderLibrary::Exists(
		const std::string& shaderName) const
	{
	
		return m_Shaders.find(shaderName) != m_Shaders.end();
	}

}
