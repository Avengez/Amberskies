
#include "OpenGLShader.h"

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




#include <glm/gtc/type_ptr.hpp>



namespace Amber
{

	static GLenum ShaderTypeFromString(
		const std::string& type)
	{

		if (type == "vertex")
			return GL_VERTEX_SHADER;

		if (type == "fragment" || type == "pixel")
			return GL_FRAGMENT_SHADER;

		AMBER_ASSERT(
			false,
			"[OpenGLShader] Shader Type From String : Unknown Shader type."
		);

		return GL_FALSE;

	}



	OpenGLShader::OpenGLShader(
		const std::string& filePath
	) :
		m_RendererID(0)
	{

		auto lastSlash =
			filePath.find_last_of(
				"/\\"
		);

		lastSlash =
			lastSlash == std::string::npos ? 0 : lastSlash + 1;

		auto lastDot =
			filePath.rfind(
				'.'
		);

		auto count =
			lastDot == std::string::npos ? filePath.size() - lastSlash : lastDot - lastSlash;

		m_Name = 
			filePath.substr(
				lastSlash,
				count
		);

		std::string source = ReadFile(
			filePath
		);

		auto shaderSources = 
			PreProcessShaderFile(
				source
		);

		Compile(
			shaderSources
		);

	}




	OpenGLShader::OpenGLShader(
		const std::string& shaderName,
		const std::string& shaderVertexSource,
		const std::string& shaderFragmentSource
	) :
		m_RendererID(0),
		m_Name(shaderName)
	{

		std::unordered_map<GLenum, std::string> shaderSources;

		shaderSources[GL_VERTEX_SHADER] =
			shaderVertexSource;

		shaderSources[GL_FRAGMENT_SHADER] =
			shaderFragmentSource;

		Compile(
			shaderSources
		);
		
	}



	OpenGLShader::~OpenGLShader()
	{

		glDeleteProgram(
			m_RendererID
		);

	}



	std::string OpenGLShader::ReadFile(
		const std::string& filePath)
	{
		
		std::string inResult;

		std::ifstream in(
			filePath,
			std::ios::in |			// bit mask types
			std::ios::binary
		);

		if (in)
		{

			in.seekg(
				0,
				std::ios::end
			);

			inResult.resize(
				in.tellg()
			);

			in.seekg(
				0,
				std::ios::beg
			);

			in.read(
				&inResult[0],
				inResult.size()
			);

			in.close();

		}
		else
		{

			AMBER_ERROR(
				"[OpenGLShader] Could not open file : {0}",
				filePath
			);

		}

		return inResult;
	}



	void OpenGLShader::Bind() const
	{

		glUseProgram(
			m_RendererID
		);

	}



	void OpenGLShader::Unbind() const
	{
		glUseProgram(
			GL_FALSE
		);

	}



	void OpenGLShader::UploadUniformMat4(
		const std::string& name,
		const glm::mat4& matrix4x)
	{

		GLint location =
			glGetUniformLocation(
				m_RendererID,
				name.c_str()
			);

		glUniformMatrix4fv(
			location,
			1,
			GL_FALSE,
			glm::value_ptr(matrix4x)
		);

	}



	void OpenGLShader::UploadUniformMat3(
		const std::string& name, 
		const glm::mat3& matrix3x)
	{

		GLint location =
			glGetUniformLocation(
				m_RendererID,
				name.c_str()
			);

		glUniformMatrix3fv(
			location,
			1,
			GL_FALSE,
			glm::value_ptr(matrix3x)
		);
	
	}



	void OpenGLShader::UploadUniformFloat4(
		const std::string& name,
		const glm::vec4& vec4Floats)
	{

		GLint location =
			glGetUniformLocation(
				m_RendererID,
				name.c_str()
			);

		glUniform4f(
			location,
			vec4Floats.x,
			vec4Floats.y,
			vec4Floats.z,
			vec4Floats.w
		);

	}



	void OpenGLShader::UploadUniformFloat3(
		const std::string& name,
		const glm::vec3& vec3Floats)
	{

		GLint location =
			glGetUniformLocation(
				m_RendererID,
				name.c_str()
			);

		glUniform3f(
			location,
			vec3Floats.x,
			vec3Floats.y,
			vec3Floats.z
		);

	}



	void OpenGLShader::UploadUniformFloat2(
		const std::string& name,
		const glm::vec2& vec2Floats)
	{

		GLint location =
			glGetUniformLocation(
				m_RendererID,
				name.c_str()
			);

		glUniform2f(
			location,
			vec2Floats.x,
			vec2Floats.y
		);
	
	}



	void OpenGLShader::UploadUniformFloat(
		const std::string& name,
		const float& singleFloat)
	{

		GLint location =
			glGetUniformLocation(
				m_RendererID,
				name.c_str()
			);

		glUniform1f(
			location,
			singleFloat
		);

	}



