
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

		/* ideas based on github entt
		*  struct TransformComponent
		* {
		*		Data
		* };
		* 
		*  u32 entity = m_Registry.create
		* 
		*  
		*  m_Registry.emplace(targetEntity, Component)
		*		.remove
		*		.clear
		*		.get
		*		.group (componentType, componentType) use in same way as view
		*		.connect to ie: OnComponentConstruct()
		*	auto view = 	.view(componentType)
		* 
		*	for (auto entity : view)
		*   {
		*      do stuff
		*   }
		* 
		*/
	}
	
	
	
	Scene::~Scene()
	{

		// Empty

	}



	void Scene::OnUpdate(DeltaTime deltaTime)
	{
	}

}
