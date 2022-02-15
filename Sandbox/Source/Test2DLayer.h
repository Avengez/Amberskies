#pragma once

/**
* ________________________________________________________
* Project Created by Frazor Sharp : 15/02/2022
*
* Twitch : Mini Game Engine Programming in C/C++
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

		Amber::Ref<Amber::ShaderLibrary> m_ShaderLibrary;

		//Amber::Ref<Amber::Texture2D> m_TestTexture;

		//Amber::Ref<Amber::VertexArray> m_SquareVertexArray;

		glm::vec4 m_SquareColor = glm::vec4(1.0f);

		bool m_ShowFirstWindow = true;
		
		float m_RotationRad = 0.0f;

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

