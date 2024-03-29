#pragma once

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





#include "Common.h"

#include <GLFW/glfw3.h>

#include "Amberskies/Renderer/GFXContext.h"

#include "Platform/OpenGL/glad.h"



namespace Amber
{

	class OpenGLContext : public GFXContext
	{

		GLFWwindow* m_WindowHandle;

	public:

		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Initialize() override;

		virtual void SwapBuffers() override;

	};

}