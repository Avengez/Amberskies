#pragma once

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





#include "Common.h"



namespace Amber
{

	class Shader
	{

	public:

		virtual ~Shader() = default;

		virtual void Bind() const = 0;

		virtual void Unbind() const = 0;

		static Shader* Create(
			const std::string& filePath
			);

		static Shader* Create(
			const std::string& ShaderVertexSource,
			const std::string& ShaderFragmentSource
		);

	};

}
