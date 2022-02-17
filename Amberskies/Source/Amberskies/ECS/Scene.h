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

#include "Amberskies/ECS/Entity.h"
#include "Amberskies/ECS/Components.h"



namespace Amber
{

	class Scene
	{

		u8 m_ID;

		std::string m_Name;

		std::vector<Entity*> m_EntityRegistry;

	public:

		Scene(
			u8 id,
			const std::string& name
		);

		~Scene();

		void OnUpdate(
			DeltaTime deltaTime
		);

		Entity* AddNewEntity(
			const std::string& name
		);

		void RemoveEntity(
			Entity entity
		);

		Entity* GetEntity(
			const std::string& name
		);

		void AddComponent(
			Entity* entity,
			Component component
		);

		void* GetComponent(
			Entity* entity,
			Component component
		);

		void RemoveComponent(
			Entity entity,
			void* component
		);

		void* View(
			void* component
		);

	private:

		bool EntityExists(
			Entity entity
		);

		bool ComponentExists(
			Entity entity,
			void* component
		);

	};

}
