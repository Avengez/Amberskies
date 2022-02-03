
/**
* ________________________________________________________
* Project Created by Frazor Sharp : 16/01/2022
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
#include "imgui.h"



class ExampleLayer : public Amber::Layer
{

public:

	ExampleLayer() : 
		Layer("Example"),
		m_Camera(-1.0f, 1.0f, -1080.0f / 1920.0f - 0.05f, 1080.0f / 1920.0f + 0.05f),
		m_CameraPosition(0.0f)
	{
	
		m_VertexArray.reset(
			Amber::VertexArray::Create()
		);

		float vertices[3 * 7] =
		{
			-0.2f, -0.2f, 0.0f,			// Position 1
			 1.0f,  0.0f, 0.0f, 1.0f,	// Color 1

			 0.2f, -0.2f, 0.0f,
			 0.0f,  1.0f, 0.0f, 1.0f,

			 0.0f,  0.2f, 0.0f,
			 0.0f,  0.0f, 1.0f, 1.0f
		};

		std::shared_ptr<Amber::VertexBuffer> vertexBuffer;

		vertexBuffer.reset(
			Amber::VertexBuffer::Create(
				vertices,
				sizeof(vertices)
			)
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

		std::shared_ptr<Amber::IndexBuffer> indexBuffer;

		indexBuffer.reset(
			Amber::IndexBuffer::Create(
				indices,
				sizeof(indices) / sizeof(u32)
			)
		);

		m_VertexArray->SetIndexBuffer(
			indexBuffer
		);

		// *********************************

		m_SquareVertexArray.reset(
			Amber::VertexArray::Create()
		);

		float squareVertices[3 * 4] =
		{
			-0.3f, -0.3f, 0.0f,			// Position 1
			 0.3f, -0.3f, 0.0f,
			 0.3f,  0.3f, 0.0f,
			-0.3f,  0.3f, 0.0f
		};

		std::shared_ptr<Amber::VertexBuffer> squareVertexBuffer;

		squareVertexBuffer.reset(
			Amber::VertexBuffer::Create(
				squareVertices,
				sizeof(squareVertices)
			)
		);

		squareVertexBuffer->SetLayout(
			{
				{ Amber::ShaderDataType::Float3, "a_Postion" }
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

		std::shared_ptr<Amber::IndexBuffer> squareIndexBuffer;

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

		std::string vertexSource =
			R"(
				#version 330 core
				
				layout(location = 0) in vec3 a_Position;
				layout(location = 1) in vec4 a_Color;

				uniform mat4 u_ViewProjection;

				out vec4 v_Color;

				void main()
				{
					v_Color = a_Color;
					gl_Position = u_ViewProjection * vec4(a_Position, 1.0f);
				}
		)";

		std::string fragmentSource =
			R"(
				#version 330 core
				
				layout(location = 0) out vec4 f_Color;

				in vec4 v_Color;

				void main()
				{
					f_Color = v_Color;
				}
		)";

		m_Shader.reset(
			new Amber::Shader(
				vertexSource,
				fragmentSource
			)
		);

		std::string blueVertexSource =
			R"(
				#version 330 core
				
				layout(location = 0) in vec3 a_Position;
				
				uniform mat4 u_ViewProjection;

				out vec3 v_Position;

				void main()
				{
					v_Position = a_Position;
					gl_Position = u_ViewProjection * vec4(a_Position, 1.0f);
				}
		)";

		std::string blueFragmentSource =
			R"(
				#version 330 core
				
				layout(location = 0) out vec4 f_Color;

				in vec3 v_Position;

				void main()
				{
					f_Color = vec4(0.1f, 0.15f, 0.75f, 1.0f);
				}
		)";

		m_BlueShader.reset(
			new Amber::Shader(
				blueVertexSource,
				blueFragmentSource
			)
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

		// This needs Delta Time
		// Key Left
		if (Amber::Input::IsKeyPressed(AMBER_KEY_A))
			m_CameraPosition.x -= m_CameraSpeed * dt;

		// Key Right
		if (Amber::Input::IsKeyPressed(AMBER_KEY_D))
			m_CameraPosition.x += m_CameraSpeed * dt;

		// Key UP
		if (Amber::Input::IsKeyPressed(AMBER_KEY_W))
			m_CameraPosition.y += m_CameraSpeed * dt;

		// Key Down
		if (Amber::Input::IsKeyPressed(AMBER_KEY_S))
			m_CameraPosition.y -= m_CameraSpeed * dt;

		// Rotate Anti-Clockwise
		if (Amber::Input::IsKeyPressed(AMBER_KEY_Q))
			m_CameraRotation += m_CameraRotationSpeed * dt;

		// Rotate Clockwise
		if (Amber::Input::IsKeyPressed(AMBER_KEY_E))
			m_CameraRotation -= m_CameraRotationSpeed * dt;

		m_Camera.SetPosition(
			m_CameraPosition
		);

		m_Camera.SetRotationZ(
			m_CameraRotation
		);

		Amber::RenderCommand::SetClearColor(
			{
			0.05f,
			0.05f,
			0.5f,
			1.0f
			}
		);

		Amber::RenderCommand::Clear();

		Amber::Renderer::BeginScene(m_Camera);

		Amber::Renderer::Submit(
			m_Camera.GetViewProjectionMatrix(),
			m_BlueShader,
			m_SquareVertexArray
		);

		Amber::Renderer::Submit(
			m_Camera.GetViewProjectionMatrix(),
			m_Shader,
			m_VertexArray
		);

		Amber::Renderer::EndScene();

	}



	virtual void OnImGuiRender() override
	{
		
		if (m_ShowFirstWindow)
		{

			/*
			ImGui::ShowDemoWindow(
				&show
			);*/


			ImGui::Begin(
				"First Window",
				&m_ShowFirstWindow
			);

			ImGui::Text(
				"Hello from another window!"
			);

			ImGui::End();

		}

	}



	void OnEvent(
		Amber::Event& event
	)	override
	{

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

	std::shared_ptr<Amber::Shader> m_Shader;

	std::shared_ptr<Amber::Shader> m_BlueShader;

	std::shared_ptr<Amber::VertexArray> m_VertexArray;

	std::shared_ptr<Amber::VertexArray> m_SquareVertexArray;

	Amber::OrthographicCamera m_Camera;

	glm::vec3 m_CameraPosition;

	float m_CameraSpeed = 3.0f;				// ie 3 units per second

	float m_CameraRotation = 0.0f;

	float m_CameraRotationSpeed = 180.0f;	// 180 degrees per second

	float m_SimpleTimer = 0.0f;

};



class Sandbox : public Amber::Application
{

public:

	Sandbox()
	{
		PushLayer(
			new ExampleLayer()
		);

	}

	~Sandbox()
	{
		//empty
	}

};



Amber::Application* Amber::CreateApplication()
{

	return new Sandbox();

}
