#pragma once

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





#include <Amberskies.h>



	class CoreLayer : public Amber::Layer
	{
		
		Amber::Scene* m_MainScene;

	public:

		CoreLayer();

		virtual ~CoreLayer() = default;

		virtual void OnAttach() override;

		virtual void OnDetach() override;

		virtual void OnUpdate(
			Amber::DeltaTime deltaTime
		) override;

#ifdef _DEBUG
		virtual void OnImGuiRender() override;
#endif // DEBUG

		virtual void OnEvent(
			Amber::Event& event
		) override;

	private:

		bool OnKeyPressed(
			Amber::KeyPressedEvent& keyEvent
		);

		bool OnMouseButtonPressed(
			Amber::MouseButtonPressedEvent& mouseEvent
		);

		void NewScene();

	};
