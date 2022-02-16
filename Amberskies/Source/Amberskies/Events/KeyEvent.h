#pragma once


/**
* ________________________________________________________
* Project Created by Frazor Sharp : 16/01/2022
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

#include "Amberskies/Events/Event.h"



namespace Amber
{

	class KeyEvent : public Event
	{

	public:

		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:

		KeyEvent(int keycode)
			: m_KeyCode(keycode) {}

		int m_KeyCode;

	};



	class KeyPressedEvent : public KeyEvent
	{
		int m_RepeatCount;

	public:

		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{

			std::stringstream result;

			result
				<< "KeyPressedEvent: "
				<< m_KeyCode
				<< " ("
				<< m_RepeatCount
				<< " repeats)";

			return result.str();

		}

		EVENT_CLASS_TYPE(KeyPressed)

	};



	class KeyReleasedEvent : public KeyEvent
	{

	public:

		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override
		{

			std::stringstream result;

			result
				<< "KeyReleasedEvent: "
				<< m_KeyCode;

			return result.str();

		}

		EVENT_CLASS_TYPE(KeyReleased)

	};



	class KeyTypedEvent : public KeyEvent
	{
		int m_RepeatCount = 0;

	public:

		KeyTypedEvent(int keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override
		{

			std::stringstream result;

			result
				<< "KeyTypedEvent: "
				<< m_KeyCode;

			return result.str();

		}

		EVENT_CLASS_TYPE(KeyTyped)

	};
}
