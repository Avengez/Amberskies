
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
	m_MainScene(new Amber::Scene())
{
}

void CoreLayer::OnAttach()
{

	Amber::RenderCommand::SetClearColor(
		{
		0.10f,
		0.045f,
		0.012f,
		1.0f
		}
	);

}

void CoreLayer::OnDetach()
{

	delete m_MainScene;

}

void CoreLayer::OnUpdate(Amber::DeltaTime deltaTime)
{

	m_MainScene->OnUpdate(
		deltaTime
	);

}

#ifdef _DEBUG
void CoreLayer::OnImGuiRender()
{
}
#endif // DEBUG



void CoreLayer::OnEvent(Amber::Event& e)
{

	m_MainScene->OnEvent(
		e
	);

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
