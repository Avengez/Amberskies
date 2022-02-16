#pragma once

/**
* ________________________________________________________
* Project Created by Frazor Sharp : 15/02/2022
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
#include "Amberskies/ECS/Components.h"



namespace Amber
{

	class Scene
	{

		// registry m_Registry

	public:

		Scene();

		~Scene();

		void OnUpdate(DeltaTime deltaTime);

	};

}
