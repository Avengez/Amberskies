
#include "WindowsInput.h"

/**
* ________________________________________________________
* Project Created by Frazor Sharp : 18/01/2022
*
* Twitch : Simple Server Programming in C/C++
*
* Contact Email : daocamberskies@googlemail.com
* Github		: https://github.com/Avengez/Amberskies.git
* Twitch		: frazorbladezsharp
* Youtube		: Frazor Sharp
*
* ______________________________________________________*/




#include <GLFW/glfw3.h>
#include "Amberskies/Core/Application.h"



namespace Amber
{

	Input* Input::s_Instance = 
		new WindowsInput();

	bool WindowsInput::IsKeyPressedImpl(int keycode)
	{

		GLFWwindow* window =
			static_cast<GLFWwindow*>(
				Application::Get().GetWindow().GetNativeWindow()
		);

		auto state = glfwGetKey(
			window,
			keycode
		);

		return state == GLFW_PRESS || state == GLFW_REPEAT;

	}



	bool WindowsInput::IsMouseButtonPressedImpl(int button)
	{
		
		GLFWwindow* window =
			static_cast<GLFWwindow*>(
				Application::Get().GetWindow().GetNativeWindow()
		);

		auto state = glfwGetMouseButton(
			window,
			button
		);

		return (state == GLFW_PRESS);

	}



	std::pair<float, float> WindowsInput::GetMousePositionImpl()
	{

		GLFWwindow* window =
			static_cast<GLFWwindow*>(
				Application::Get().GetWindow().GetNativeWindow()
				);

		double x, y;

		glfwGetCursorPos(
			window,
			&x,
			&y
		);

		return { (float)x, (float)y };

	}



	float WindowsInput::GetMouseXImpl()
	{
		
		GLFWwindow* window =
			static_cast<GLFWwindow*>(
				Application::Get().GetWindow().GetNativeWindow()
		);

		double x, y;

		glfwGetCursorPos(
			window,
			&x,
			&y
		);

		return (float)x;

		/*C++17 Alternative
		* auto[x,y] = GetMousePositionImpl();
		* return x
		*/

	}



	float WindowsInput::GetMouseYImpl()
	{
		
		GLFWwindow* window =
			static_cast<GLFWwindow*>(
				Application::Get().GetWindow().GetNativeWindow()
		);

		double x, y;

		glfwGetCursorPos(
			window,
			&x,
			&y
		);

		return (float)y;

		/*C++17 Alternative
		* auto[x,y] = GetMousePositionImpl();
		* return y
		*/

	}

}