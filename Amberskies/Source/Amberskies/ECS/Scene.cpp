
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
		* std::vector<uint32_t> m_EntityRegistry;
		*
		* std::vector<std::vector<int>> m_ComponentRegistry;
		* 
		*/
	

	Scene::Scene(
		u8 id, 
		const std::string& name
	)	:
		m_ID(id),
		m_Name(name)
	{

		// Empty

	}
	
	
	
	Scene::~Scene()
	{

		m_EntityRegistry.clear();

	}



	void Scene::OnUpdate(
		DeltaTime deltaTime)
	{
	}

	Entity* Scene::AddNewEntity(
		const std::string& name)
	{

		u32 id = 
			(u32)m_EntityRegistry.size();

		Entity* entity = new Entity(id, m_ID);

		m_EntityRegistry.push_back(
			entity
		);

		entity->addComponent(
			Component::UUIDComponent
		);

		entity->addComponent(
			Component::NameComponent
		);

		static_cast<NameComponent*>(
			GetComponent(
				entity,
				Component::NameComponent
			)
		)->m_Name = name;

		entity->addComponent(
			Component::ModelMatrixComponent
		);

		return entity;

	}

	void Scene::RemoveEntity(
		Entity entity)
	{
	}

	Entity* Scene::GetEntity(const std::string& name)
	{

		// TODO :
		return nullptr;
	}

	void Scene::AddComponent(
		Entity* entity, 
		Component component)
	{

		entity->addComponent(
			component
		);

	}

	void* Scene::GetComponent(
		Entity* entity, 
		Component component)
	{
		return entity->GetComponent(component);
	}

	void Scene::RemoveComponent(
		Entity entity, 
		void* component)
	{
	}

	void* Scene::View(
		void* component)
	{
		return nullptr;
	}

	bool Scene::EntityExists(
		Entity entity)
	{
		return false;
	}

	bool Scene::ComponentExists(
		Entity entity, 
		void* component)
	{
		return false;
	}

}
