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

		virtual const std::string& GetName() const = 0;
		
		static Ref<Shader> Create(
			const std::string& filePath
			);

		static Ref<Shader> Create(
			const std::string& shaderName,
			const std::string& ShaderVertexSource,
			const std::string& ShaderFragmentSource
		);

	};



	class ShaderLibrary
	{

		std::unordered_map<std::string, Ref<Shader>> m_Shaders;

	public:

		void Initialize();

		void Add(
			const Ref<Shader>& shader
		);

		Ref<Shader> Load(
			const std::string& filePath
		);

		Ref<Shader> Load(
			const std::string& shaderName,
			const std::string& filePath
		);

		Ref<Shader> Get(
			const std::string& shaderName
		);

		bool Exists(
			const std::string& shaderName
		) const;

	};

}
