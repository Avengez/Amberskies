
#include "Test2DLayer.h"

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




	Test2DLayer::Test2DLayer()
		:
		Layer("Test2DLayer"),
		m_Camera(45, 1920.0f / 1080.0f, 0.5f, 100.0f)
	{

	}



	void Test2DLayer::OnAttach()
	{

		Amber::Renderer::Initialize();

		m_SquareColor =
			glm::vec4(
				0.0f,
				0.0f,
				1.0f,
				1.0f
		);

		Amber::RenderCommand::SetClearColor(
			{
			0.05f,
			0.05f,
			0.2f,
			1.0f
			}
		);

		m_TestTexture =
			Amber::Texture2D::Create(
				"Assets/Textures/Checkerboard.png"
			);

	}



	void Test2DLayer::OnDetach()
	{

		Amber::Render2D::Shutdown();

	}



	void Test2DLayer::OnUpdate(
		Amber::DeltaTime deltaTime)
	{

		// *** Update ***
		m_Camera.OnUpdate(
			deltaTime
		);


		// will be able to currentScene.OnUpdate(deltaTime)
		// *** Render ***
		Amber::RenderCommand::Clear();

		Amber::Render2D::BeginScene(m_Camera);

		glm::vec3 position(
			1.0f,
			1.0f,
			0.0f
		);

		glm::vec2 size(
			1.0f
		);

		Amber::Render2D::DrawQuad(
			position,
			size,
			m_RotationRad,
			m_TestTexture,
			m_SquareColor
		);

		m_RotationRad +=
			glm::radians(
				1.0f
			);

		glm::vec3 thePosition(
			1.0f, 
			0.0f, 
			0.01f
		);

		glm::vec4 theColor(
			1.0f, 
			0.25f, 
			0.25f, 
			0.5f
		);

		Amber::Render2D::DrawQuad(
			thePosition,
			{ 1.0f, 2.0f },
			-m_RotationRad,
			theColor
		);

		Amber::Render2D::EndScene();

	}


#ifdef _DEBUG
	void Test2DLayer::OnImGuiRender()
	{

		if (m_ShowFirstWindow)
		{

			ImGui::Begin(
				"Settings",
				&m_ShowFirstWindow
			);

			ImGui::ColorEdit4(
				"Square Color",
				glm::value_ptr(
					m_SquareColor
				)
			);

			ImGui::End();

		}

	}
#endif // DEBUG



	void Test2DLayer::OnEvent(
		Amber::Event& event)
	{

		m_Camera.OnEvent(
			event
		);

		Amber::EventDispatcher dispatcher(
			event
		);

		dispatcher.Dispatch<Amber::KeyPressedEvent>(
			BIND_EVENT_FN(Test2DLayer::OnKeyPressed)
			);

		dispatcher.Dispatch<Amber::MouseButtonPressedEvent>(
			BIND_EVENT_FN(Test2DLayer::OnMouseButtonPressed)
			);

	}



	bool Test2DLayer::OnKeyPressed(
		Amber::KeyPressedEvent& keyEvent)
	{
		return false;
	}



	bool Test2DLayer::OnMouseButtonPressed(
		Amber::MouseButtonPressedEvent& mouseEvent)
	{
		return false;
	}



	void Test2DLayer::NewScene()
	{

	}
