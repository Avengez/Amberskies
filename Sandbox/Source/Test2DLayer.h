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





	class Test2DLayer : public Amber::Layer
	{
		Amber::PerspectiveCamera m_Camera;

		Amber::ShaderLibrary m_ShaderLibrary;

		Amber::Ref<Amber::Texture2D> m_TestTexture;

		Amber::Ref<Amber::VertexArray> m_SquareVertexArray;

	public:

		Test2DLayer();

		virtual ~Test2DLayer() = default;

		virtual void OnAttach() override;

		virtual void OnDetach() override;

		virtual void OnUpdate(
			Amber::DeltaTime deltaTime
		) override;

		virtual void OnImGuiRender() override;

		virtual void OnEvent(
			Amber::Event& event
		) override;

	private:

		void CreateSquare();

		bool OnKeyPressed(
			Amber::KeyPressedEvent& keyEvent
		);

		bool OnMouseButtonPressed(
			Amber::MouseButtonPressedEvent& mouseEvent
		);

		void NewScene();

	};

