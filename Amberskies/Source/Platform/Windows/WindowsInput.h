#pragma once

/**
* ________________________________________________________
* Project Created by Frazor Sharp : 18/01/2022
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
#include "Amberskies/Input/Input.h"



namespace Amber
{

	class WindowsInput : public Input
	{

	protected:

		virtual bool IsKeyPressedImpl(
			int keycode
		) override;

		virtual bool IsMouseButtonPressedImpl(
			int button
		) override;

		virtual std::pair<float, float> GetMousePositionImpl() override;

		virtual float GetMouseXImpl() override;

		virtual float GetMouseYImpl() override;
	};

}