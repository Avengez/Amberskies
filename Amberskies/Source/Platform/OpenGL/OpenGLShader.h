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

#include "Amberskies/Render3D/ShaderAPI.h"
#include <glm/glm.hpp>


namespace Amber
{

	class OpenGLShader : public Shader
	{

		u32 m_RendererID;

		std::string m_Name;

	public:

		OpenGLShader(
			const std::string& filePath
		);

		OpenGLShader(
			const std::string& shaderName,
			const std::string& shaderVertexSource,
			const std::string& shaderFragmentSource
		);

		virtual ~OpenGLShader();

		std::string ReadFile(
			const std::string& filePath
		);

		virtual void Bind() const override;

		virtual void Unbind() const override;


		virtual void SetMat4(
			const std::string& name,
			const glm::mat4 value
		) const override;

		virtual void SetFloat3(
			const std::string& name,
			const glm::vec3 value
		) const override;

		virtual void SetFloat4(
			const std::string& name,
			const glm::vec4 value
		) const override;

		virtual void SetInt(
			const std::string& name,
			const int value
		) const override;


		virtual const std::string& GetName() const override {
			return m_Name; }

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

	private:

		std::unordered_map<GLenum, std::string> PreProcessShaderFile(
			const std::string& source
		);
		
		void Compile(
			std::unordered_map<GLenum, std::string> shaderSources
		);

	};

}