#pragma once

/**
* ________________________________________________________
* Project Created by Frazor Sharp : 15/02/2022
*
* Twitch : Sandbox Programming in C/C++
*
* Contact Email : daocamberskies@googlemail.com
* Github		: https://github.com/Avengez/Amberskies.git
* Twitch		: frazorbladezsharp
* Youtube		: Frazor Sharp
*
* ______________________________________________________*/





#include <Amberskies.h>





	class Test2DLayer : public Amber::Layer
	{
		Amber::PerspectiveCamera m_Camera;

		Amber::Scene* m_MainScene;

		Amber::Ref<Amber::Texture2D> m_TestTexture;

		bool m_ShowFirstWindow = true;
		

	public:

		Test2DLayer();

		virtual ~Test2DLayer() = default;

		virtual void OnAttach() override;

		virtual void OnDetach() override;

		virtual void OnUpdate(
			Amber::DeltaTime deltaTime
		) override;
#ifdef _DEBUG
		virtual void OnImGuiRender() override;
#endif
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

