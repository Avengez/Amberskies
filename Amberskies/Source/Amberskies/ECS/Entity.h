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

class Scene;

namespace Amber
{
	class Entity
	{

		u32 m_EntityHandle = 0;

		u8 m_SceneID;

		std::vector<std::vector<void*>> m_ComponentRegistry;

	public:

		Entity(
			u32 entityHandle, 
			u8 sceneID
		);

		Entity(const Entity& other) = default;

		bool addComponent(Component component);

		//bool addOrReplaceComponent(Component component)

		void* GetComponent(Component component);

		//bool RemoveComponent(Component component)

		operator bool() const { 
			return m_EntityHandle != NULL; 
		}

		//operator entity() const { return m_EntityHandle; }

		operator u32() const { 
			return (u32)m_EntityHandle; 
		}

		//UUID GetUUID() { return GetComponent<IDComponent>().ID; }
		
		//const std::string& GetName() { return GetComponent<TagComponent>().Tag; }

		bool operator==(const Entity& other) const 
		{

			return m_EntityHandle == other.m_EntityHandle &&
				m_SceneID == other.m_SceneID;
		
		}

		bool operator!=(const Entity& other) const
		{
			return !(*this == other);
		}

	};

}
