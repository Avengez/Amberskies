
/**
* ________________________________________________________
* Project Created by Frazor Sharp : 16/01/2022
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


#include <Platform/OpenGL/OpenGLShader.h>

#include "Test2DLayer.h"



class ExampleLayer : public Amber::Layer
{

public:

	ExampleLayer() : 
		Layer("Example"),
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
	


		/*
		*  would like to replace with ECS
		*  ie:
		*  auto sqaure = m_CurrentScene->CreateEntity()
		*  square.AddComponent(Component)
		*/
		m_VertexArray =
			Amber::VertexArray::Create();

		float vertices[3 * 7] =
		{
			-0.5f, -0.5f, 0.0f,			// Position 1
			 1.0f,  0.0f, 0.0f, 1.0f,	// Color 1

			 0.5f, -0.5f, 0.0f,
			 0.0f,  1.0f, 0.0f, 1.0f,

			 0.0f,  0.5f, 0.0f,
			 0.0f,  0.0f, 1.0f, 1.0f
		};

		Amber::Ref<Amber::VertexBuffer> vertexBuffer;

		vertexBuffer =
			Amber::VertexBuffer::Create(
				vertices,
				sizeof(vertices)
		);
		

		Amber::BufferLayout layout =
		{

			{ Amber::ShaderDataType::Float3, "a_Postion" },
			{ Amber::ShaderDataType::Float4, "a_Color"}

		};

		vertexBuffer->SetLayout(
			layout
		);

		// must be used after SetLayout 
		m_VertexArray->AddVertexBuffer(
			vertexBuffer
		);

		// ***********************************

		u32 indices[3] =
		{
			0, 1, 2
		};

		Amber::Ref<Amber::IndexBuffer> indexBuffer;

		indexBuffer =
			Amber::IndexBuffer::Create(
				indices,
				sizeof(indices) / sizeof(u32)
		);
		

		m_VertexArray->SetIndexBuffer(
			indexBuffer
		);

		// *********************************

		m_SquareVertexArray =
			Amber::VertexArray::Create();

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

		squareVertexBuffer =
			Amber::VertexBuffer::Create(
				squareVertices,
				sizeof(squareVertices)
		);

		squareVertexBuffer->SetLayout(
			{
				{ Amber::ShaderDataType::Float3, "a_Postion" },
				{ Amber::ShaderDataType::Float2, "a_TextureCoord"}
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

		squareIndexBuffer =
			Amber::IndexBuffer::Create(
				squareIndices,
				sizeof(squareIndices) / sizeof(u32)
		);
		
		m_SquareVertexArray->SetIndexBuffer(
			squareIndexBuffer
		);

		// *********************************	
		
		m_ShaderLibrary.Initialize();

		m_TestTexture =
			Amber::Texture2D::Create(
				"Assets/Textures/Checkerboard.png"
		);

	}



	void OnUpdate(Amber::DeltaTime deltaTime) override
	{

		float dt = 
			deltaTime.GetSeconds();

		m_SimpleTimer +=
			dt;

		if (m_SimpleTimer >= 1)
		{

			DEV_INFO(
				"Delta time : {0}s   {1}ms",
				dt,
				deltaTime.GetMilliseconds()
			);

			m_SimpleTimer = 0.0f;

		}

		// *** Update ***
		m_Camera.OnUpdate(
			deltaTime
		);


		// will be able to currentScene.OnUpdate(deltaTime)
		// *** Render ***
		Amber::RenderCommand::Clear();

		Amber::Renderer::BeginScene(m_Camera);



		glm::mat4 squareModelScale =
			glm::scale(
				glm::mat4(1.0f),
				glm::vec3(0.1f)
			);

		auto flatColorShader = m_ShaderLibrary.Get(
			"FlatColor"
		);

		flatColorShader->Bind();

		

		for (int indexY = -10; indexY < 10; indexY++)
		{

			for (int indexX = -10; indexX < 10; indexX++)
			{
				glm::vec3 position(
					indexX * 0.11,
					indexY * 0.11,
					-0.5f
				);

				glm::mat4 squareModelMatrix =
					glm::translate(
						glm::mat4(1.0f),
						position
					) *
					squareModelScale;

				

				if (indexX % 2 == 0)
				{

					glm::vec4 guiColor =
						glm::vec4(
							m_SquareColor, 
							1.0f
					);

					std::dynamic_pointer_cast<Amber::OpenGLShader>(
						flatColorShader)->UploadUniformFloat4(
							"u_Color", guiColor
						);

				}
				else
				{

					glm::vec4 blueColor(
						0.10f,
						0.15f,
						0.75f,
						1.0f
					);

					std::dynamic_pointer_cast<Amber::OpenGLShader>(
						flatColorShader)->UploadUniformFloat4(
							"u_Color", blueColor
					);
				
				}

				Amber::Renderer::Submit(
					flatColorShader,
					m_SquareVertexArray,
					squareModelMatrix
				);

			}
		
		}


		auto textureShader =
			m_ShaderLibrary.Get(
				"Texture"
		);

		textureShader->Bind();

		u32 slot =
			0;

		m_TestTexture->Bind(slot);

		Amber::Renderer::Submit(
			textureShader,
			m_SquareVertexArray
		); // ModelMatrix default given by Amber Engine



		Amber::Renderer::EndScene();

	}


#ifdef _DEBUG
	virtual void OnImGuiRender() override
	{


		
		if (m_ShowFirstWindow)
		{

			ImGui::Begin(
				"Settings",
				&m_ShowFirstWindow
			);

			ImGui::ColorEdit3(
				"Square Color",
				glm::value_ptr(
					m_SquareColor
				)
			);

			ImGui::End();

		}



	}
#endif


	void OnEvent(
		Amber::Event& event
	)	override
	{

		m_Camera.OnEvent(
			event
		);

		Amber::EventDispatcher dispatcher(
			event
		);

		dispatcher.Dispatch<Amber::KeyPressedEvent>(
			BIND_EVENT_FN(ExampleLayer::OnKeyPressedEvent)
		);

	}



	bool OnKeyPressedEvent(
		Amber::KeyPressedEvent& event
	)
	{

		/* this would give chunky movement as events run once per frame
		*  also takes event from OS so would react to OS key repeat delay.
		*  good for using menu's etc
		* 
		*  eg:
		* 
		// Key Left
		if (event.GetKeyCode() == AMBER_KEY_A)
			m_CameraPosition.x -= m_CameraSpeed;
		*
		*/

		return false; // continues to propergate other layers
	}

private:

	bool m_ShowFirstWindow = true;

	Amber::ShaderLibrary m_ShaderLibrary;

	Amber::Ref<Amber::Shader> m_Shader;

	//Amber::Ref<Amber::Shader> m_FlatColorShader;


	Amber::Ref<Amber::VertexArray> m_VertexArray;

	Amber::Ref<Amber::VertexArray> m_SquareVertexArray;

	Amber::Ref<Amber::Texture2D> m_TestTexture;

	Amber::PerspectiveCamera m_Camera;

	float m_SimpleTimer = 0.0f;

	glm::vec3 m_SquareColor = glm::vec3(1.0f);

};



class Sandbox : public Amber::Application
{

public:

	Sandbox()
	{

		/*PushLayer(
			new ExampleLayer()
		);*/

		PushLayer(
			new Test2DLayer()
		);

	}

	~Sandbox()
	{
		//empty
	}

};



//*******************************
// Main Entry Point for the User
//*******************************
#include "Amberskies/Core/MainEntryPoint.h"

Amber::Application* Amber::CreateApplication()
{

	return new Sandbox();

}
