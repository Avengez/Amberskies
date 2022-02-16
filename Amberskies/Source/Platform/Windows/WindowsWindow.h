#pragma once

/**
* ________________________________________________________
* Project Created by Frazor Sharp : 17/01/2022
*
* Twitch : Mini Game Engine Programming in C/C++
*
* Contact Email : daocamberskies@googlemail.com
* Github		: https://github.com/Avengez/Amberskies.git
* Twitch		: frazorbladezsharp
* Youtube		: Frazor Sharp
*
* ______________________________________________________*/

 



#include "Common.h"

#include "Amberskies/Core/Window.h"

#include "Platform/OpenGL/OpenGLContext.h"



namespace Amber
{

	class WindowsWindow : public Window
	{

		GLFWwindow* m_Window;

		GFXContext* m_gfxContext;

		struct WindowData
		{
			
			std::string Title = "Default";
			
			unsigned int Width = 100;
			unsigned int Height = 100;
			
			bool VSync = true;

			EventCallbackFn EventCallback;

		};

		WindowData m_Data;

	public:

		WindowsWindow(const WindowProperties& props);

		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }

		inline unsigned int GetHeight() const override { return m_Data.Height; }

		//Attributes
		inline void SetEventCallback(const EventCallbackFn& callback) override
			{ m_Data.EventCallback = callback; }
		
		void SetVSync(bool enabled) override;
		
		bool IsVSync() const override;

		inline virtual void* GetNativeWindow() const { return m_Window; }
	
	private:
		
		virtual void Initialize(const WindowProperties& props);
		
		virtual void Shutdown();
	};

}