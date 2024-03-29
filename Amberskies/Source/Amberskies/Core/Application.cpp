
#include "Application.h"

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




#include <backends/imgui_impl_glfw.h>

#include "Amberskies/Core/Log.h"

#include "Amberskies/Input/Input.h"

#include "Amberskies/Renderer/Renderer.h"





namespace Amber
{

	Application* Application::s_Instance =
		nullptr;



	Application::Application()
		
	{

		AMBER_ASSERT(!s_Instance, "Application already exists.");

		s_Instance =
			this;

		m_Window = 
			std::unique_ptr<Window>(
				Window::Create()
			);

		m_Window->SetEventCallback(
			BIND_EVENT_FN(Application::OnEvent)
		);

		m_ImGuiLayer =
			new ImGuiLayer();

		PushOverlay(
			m_ImGuiLayer
		);

	}



	Application::~Application()
	{

		//Empty

	}



	void Application::Run()
	{

		while(m_Running)
		{

			float time =
				(float)ImGui::GetTime();

			DeltaTime deltaTime = 
				time - m_LastFrameTime;

			m_LastFrameTime = time;

			if (Amber::Input::IsKeyPressed(AMBER_KEY_ESCAPE))
			{

				CloseApplication();

				DEV_INFO("The escape key was pressed");

			}

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate(deltaTime);

			m_ImGuiLayer->Begin();

			for (Layer* layer : m_LayerStack)
				layer->OnImGuiRender();

			m_ImGuiLayer->End();

			m_Window->OnUpdate();
				
		}

	}



	void Application::OnEvent(
		Event& e
	)
	{

		EventDispatcher dispatcher(
			e
		);

		dispatcher.Dispatch<WindowCloseEvent>(
			BIND_EVENT_FN(Application::OnWindowClose)
		);

		//AMBER_TRACE("event : {0}", e);

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{

			(*--it)->OnEvent(
				e
			);

			if (e.Handled)
				break;

		}

	}



	void Application::PushLayer(
		Layer* layer
	)
	{

		m_LayerStack.PushLayer(
			layer
		);

		layer->OnAttach();

	}



	void Application::PushOverlay(
		Layer* layer
	)
	{

		m_LayerStack.PushOverLay(
			layer
		);

		layer->OnAttach();

	}



	void Application::CloseApplication()
	{

		m_Running =
			false;
	}



	bool Application::OnWindowClose(
		WindowCloseEvent& e
	)
	{
		m_Running =
			false;

		return true;
	}

}
