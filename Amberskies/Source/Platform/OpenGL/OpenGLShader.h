#pragma once

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





#include "Common.h"

#include "Amberskies/Renderer/ShaderAPI.h"
#include <glm/glm.hpp>


namespace Amber
{

	class OpenGLShader : public Shader
	{

		u32 m_RendererID;

	public:

		OpenGLShader(
			const std::string& ShaderVertexSource,
			const std::string& ShaderFragmentSource
		);

		virtual ~OpenGLShader();

		virtual void Bind() const override;

		virtual void Unbind() const override;

		void UploadUniformMat4(
			const std::string& name,
			const glm::mat4& matrix4x
		);

		void UploadUniformMat3(
			const std::string& name,
			const glm::mat3& matrix3x
		);

		void UploadUniformFloat4(
			const std::string& name,
			const glm::vec4& vec4Floats
		);

		void UploadUniformFloat3(
			const std::string& name,
			const glm::vec3& vec3Floats
		);

		void UploadUniformFloat2(
			const std::string& name,
			const glm::vec2& vec2Floats
		);

		void UploadUniformFloat(
			const std::string& name,
			const float& singleFloat
		);

		void UploadUniformInt(
			const std::string& name,
			const int& singleInt
		);

	};

}