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

#include "Amberskies/Core/Layer.h"



namespace Amber
{

	class LayerStack
	{

		std::vector<Layer*> m_Layers;

		unsigned int m_LayerInsertIndex = 0;

	public:

		LayerStack();
		
		~LayerStack();

		void PushLayer(
			Layer* layer
		);

		void PushOverLay(
			Layer* overlay
		);

		void PopLayer(
			Layer* layer
		);

		void PopOverlay(
			Layer* overlay
		);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }

		std::vector<Layer*>::iterator end() { return m_Layers.end(); }

	};

}