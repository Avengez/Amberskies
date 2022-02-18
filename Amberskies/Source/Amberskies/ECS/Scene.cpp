
#include "Scene.h"

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




namespace Amber
{

	Scene::Scene()
	{
		
	}
	
	
	
	Scene::~Scene()
	{

		

	}



	void Scene::OnUpdate(
		DeltaTime deltaTime)
	{
	}

	i32 Scene::AddEntity(
		const std::string& name)
	{
		i32 generatedID = m_ID;

		m_ID++;

		m_Entities->entity_id[generatedID] = 
			generatedID; // register in list of Entities

		m_Registry[generatedID].entity_id = 
			generatedID;  // register in list of Components

		// Add base components here (All entities must have these)
		AddBaseComponents(
			generatedID,
			name
		);

		return generatedID;
	}



	void Scene::RemoveEntity(i32 entityID)
	{

		m_Entities->entity_id[entityID] =
			UNUSED;

		for (void* component : m_Registry[entityID].component)
		{

			if(component != nullptr)
				delete component;

		}

		m_Registry[entityID].entity_id =
			UNUSED;

	}



	void Scene::AddBaseComponents(
		i32 entityID, 
		const std::string& name)
	{


		m_Registry[entityID].component[COMP_UUID] =
			new UUIDComponent();

	}

	

	

}

