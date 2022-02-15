
#include "Test2DLayer.h"

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




#include <Platform/OpenGL/OpenGLShader.h>



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

		CreateSquare();

		m_ShaderLibrary.Initialize();

		m_TestTexture =
			Amber::Texture2D::Create(
				"Assets/Textures/Checkerboard.png"
			);

	}



	void Test2DLayer::OnDetach()
	{
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

		Amber::Renderer::BeginScene(m_Camera);

		auto textureShader =
			m_ShaderLibrary.Get(
				"Texture"
			);

		textureShader->Bind();

		u32 slot =
			0;

		m_TestTexture->Bind(slot);

		std::dynamic_pointer_cast<Amber::OpenGLShader>(
			textureShader)->UploadUniformFloat4(
				"u_Color", m_SquareColor
			);

		Amber::Renderer::Submit(
			textureShader,
			m_SquareVertexArray
		); // ModelMatrix default given by Amber Engine

		Amber::Renderer::EndScene();

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



	void Test2DLayer::CreateSquare()
	{

		// *********************************

		m_SquareVertexArray.reset(
			Amber::VertexArray::Create()
		);

		float squareVertices[5 * 4] =
		{
			-0.5f, -0.5f, 0.0f,			// btm left
			 0.0f,  0.0f,				//Texture UV
			 0.5f, -0.5f, 0.0f,			// btm right
			 1.0f,  0.0f,
			 0.5f,  0.5f, 0.0f,			// top right
			 1.0f,  1.0f,
			-0.5f,  0.5f, 0.0f,			// top left
			 0.0f,  1.0f
		};

		Amber::Ref<Amber::VertexBuffer> squareVertexBuffer;

		squareVertexBuffer.reset(
			Amber::VertexBuffer::Create(
				squareVertices,
				sizeof(squareVertices)
			)
		);

		squareVertexBuffer->SetLayout(
			{
				{ Amber::ShaderDataType::Float3, "a_Postion" },
				{ Amber::ShaderDataType::Float2, "a_TextureCoord"}
				//{ Amber::ShaderDataType::Float4, "u_Color"}
			}
		);

		m_SquareVertexArray->AddVertexBuffer(
			squareVertexBuffer
		);

		// ***********************************

		u32 squareIndices[6] =
		{
			0, 1, 2, 2, 3, 0
		};

		Amber::Ref<Amber::IndexBuffer> squareIndexBuffer;

		squareIndexBuffer.reset(
			Amber::IndexBuffer::Create(
				squareIndices,
				sizeof(squareIndices) / sizeof(u32)
			)
		);

		m_SquareVertexArray->SetIndexBuffer(
			squareIndexBuffer
		);

		// *********************************	

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