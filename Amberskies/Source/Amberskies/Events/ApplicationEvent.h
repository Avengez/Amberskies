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
#include "Event.h"



namespace Amber
{

	class WindowResizeEvent : public Event
	{

		unsigned int m_Width;

		unsigned int m_Height;

	public:

		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height) {}

		unsigned int GetWidth() const { return m_Width; }
		
		unsigned int GetHeight() const { return m_Height; }

		std::string ToString() const override
		{

			std::stringstream result;

			result 
				<< "WindowResizeEvent: " 
				<< m_Width 
				<< ", " 
				<< m_Height;

			return result.str();
		}
		
		EVENT_CLASS_TYPE(WindowResize)
		
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	};



	class WindowCloseEvent : public Event
	{

	public:

		WindowCloseEvent() = default;

		EVENT_CLASS_TYPE(WindowClose)

		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	};



	class AppTickEvent : public Event
	{

	public:

		AppTickEvent() = default;

		EVENT_CLASS_TYPE(AppTick)

		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	};



	class AppUpdateEvent : public Event
	{

	public:

		AppUpdateEvent() = default;

		EVENT_CLASS_TYPE(AppUpdate)
		
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	};

	class AppRenderEvent : public Event
	{

	public:

		AppRenderEvent() = default;

		EVENT_CLASS_TYPE(AppRender)
		
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	};

}
