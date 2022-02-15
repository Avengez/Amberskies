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




#ifdef _DEBUG



#include "Common.h"

#include "Amberskies/Core/Layer.h"

#include "Amberskies/Events/ApplicationEvent.h"
#include "Amberskies/Events/MouseEvent.h"
#include "Amberskies/Events/KeyEvent.h"



namespace Amber
{

	//float m_Time = 0.0f;

	class ImGuiLayer : public Layer
	{

	public:

		ImGuiLayer();

		~ImGuiLayer();

		virtual void OnAttach() override;

		virtual void OnDetach() override;

		virtual void OnImGuiRender() override;

		void Begin();

		void End();

	};

}
#endif // DEBUG