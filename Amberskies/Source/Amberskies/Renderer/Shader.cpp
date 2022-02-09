#include "Shader.h"

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





#include <glm/gtc/type_ptr.hpp>



namespace Amber
{

	Shader::Shader(
		const std::string& ShaderVertexSource,
		const std::string& ShaderFragmentSource
	) :
		m_RendererID(0)
	{

		// Read our shaders into the appropriate buffers
		std::string vertexSource =
			ShaderVertexSource;// Get source code for vertex shader.
		
		std::string fragmentSource =
			ShaderFragmentSource;// Get source code for fragment shader.

		// Create an empty vertex shader handle
		GLuint vertexShader = 
			glCreateShader(GL_VERTEX_SHADER);

		// Send the vertex shader source code to GL
		// Note that std::string's .c_str is NULL character terminated.
		const GLchar* source = 
			(const GLchar*)vertexSource.c_str();

		glShaderSource(
			vertexShader,
			1, 
			&source, 
			0
		);

		// Compile the vertex shader
		glCompileShader(
			vertexShader
		);

		GLint isCompiled = 
			0;

		glGetShaderiv(
			vertexShader, 
			GL_COMPILE_STATUS, 
			&isCompiled
		);

		if (isCompiled == GL_FALSE)
		{

			GLint maxLength = 
				0;

			glGetShaderiv(
				vertexShader, 
				GL_INFO_LOG_LENGTH, 
				&maxLength
			);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(
				maxLength
			);

			glGetShaderInfoLog(
				vertexShader, 
				maxLength, 
				&maxLength, 
				&infoLog[0]
			);

			// We don't need the shader anymore.
			glDeleteShader(
				vertexShader
			);

			// Use the infoLog as you see fit.

			AMBER_ERROR("[Shader] Error : Vertex Shader Compile");
			AMBER_ERROR("[Shader] {0}", infoLog.data());

			// In this simple program, we'll just leave
			return;

		}

		// Create an empty fragment shader handle
		GLuint fragmentShader = 
			glCreateShader(
				GL_FRAGMENT_SHADER
			);

		// Send the fragment shader source code to GL
		// Note that std::string's .c_str is NULL character terminated.
		source = 
			(const GLchar*)fragmentSource.c_str();

		glShaderSource(
			fragmentShader, 
			1, 
			&source,
			0
		);

		// Compile the fragment shader
		glCompileShader(
			fragmentShader
		);

		glGetShaderiv(
			fragmentShader, 
			GL_COMPILE_STATUS, 
			&isCompiled
		);

		if (isCompiled == GL_FALSE)
		{

			GLint maxLength = 
				0;

			glGetShaderiv(
				fragmentShader, 
				GL_INFO_LOG_LENGTH, 
				&maxLength
			);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(
				maxLength
			);

			glGetShaderInfoLog(
				fragmentShader, 
				maxLength, 
				&maxLength, 
				&infoLog[0]
			);

			// We don't need the shader anymore.
			glDeleteShader(
				fragmentShader
			);

			// Either of them. Don't leak shaders.
			glDeleteShader(
				vertexShader
			);

			// Use the infoLog as you see fit.

			AMBER_ERROR("[Shader] Error : Fragment Shader Compile");
			AMBER_ERROR("[Shader] {0}", infoLog.data());

			// In this simple program, we'll just leave
			return;

		}

		// Vertex and fragment shaders are successfully compiled.
		// Now time to link them together into a program.
		// Get a program object.

		GLuint program = 
			glCreateProgram();

		// Attach our shaders to our program
		glAttachShader(
			program, 
			vertexShader
		);

		glAttachShader(
			program, 
			fragmentShader
		);

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
			glDeleteShader(
				vertexShader
			);

			glDeleteShader(
				fragmentShader
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
			vertexShader
		);

		glDetachShader(
			program, 
			fragmentShader
		);
	}



	Shader::~Shader()
	{

		glDeleteProgram(
			m_RendererID
		);

	}



	void Shader::Bind() const
	{

		glUseProgram(
			m_RendererID
		);

	}



	void Shader::Unbind() const
	{
		glUseProgram(
			GL_FALSE
		);

	}



	void Shader::UploadUniformMat4(
		const std::string& name,
		const glm::mat4 matrix
	)
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
			glm::value_ptr(matrix)
		);

	}

}

