
#include "Core.h"

/**
* ________________________________________________________
* Project Created by Frazor Sharp : 15/02/2022
*
* Twitch : Sand_Rogue Programming in C/C++
*
* Contact Email : daocamberskies@googlemail.com
* Github		: https://github.com/Avengez/Amberskies.git
* Twitch		: frazorbladezsharp
* Youtube		: Frazor Sharp
*
* ______________________________________________________*/




#include <GLFW/glfw3.h>
CoreLayer::CoreLayer()
	:
	Layer("CoreLayer"),
	m_Camera(45, 1920.0f / 1080.0f, 0.5f, 100.0f)
{
}

void CoreLayer::OnAttach()
{
}

void CoreLayer::OnDetach()
{
}

void CoreLayer::OnUpdate(Amber::DeltaTime deltaTime)
{
}

#ifdef _DEBUG
void CoreLayer::OnImGuiRender()
{
}
#endif // DEBUG



void CoreLayer::OnEvent(Amber::Event& event)
{
}

bool CoreLayer::OnKeyPressed(Amber::KeyPressedEvent& keyEvent)
{
	return false;
}

bool CoreLayer::OnMouseButtonPressed(Amber::MouseButtonPressedEvent& mouseEvent)
{
	return false;
}

void CoreLayer::NewScene()
{
}
