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
#include <glm/glm.hpp>


namespace Amber
{

	class Shader
	{

		u32 m_RendererID;

	public:

		Shader(
			const std::string& ShaderVertexSource,
			const std::string& ShaderFragmentSource
		);

		~Shader();

		void Bind() const;

		void Unbind() const;

		void UploadUniformMat4(
			const std::string& name,
			const glm::mat4 matrix
		);

	};

}