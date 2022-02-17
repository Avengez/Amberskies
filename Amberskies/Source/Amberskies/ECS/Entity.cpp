
#include "Entity.h"

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


#include "Amberskies/ECS/Scene.h"

namespace Amber
{

	Entity::Entity(
		u32 entityHandle,
		u8 sceneID
		)
		:
		m_EntityHandle(entityHandle),
		m_SceneID(sceneID)
	{

		// Empty

	}

	

	bool Entity::addComponent(Component component)
	{
		
		if (component == Component::UUIDComponent)
		{

			UUIDComponent* theComponent = 
				new UUIDComponent();

			m_ComponentRegistry[(int)Component::UUIDComponent].push_back(
				theComponent
			);

		}
		else if (component == Component::NameComponent)
		{

			NameComponent* theComponent =
				new NameComponent();

			m_ComponentRegistry[(int)Component::NameComponent].push_back(
				theComponent
			);

		}
		else if (component == Component::ModelMatrixComponent)
		{

			ModelMatrixComponent* theComponent =
				new ModelMatrixComponent();

			m_ComponentRegistry[(int)Component::ModelMatrixComponent].push_back(				
				theComponent
			);

		}
		else if (component == Component::MaterialComponent)
		{

			MaterialComponent* theComponent =
				new MaterialComponent();

			m_ComponentRegistry[(int)Component::MaterialComponent].push_back(
				theComponent
			);

		}
		else
		{

			return false;

		}
			
		return true;
	
	}



	void* Entity::GetComponent(Component component)
	{

		if (m_ComponentRegistry[(int)component][0] == nullptr)
			AMBER_ASSERT(
				false, 
				"[Entity] Get Component not found"
			);

		return m_ComponentRegistry[(int)component][0];

	}

}
