#pragma once

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





#include <Amberskies.h>




namespace Amber
{
	class Test2DLayer : public Amber::Layer
	{
		PerspectiveCamera m_Camera;

	public:

		Test2DLayer();

		virtual ~Test2DLayer() = default;

		virtual void OnAttach() override;

		virtual void OnDetach() override;

		virtual void OnUpdate(
			DeltaTime deltaTime
		) override;

		virtual void OnImGuiRender() override;

		virtual void OnEvent(
			Event& event
		) override;

	private:

		bool OnKeyPressed(
			KeyPressedEvent& keyEvent
		);

		bool OnMouseButtonPressed(
			MouseButtonPressedEvent& mouseEvent
		);

		void NewScene();

	};
}
