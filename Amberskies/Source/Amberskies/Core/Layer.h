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

#include "Amberskies/Core/DeltaTime.h"

#include "Amberskies/Events/Event.h"




namespace Amber
{

	class Layer
	{

	public:

		Layer(
			const std::string& name = "Layer"
		);

		virtual ~Layer();

		virtual void OnAttach() {}
		
		virtual void OnDetach() {}

		virtual void OnUpdate(DeltaTime deltaTime) {}

#ifdef _DEBUG
		virtual void OnImGuiRender() {}
#endif // DEBUG

		virtual void OnEvent(
			Event& event
		) {}

		inline const std::string& GetName() const { return m_DebugName; }

	protected:

		std::string m_DebugName;

	};

}
