
#include "Test2D.h"

/**
* ________________________________________________________
* Project Created by Frazor Sharp : 15/02/2022
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

	Test2DLayer::Test2DLayer()
		:
		Layer("Test2D"),
		m_Camera(45, 1920.0f / 1080.0f, 0.5f, 100.0f)
	{
	}



	void Test2DLayer::OnAttach()
	{
	}



	void Test2DLayer::OnDetach()
	{
	}



	void Test2DLayer::OnUpdate(
		DeltaTime deltaTime)
	{
	}



	void Test2DLayer::OnImGuiRender()
	{
	}



	void Test2DLayer::OnEvent(
		Event& event)
	{
	}



	bool Test2DLayer::OnKeyPressed(
		KeyPressedEvent& keyEvent)
	{
		return false;
	}



	bool Test2DLayer::OnMouseButtonPressed(
		MouseButtonPressedEvent& mouseEvent)
	{
		return false;
	}



	void Test2DLayer::NewScene()
	{
	}

}
