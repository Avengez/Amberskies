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

#include "Amberskies/ECS/ECS.h"


namespace Amber
{
	
	typedef struct {

		i32 entity_id[MAX_ENTITIES] = {UNUSED};

	} Entities;

}
