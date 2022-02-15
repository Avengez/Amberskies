
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

		Amber::RenderCommand::SetClearColor(
			{
			0.05f,
			0.05f,
			0.2f,
			1.0f
			}
		);

	}



	void Test2DLayer::OnAttach()
	{

		Amber::Render2D::Initialize();

		m_TestTexture =
			Amber::Texture2D::Create(
				"Assets/Textures/Checkerboard.png"
			);

		m_SquareColor =
			glm::vec4(
				0.10f,
				0.15f,
				0.30f,
				1.0f
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



		// *** Render ***
		Amber::Render2D::BeginScene(m_Camera);

		/*auto textureShader =
			m_ShaderLibrary.Get(
				"Texture"
			);

		textureShader->Bind();

		u32 slot =
			0;

		m_TestTexture->Bind(slot);*/

		/**/

		glm::vec3 position(
			0.0f,
			0.0f,
			0.0f
		);

		glm::vec2 size(
			10.0f
		);

		m_RotationRad +=
			glm::radians(
				1.0f
			);

		Amber::Render2D::DrawQuad(
			position,
			m_RotationRad,
			size,
			m_SquareColor,
			m_TestTexture
		);

		/*Amber::Render2D::DrawQuad(
			{ 0.5f, 0.0f, 0.01f },
			-m_RotationRad,
			{ 0.5f, 2.0f },
			{ 0.5f, 0.2f, 0.05f, 0.5f}
		);*/

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
