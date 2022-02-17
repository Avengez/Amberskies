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
#include "Amberskies/ECS/Components.h"

#include "Amberskies/Core/DeltaTime.h"




namespace Amber
{

	class Scene
	{

		

		typedef struct Object{

			i32 entity_id = UNUSED;
			void* component[64];

		}Object;

		// registry m_Registry
		Ref<Object> m_Registry[MAX_ENTITIES];

		Ref<Entities> m_Entities;

		i32 m_ID = 0;


	public:

		Scene();

		~Scene();

		void OnUpdate(DeltaTime deltaTime);

		i32 AddEntity(std::string& name);
		void RemoveEntity();

		void* EntityLookupComponent(
			i32 entityID,
			i32 component)
		{
			return m_Registry[entityID]->component[component];
		}

	};

	

	/* exapmle useage
	
	Position* player_position = (Position*)EntityLookupComponent(
        64,
        COMP_POSITION
    );
	
	*/

	/* example add component
	
	    //////////////////////// Position Component //////////////////////////
void Object_Add_Position(
    i32 object_id,
    u32 room) {


        Position *object_position;

        object_position = (Position *) malloc(
            sizeof(Position)
        );

        object_position->object_id = object_id;          // set values for the object position.

        Point_3D placement = Map_Random_Point_In_Room(
            room
        );

        object_position->position[0] = (float) placement.x;                   // initialize all to effective zero
        object_position->position[1] = 0.5f;
        object_position->position[2] = (float) placement.z;
        object_position->rotationX = 0.0f;
        object_position->rotationY = -45.0f;
        object_position->rotationZ = 0.0f;
        object_position->scale = 1.0f;

        position_component[object->object_id].object_id = object_id;    // keep track of all position components
        object[object_id].component[COMP_POSITION] = object_position;   // add position component to object
    }
	*/
}

