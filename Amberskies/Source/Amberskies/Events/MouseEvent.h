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

	class MouseMovedEvent : public Event
	{

		float m_MouseX;

		float m_MouseY;

	public:

		MouseMovedEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y) {}

		inline float GetX() const { return m_MouseX; }

		inline float GetY() const { return m_MouseY; }

		std::string ToString() const override
		{

			std::stringstream result;

			result
				<< "MouseMovedEvent: "
				<< m_MouseX
				<< ", "
				<< m_MouseY;

			return result.str();

		}

		EVENT_CLASS_TYPE(MouseMoved)

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	};



	class MouseScrolledEvent : public Event
	{

		float m_Xoffset;

		float m_Yoffset;

	public:

		MouseScrolledEvent(const float xoffset, const float yoffset)
			: m_Xoffset(xoffset), m_Yoffset(yoffset) {}

		float GetXoffset() const { return m_Xoffset; }

		float GetYoffset() const { return m_Yoffset; }

		std::string ToString() const override
		{

			std::stringstream result;

			result
				<< "MouseScrolledEvent: "
				<< m_Xoffset
				<< ", "
				<< m_Yoffset;

			return result.str();

		}

		EVENT_CLASS_TYPE(MouseScrolled)

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	};



	class MouseButtonEvent : public Event
	{

	public:

		int GetMouseButtone() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton)

	protected:

		int m_Button;

		MouseButtonEvent(const int button)
			: m_Button(button) {}

	};



	class MouseButtonPressedEvent : public MouseButtonEvent
	{

	public:

		MouseButtonPressedEvent(const int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{

			std::stringstream result;

			result
				<< "MouseButtonPressedEvent: " 
				<< m_Button;

			return result.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)

	};



	class MouseButtonReleasedEvent : public MouseButtonEvent
	{

	public:
		
		MouseButtonReleasedEvent(const int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{

			std::stringstream result;

			result 
				<< "MouseButtonReleasedEvent: " 
				<< m_Button;

			return result.str();

		}

		EVENT_CLASS_TYPE(MouseButtonReleased)

	};

}
