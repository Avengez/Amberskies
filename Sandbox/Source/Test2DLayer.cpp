
#include "Test2DLayer.h"

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



struct QuadProperties
{

	glm::vec3 position = 
		{ 0.0f, 0.0f, 0.0f };

	glm::vec2 size = 
		{ 1.0f, 1.0f };

	glm::vec4 color = 
		{ 1.0f, 1.0f, 1.0f, 1.0f };

	float rotationRadians = 0.0f;

};

QuadProperties g_Quad1;
QuadProperties g_Quad2;

	Test2DLayer::Test2DLayer()
		:
		Layer("Test2DLayer"),
		m_Camera(45, 1920.0f / 1080.0f, 0.5f, 100.0f)
	{

	}



	void Test2DLayer::OnAttach()
	{

		Amber::Renderer::Initialize();


		// Initialize the first Quad
		g_Quad1.position =
			glm::vec3(
				1.0f,
				1.0f,
				0.0f
		);



		// Initialize the second Quad
		g_Quad2.position =
			glm::vec3(
				1.0f,
				0.0f,
				0.01f
		);

		g_Quad2.color =
			glm::vec4(
				1.0f,
				0.25f,
				0.25f,
				0.5f
		);

		g_Quad2.size =
			{ 1.0f, 2.0f };



		// Initialize the background color
		Amber::RenderCommand::SetClearColor(
			{
			0.05f,
			0.05f,
			0.2f,
			1.0f
			}
		);



		// Initialize the test texture
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

		// Rotate the Quads += anti-clockwise for openGL
		g_Quad1.rotationRadians +=
			glm::radians(
				1.0f
			);

		g_Quad2.rotationRadians +=
			glm::radians(
				-1.0f
			);



		// will be able to move to currentScene.OnUpdate(deltaTime)
		// *** Render ***
		Amber::RenderCommand::Clear();

		Amber::Render2D::BeginScene(m_Camera);

		Amber::Render2D::DrawQuad(
			g_Quad1.position,
			g_Quad1.size,
			g_Quad1.rotationRadians,
			m_TestTexture,
			g_Quad1.color
		);

		Amber::Render2D::DrawQuad(
			g_Quad2.position,
			g_Quad2.size,
			g_Quad2.rotationRadians,
			g_Quad2.color
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
					g_Quad1.color
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
