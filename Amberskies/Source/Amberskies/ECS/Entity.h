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
#include "Amberskies/Core/UUID.h"
#include "Amberskies/ECS/Components.h"
#include "Amberskies/ECS/Scene.h"


namespace Amber
{
	class Entity
	{

		u32 m_EntityHandle = NULL;

		Scene* m_Scene = nullptr;

	public:

		Entity() = default;

		Entity(u32 entityHandle, Scene* scene);

		Entity(const Entity& other) = default;

		//bool addComponent(Component component)

		//bool addOrReplaceComponent(Component component)

		// Components GetComponent()

		//bool RemoveComponent(Component component)

		operator bool() const { 
			return m_EntityHandle != NULL; 
		}

		//operator entity() const { return m_EntityHandle; }

		operator uint32_t() const { 
			return (uint32_t)m_EntityHandle; 
		}

		//UUID GetUUID() { return GetComponent<IDComponent>().ID; }
		
		//const std::string& GetName() { return GetComponent<TagComponent>().Tag; }

		bool operator==(const Entity& other) const 
		{

			return m_EntityHandle == other.m_EntityHandle && 
						m_Scene == other.m_Scene;
		
		}

		bool operator!=(const Entity& other) const
		{
			return !(*this == other);
		}

	};
}
