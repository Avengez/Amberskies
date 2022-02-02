
#include "OpenGLContext.h"

/**
* ________________________________________________________
* Project Created by Frazor Sharp : 17/01/2022
*
* Twitch : Simple Server Programming in C/C++
*
* Contact Email : daocamberskies@googlemail.com
* Github		: https://github.com/Avengez/Amberskies.git
* Twitch		: frazorbladezsharp
* Youtube		: Frazor Sharp
*
* ______________________________________________________*/




namespace Amber
{

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{

		AMBER_ASSERT(windowHandle, "[OpenGLContext] windowHandle is null");

	}



	void OpenGLContext::Initialize()
	{

		glfwMakeContextCurrent(
			m_WindowHandle
		);

		int status = gladLoadGLLoader(
			(GLADloadproc)glfwGetProcAddress
		);

		AMBER_ASSERT(status, "[OpenGLContext] Error loading Glad.");

		AMBER_TRACE("[OpenGLContext] OpenGL context created");

		AMBER_TRACE("[OpenGLContext] Renderer : {0}", glGetString(GL_RENDERER));
	
		AMBER_TRACE("[OpenGLContext] GL Version {0}", glGetString(GL_VERSION));
	}



	void OpenGLContext::SwapBuffers()
	{

		glfwSwapBuffers(
			m_WindowHandle
		);

	}

}