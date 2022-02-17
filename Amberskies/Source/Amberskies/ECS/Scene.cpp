
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



	void Scene::OnUpdate(DeltaTime deltaTime)
	{
	}

	i32 Scene::AddEntity(std::string& name)
	{
		i32 generatedID = m_ID;

		m_ID++;

		m_Entities->entity_id[generatedID] = 
			generatedID; // register in list of Entities

		m_Registry[generatedID]->entity_id = 
			generatedID;  // register in list of Components

		// Add base components here (All entities must have these)

		return generatedID;
	}

	

}