	void OpenGLShader::UploadUniformInt(
		const std::string& name, 
		const int& singleInt)
	{

		GLint location =
			glGetUniformLocation(
				m_RendererID,
				name.c_str()
			);

		glUniform1i(
			location,
			singleInt
		);

	}



	std::unordered_map<GLenum, std::string> OpenGLShader::PreProcessShaderFile(
		const std::string& source)
	{

		std::unordered_map<GLenum, std::string> shaderSources;

		const char* typeToken = 
			"#type";

		size_t typeTokenLength =
			strlen(
				typeToken
		);

		size_t pos =
			source.find(
				typeToken,
				0
		);

		while (pos != std::string::npos)
		{

			size_t endOfLine =
				source.find_first_of(
					"\r\n",
					pos
			);

			AMBER_ASSERT(
				endOfLine != std::string::npos,
				"[OpenGLShader] Syntax error Pre-Processing Shader File."
			);

			size_t begin =
				pos + typeTokenLength + 1;

			std::string type =
				source.substr(
					begin,
					endOfLine - begin
			);

			AMBER_ASSERT(
				type == "vertex" ||
				type == "fragment" ||
				type == "pixel",
				"[OpenGLShader] Invalid shader type while Pre-Processing."
			);

			size_t nextLinePos =
				source.find_first_not_of(
					"\r\n",
					endOfLine
			);

			pos =
				source.find(
					typeToken,
					nextLinePos
			);

			shaderSources[ShaderTypeFromString(type)] =
				source.substr(
					nextLinePos,
					pos - (nextLinePos == std::string::npos ? source.size() - 1 : nextLinePos)
			);

		}

		return shaderSources;

	}



	void OpenGLShader::Compile(
		std::unordered_map<GLenum, std::string> shaderSources)
	{

		GLuint program =
			glCreateProgram();

		AMBER_ASSERT(
			shaderSources.size() <= 2,
			"[OpenGLShader] Compile : too many shader sources"
		);

		std::array<GLuint, 2> ShaderID; 

		u8 index = 
			0;

		for (auto& kv : shaderSources)
		{

			GLenum type = 
				kv.first;

			const std::string& sourceString = 
				kv.second;

			GLuint shader =
				glCreateShader(
					type
			);

			const GLchar* source =
				sourceString.c_str();

			glShaderSource(
				shader,
				1,
				&source,
				0
			);

			// Compile the vertex shader
			glCompileShader(
				shader
			);

			GLint isCompiled =
				0;

			glGetShaderiv(
				shader,
				GL_COMPILE_STATUS,
				&isCompiled
			);



			ShaderID[index] =
				shader;

			if (isCompiled == GL_FALSE)
			{

				GLint maxLength =
					0;

				glGetShaderiv(
					shader,
					GL_INFO_LOG_LENGTH,
					&maxLength
				);

				// The maxLength includes the NULL character
				std::vector<GLchar> infoLog(
					maxLength
				);

				glGetShaderInfoLog(
					shader,
					maxLength,
					&maxLength,
					&infoLog[0]
				);

				// We don't need the shader(s) anymore.
				for (GLuint id : ShaderID)
					glDeleteShader(
						id
					);

				glDeleteProgram(
					program
				);

				// Use the infoLog as you see fit.

				AMBER_ERROR("[Shader] Error : Shader Compile");
				AMBER_ERROR("[Shader] {0}", infoLog.data());

				// In this simple program, we'll just leave
				break;

			}

			glAttachShader(
				program,
				shader
			);

			index++;

		}

		// Link our program
		glLinkProgram(
			program
		);

		// Note the different functions here: glGetProgram* instead of glGetShader*.
		GLint isLinked =
			0;

		glGetProgramiv(
			program,
			GL_LINK_STATUS,
			(int*)&isLinked);

		if (isLinked == GL_FALSE)
		{

			GLint maxLength =
				0;

			glGetProgramiv(
				program,
				GL_INFO_LOG_LENGTH,
				&maxLength
			);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(
				maxLength
			);

			glGetProgramInfoLog(
				program,
				maxLength,
				&maxLength,
				&infoLog[0]
			);

			// We don't need the program anymore.
			glDeleteProgram(
				program
			);

			// Don't leak shaders either.
			for (GLuint id : ShaderID)
				glDeleteShader(
					id
			);

			// Use the infoLog as you see fit.

			AMBER_ERROR("[Shader] Error : Shader Link");

			AMBER_ERROR("[Shader] {0}", infoLog.data());

			// In this simple program, we'll just leave
			return;

		}

		m_RendererID =
			program;

		// Always detach shaders after a successful link.
		glDetachShader(
			program,
			ShaderID[0]
		);

		glDetachShader(
			program,
			ShaderID[1]
		);

	}

}
