
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
#include <imgui.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <Platform/OpenGL/OpenGLShader.h>



class ExampleLayer : public Amber::Layer
{

public:

	ExampleLayer() : 
		Layer("Example"),
		m_Camera(-2.0f, 2.0f, -1.08f / 1.92f - 0.5f , 1.08f / 1.92f + 0.5f),
		m_CameraPosition({ 0.0f, 0.0f, -1.0 })
	{

		Amber::RenderCommand::SetClearColor(
			{
			0.05f,
			0.05f,
			0.5f,
			1.0f
			}
		);
	
		m_VertexArray.reset(
			Amber::VertexArray::Create()
		);

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

		Amber::Ref<Amber::IndexBuffer> indexBuffer;

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

		std::string vertexSource =
			R"(
				#version 330 core
				
				layout(location = 0) in vec3 a_Position;
				layout(location = 1) in vec4 a_Color;

				uniform mat4 u_ViewProjection;
				uniform mat4 u_ModelMatrix;

				out vec4 v_Color;

				void main()
				{
					v_Color = a_Color;
					gl_Position = u_ViewProjection * u_ModelMatrix * vec4(a_Position, 1.0f);
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
			Amber::Shader::Create(
				vertexSource,
				fragmentSource
			)
		);

		std::string flatColorVertexSource =
			R"(
				#version 330 core
				
				layout(location = 0) in vec3 a_Position;
				
				uniform mat4 u_ViewProjection;
				uniform mat4 u_ModelMatrix;

				out vec3 v_Position;

				void main()
				{
					v_Position = a_Position;
					gl_Position = u_ViewProjection * u_ModelMatrix * vec4(a_Position, 1.0f);
				}
		)";

		std::string flatColorFragmentSource =
			R"(
				#version 330 core
				
				layout(location = 0) out vec4 f_Color;

				in vec3 v_Position;

				uniform vec4 u_Color;

				void main()
				{
					f_Color = u_Color;
				}
		)";

		m_FlatColorShader.reset(
			Amber::Shader::Create(
				flatColorVertexSource,
				flatColorFragmentSource
			)
		);



		std::string textureVertexSource =
			R"(
				#version 330 core
				
				layout(location = 0) in vec3 a_Position;
				layout(location = 1) in vec2 a_TextureCoord;
				
				uniform mat4 u_ViewProjection;
				uniform mat4 u_ModelMatrix;

				out vec2 v_TextureCoord;

				void main()
				{
					v_TextureCoord = a_TextureCoord;
					gl_Position = u_ViewProjection * u_ModelMatrix * vec4(a_Position, 1.0f);
				}
		)";

		std::string textureFragmentSource =
			R"(
				#version 330 core
				
				layout(location = 0) out vec4 f_Color;

				in vec2 v_TextureCoord;

				uniform sampler2D u_Texture;

				

				void main()
				{
					f_Color = texture(u_Texture, v_TextureCoord);
				}
		)";

		m_TextureShader.reset(
			Amber::Shader::Create(
				textureVertexSource,
				textureFragmentSource
			)
		);


		int slot =
			0;

		m_TestTexture =
			Amber::Texture2D::Create(
				"Assets/Textures/Checkerboard.png"
		);

		std::dynamic_pointer_cast<Amber::OpenGLShader>(
			m_TextureShader
			)->Bind();

		std::dynamic_pointer_cast<Amber::OpenGLShader>(
			m_TextureShader)->UploadUniformInt(
				"u_Texture", slot
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

		

		Amber::RenderCommand::Clear();

		Amber::Renderer::BeginScene(m_Camera);

		glm::mat4 squareModelScale =
			glm::scale(
				glm::mat4(1.0f),
				glm::vec3(0.1f)
			);

		glm::vec4 blueColor(
			0.10f, 
			0.15f, 
			0.75f, 
			1.0f);

		std::dynamic_pointer_cast<Amber::OpenGLShader>(
			m_FlatColorShader
		)->Bind();

		for (int indexY = -10; indexY < 10; indexY++)
		{

			for (int indexX = -10; indexX < 10; indexX++)
			{
				glm::vec3 position(
					indexX * 0.11,
					indexY * 0.11,
					0.0f
				);

				glm::mat4 squareModelMatrix =
					glm::translate(
						glm::mat4(1.0f),
						position
					) *
					squareModelScale;

				glm::vec4 aColor =
					glm::vec4(m_SquareColor, 0.1f);

				if (indexX % 2 == 0)
				{

					std::dynamic_pointer_cast<Amber::OpenGLShader>(
						m_FlatColorShader)->UploadUniformFloat4(
							"u_Color", aColor
						);

				}
				else
					std::dynamic_pointer_cast<Amber::OpenGLShader>(
						m_FlatColorShader)->UploadUniformFloat4(
						"u_Color", blueColor
					);

				Amber::Renderer::Submit(
					m_FlatColorShader,
					m_SquareVertexArray,
					squareModelMatrix
				);

			}
		
		}

		std::dynamic_pointer_cast<Amber::OpenGLShader>(
			m_TextureShader
			)->Bind();

		u32 slot =
			0;

		m_TestTexture->Bind(slot);

		Amber::Renderer::Submit(
			m_TextureShader,
			m_SquareVertexArray
		);

		Amber::Renderer::EndScene();

	}



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

	Amber::Ref<Amber::Shader> m_Shader;

	Amber::Ref<Amber::Shader> m_FlatColorShader;

	Amber::Ref<Amber::Shader> m_TextureShader;

	Amber::Ref<Amber::VertexArray> m_VertexArray;

	Amber::Ref<Amber::VertexArray> m_SquareVertexArray;

	Amber::Ref<Amber::Texture2D> m_TestTexture;

	Amber::OrthographicCamera m_Camera;

	glm::vec3 m_CameraPosition;

	float m_CameraSpeed = 3.0f;				// ie 3 units per second

	float m_CameraRotation = 0.0f;

	float m_CameraRotationSpeed = 90.0f;	// 90 degrees per second

	float m_SimpleTimer = 0.0f;

	glm::vec3 m_SquareColor = glm::vec3(1.0f);

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
