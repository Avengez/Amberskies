
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




#include "Amberskies/Render2D/Render2D.h"
#include "Amberskies/Render3D/RenderCommand.h"



namespace Amber
{

	Scene::Scene()
		:
		m_Camera(45, 1920.0f / 1080.0f, 0.5f, 100.0f)
	{

		for (i32 generatedID = 0; generatedID < MAX_ENTITIES; generatedID++)
				m_Entities->entity_id[generatedID] = UNUSED;
				
	}
	
	
	
	Scene::~Scene()
	{

		// Empty

	}



	void Scene::OnUpdate(
		DeltaTime deltaTime)
	{

		// *** Update ***
		m_Camera.OnUpdate(
			deltaTime
		);

		// Render
		Render2D::BeginScene(m_Camera);

		RenderCommand::Clear();

		for (i32 entity = 0; entity < MAX_ENTITIES; entity++)
		{

			if (m_Entities->entity_id[entity] != UNUSED)
			{

				auto transform =
					(TransformComponent*)EntityLookupComponent(
						entity,
						COMP_TRANSFORM
					);

				auto material =
					(MaterialComponent*)EntityLookupComponent(
						entity,
						COMP_MATERIAL
					);

				Render2D::DrawQuad(
					transform->Translation,
					{ transform->Scale.x, transform->Scale.y },
					transform->RotationRadians.z,
					material->Texture,
					material->Color
				);

			}

		}

		Render2D::EndScene();

	}

	void Scene::OnEvent(
		Event& event)
	{

		m_Camera.OnEvent(
			event
		);

	}



	i32 Scene::AddEntity(
		const std::string& name)
	{

		i32 generatedID = 0;

		for (generatedID; generatedID < MAX_ENTITIES; generatedID++)
		{
			if (m_Entities->entity_id[generatedID] == UNUSED)
				break;
		}

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



	void Scene::AddExampleCommponent(
		i32 entityID)
	{

		m_Registry[entityID].component[COMP_EXAMPLE] =
			new ExampleComponent();

	}

	void Scene::RemoveExampleComponent(i32 entityID)
	{

		// use only for raw pointer
		void* component = 
			m_Registry[entityID].component[COMP_EXAMPLE];

		// use only for raw pointer
		if (component != nullptr)
			delete component;

		// allways remove from registry
		m_Registry[entityID].component[COMP_EXAMPLE] = nullptr;

	}

	void Scene::AddMaterialCommponent(
		i32 entityID, 
		glm::vec4 color, 
		Ref<Texture2D> texture)
	{

		m_Registry[entityID].component[COMP_MATERIAL] =
			new MaterialComponent();

		auto material = (MaterialComponent*)EntityLookupComponent(
			entityID,
			Amber::COMP_MATERIAL
		);

		material->Color = 
			color;

		material->Texture =
			texture;

	}

	void Scene::RemoveMaterialComponent(
		i32 entityID)
	{

		m_Registry[entityID].component[COMP_MATERIAL] = 
			nullptr;

	}

	



	void Scene::AddBaseComponents(
		i32 entityID, 
		const std::string& name)
	{

		m_Registry[entityID].component[COMP_UUID] =
			new UUIDComponent();

		m_Registry[entityID].component[COMP_NAME] =
			new NameComponent(name);

		m_Registry[entityID].component[COMP_TRANSFORM] =
			new TransformComponent();

	}

}

