#pragma once

/**
* ________________________________________________________
* Project Created by Frazor Sharp : 17/01/2022
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

#include "Amberskies/Events/Event.h"



namespace Amber
{

	struct WindowProperties
	{

		std::string Title = "Test";

		unsigned int Width = 100;

		unsigned int Height = 100;

		WindowProperties(
			const std::string& title = "Amber Engine",
			unsigned int width = 1920,
			unsigned int height = 1080
		) : 
			Title(title), Width(width), Height(height) {}

	};



	// Interface only can be used by any OS
	class Window
	{

	public:

		using EventCallbackFn =
			std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;

		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;

		virtual void SetVSync(bool enabled) = 0;

		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		// definition created per platform
		static Window* Create(const WindowProperties& props = WindowProperties());

	};

}