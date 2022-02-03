#pragma once


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


#include "Common.h"

#include "Amberskies/Core/Window.h"
#include "Amberskies/Core/DeltaTime.h"
#include "Amberskies/Core/LayerStack.h"

#include "Amberskies/Events/Event.h"
#include "Amberskies/Events/ApplicationEvent.h"

#include "Amberskies/Gui/ImGuiLayer.h"



namespace Amber
{

	class Application
	{

		static Application* s_Instance;

		bool m_Running =
			true;

		LayerStack m_LayerStack;

		std::unique_ptr<Window> m_Window;

		ImGuiLayer* m_ImGuiLayer;

		float m_LastFrameTime = 0.0f;

	public:

		Application();

		virtual ~Application();

		void Run();

		void OnEvent(
			Event& e
		);

		void PushLayer(
			Layer* layer
		);

		void PushOverlay(
			Layer* layer
		);

		void CloseApplication();

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

	private:

		bool OnWindowClose(
			WindowCloseEvent& e
		);

	};



	// defined in the users application.
	Application* CreateApplication();

}
