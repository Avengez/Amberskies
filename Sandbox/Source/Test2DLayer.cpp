
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




	Test2DLayer::Test2DLayer()
		:
		Layer("Test2DLayer"),
		m_MainScene(new Amber::Scene())
	{

		// Empty

	}



	void Test2DLayer::OnAttach()
	{

		Amber::Renderer::Initialize();

		// Initialize the background color
		Amber::RenderCommand::SetClearColor(
			{
			0.05f,
			0.05f,
			0.2f,
			1.0f
			}
		);


		// Initialize the first Quad
		i32 quad1 =
			m_MainScene->AddEntity(
				"Quad1"
		);

		auto transformcomp = (Amber::TransformComponent*)m_MainScene->EntityLookupComponent(
			quad1,
			Amber::COMP_TRANSFORM
		);

		transformcomp->Translation =
			glm::vec3(
				1.0f,
				1.0f,
				0.0f
		);



		// Initialize the second Quad
		i32 quad2 =
			m_MainScene->AddEntity(
				"Quad2"
		);

		auto transformQ2 = (Amber::TransformComponent*)m_MainScene->EntityLookupComponent(
			quad2,
			Amber::COMP_TRANSFORM
		);

		transformQ2->Translation =
			glm::vec3(
				1.0f,
				0.0f,
				0.01f
		);

		transformQ2->Scale =
			{ 1.0f, 2.0f, 0.0f };



		// Initialize the test texture
		m_TestTexture =
			Amber::Texture2D::Create(
				"Assets/Textures/TestTexture.png"
		);



		// Initialize Materials
		m_MainScene->AddMaterialCommponent(
			0,
			glm::vec4(1.0f), // allways set to white if solid texture
			m_TestTexture
		);

		m_MainScene->AddMaterialCommponent(
			1,
			glm::vec4(
				1.0f,
				0.25f,
				0.25f,
				0.5f   // 0.5 Alpha = 50% see through
			),
			nullptr	   // no texture = color only
		);

	}



	void Test2DLayer::OnDetach()
	{

		Amber::Render2D::Shutdown();

		delete m_MainScene;

	}



	void Test2DLayer::OnUpdate(
		Amber::DeltaTime deltaTime)
	{

		

		// Rotate the Quads += anti-clockwise for openGL
		//Entity* quad1 = m_MainScene->


		EntityRotationSystem();

	

		
		

		m_MainScene->OnUpdate(
			deltaTime
		);

	}


#ifdef _DEBUG
	void Test2DLayer::OnImGuiRender()
	{

		if (m_ShowFirstWindow)
		{

			auto materialQuad1 =
				(Amber::MaterialComponent*)m_MainScene->EntityLookupComponent(
					0,
					Amber::COMP_MATERIAL
				);


			ImGui::Begin(
				"Settings",
				&m_ShowFirstWindow
			);

			ImGui::ColorEdit4(
				"Square Color",
				glm::value_ptr(
					materialQuad1->Color
				)
			);

			ImGui::End();

		}

	}
#endif // DEBUG



	void Test2DLayer::OnEvent(
		Amber::Event& e)
	{

		m_MainScene->OnEvent(
			e
		);

		Amber::EventDispatcher dispatcher(
			e
		);

		dispatcher.Dispatch<Amber::KeyPressedEvent>(
			BIND_EVENT_FN(Test2DLayer::OnKeyPressed)
			);

		dispatcher.Dispatch<Amber::MouseButtonPressedEvent>(
			BIND_EVENT_FN(Test2DLayer::OnMouseButtonPressed)
			);

	}



	void Test2DLayer::EntityRotationSystem()
	{

		auto transformQuad1 =
			(Amber::TransformComponent*)m_MainScene->EntityLookupComponent(
				0,
				Amber::COMP_TRANSFORM
			);

		auto transformQuad2 =
			(Amber::TransformComponent*)m_MainScene->EntityLookupComponent(
				1,
				Amber::COMP_TRANSFORM
			);

		transformQuad1->RotationRadians.z +=
			glm::radians(
				1.0f
			);

		transformQuad2->RotationRadians.z +=
			glm::radians(
				-1.0f
			);

	}

	bool Test2DLayer::OnKeyPressed(
		Amber::KeyPressedEvent& keyEvent)
	{

		// Empty

		return false;

	}



	bool Test2DLayer::OnMouseButtonPressed(
		Amber::MouseButtonPressedEvent& mouseEvent)
	{

		// Empty

		return false;
	
	}



	void Test2DLayer::NewScene()
	{

		// Empty

	}
