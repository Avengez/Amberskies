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
#include "Amberskies/Render2D/TextureAPI.h"
#include "Amberskies/Render3D/PerspectiveCamera.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>



namespace Amber
{

	enum class Component
	{
		none = 0,
		UUIDComponent,
		NameComponent,
		ModelMatrixComponent,
		MaterialComponent,

		numberOfComponents
	};

	struct CameraComponent
	{

		PerspectiveCamera Camera;

		bool Primary =
			true;		// think about moving to Scene

		bool FixedAspectRatio =
			false;

		CameraComponent() = default;

		CameraComponent(
			const CameraComponent&
		) = default;

	};
	
	struct UUIDComponent
	{

		UUID m_ID;

		UUIDComponent() = default;

		UUIDComponent(
			const UUIDComponent&
		) = default;

	};

	struct NameComponent
	{

		std::string m_Name;

		NameComponent() = default;

		NameComponent(
			const NameComponent&
		) = default;

		NameComponent(
			const std::string& name
		)	: 
			m_Name(name) {}

	};

	struct ModelMatrixComponent
	{

		glm::vec3 Position = 
		{ 
			0.0f, 
			0.0f, 
			0.0f 
		};

		glm::vec3 Rotation = 
		{ 
			0.0f, 
			0.0f, 
			0.0f 
		};

		glm::vec3 Scale = 
		{ 
			1.0f, 
			1.0f, 
			0.0f 
		};

		ModelMatrixComponent() = default;

		ModelMatrixComponent(
			const ModelMatrixComponent&
		) = default;

		ModelMatrixComponent(
			const glm::vec3& position // where you place the model within the scene
		)	: 
			Position(position) {}

		glm::mat4 GetModelMatrix() const
		{

			glm::mat4 rotation = 
				glm::toMat4(
					glm::quat(  // trying to avoid gimmble lock
						Rotation
					)
			);

			return glm::translate(
				glm::mat4(1.0f), 
				Position
			) * 
				rotation
			  * 
				glm::scale(
					glm::mat4(1.0f), 
					Scale
			);

		}
	};


	// ***** Optional Components ( users choice ) *****


	struct MaterialComponent
	{

		glm::vec4 color =
		{ 1.0f, 1.0f, 1.0f, 1.0f };

		MaterialComponent() = default;

		MaterialComponent(
			const MaterialComponent&
		) = default;

	};

	/*struct MeshComponent
	{*/

		/*MeshComponent() = default;

		MeshComponent(
			const MeshComponent&
		) = default;

		MeshComponent(
			
		) :
			 {}*/

	//};

	//struct SpriteRendererComponent
	//{
	//	glm::vec4 Color{ 1.0f, 1.0f, 1.0f, 1.0f };
	//	Ref<Texture2D> Texture;
	//	float TilingFactor = 1.0f;

	//	SpriteRendererComponent() = default;
	//	SpriteRendererComponent(const SpriteRendererComponent&) = default;
	//	SpriteRendererComponent(const glm::vec4& color)
	//		: Color(color) {}
	//};

	//struct CircleRendererComponent
	//{
	//	glm::vec4 Color{ 1.0f, 1.0f, 1.0f, 1.0f };
	//	float Thickness = 1.0f; // 0->1 (1 = filled)

	//	CircleRendererComponent() = default;
	//	CircleRendererComponent(const CircleRendererComponent&) = default;
	//	CircleRendererComponent(const glm::vec4& color)
	//		: Color(color) {}
	//};

	

	/*class ScriptableEntity;
	struct NativeScriptComponent
	{
		ScriptableEntity* Instance = nullptr;

		ScriptableEntity* (*InstantiateScript)();
		void (*DestroyScript)(NativeScriptComponent*);

		template<typename T>
		void Bind()
		{
			InstantiateScript = []() { return static_cast<ScriptableEntity*>(new T()); };
			DestroyScript = [](NativeScriptComponent* nsc) { delete nsc->Instance; nsc->Instance = nullptr; };
		}
	};*/

	// Physics

	//struct Rigidbody2DComponent
	//{
	//	enum class BodyType { Static = 0, Dynamic, Kinematic };
	//	BodyType Type = BodyType::Static;
	//	bool FixedRotation = false;

	//	// Storage for runtime
	//	void* RuntimeBody = nullptr;

	//	Rigidbody2DComponent() = default;
	//	Rigidbody2DComponent(const Rigidbody2DComponent&) = default;
	//};

	//struct BoxCollider2DComponent
	//{
	//	glm::vec2 Offset = { 0.0f, 0.0f };
	//	glm::vec2 Size = { 0.5f, 0.5f };

	//	// physics material in the future maybe
	//	float Density = 1.0f;
	//	float Friction = 0.5f;
	//	float Restitution = 0.0f;
	//	float RestitutionThreshold = 0.5f;

	//	// Storage for runtime
	//	void* RuntimeFixture = nullptr;

	//	BoxCollider2DComponent() = default;
	//	BoxCollider2DComponent(const BoxCollider2DComponent&) = default;
	//};

}