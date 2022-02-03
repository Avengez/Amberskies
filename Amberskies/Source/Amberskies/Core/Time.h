#pragma once

/**
* ________________________________________________________
* Project Created by Frazor Sharp : 27/01/2022
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



namespace Amber
{

	class Time
	{
		 
		float m_Time;	// stored in seconds.

	public:

		Time(
			float time = 0.0f) :
			m_Time(time)
		{}

		operator float() const 
			{ return m_Time; }

		inline float GetSeconds() const 
			{ return m_Time; }

		inline float GetMilliseconds() const 
			{ return m_Time * 1000.0f; }

	};

}