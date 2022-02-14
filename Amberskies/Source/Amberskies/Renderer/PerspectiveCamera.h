#pragma once

/**
* ________________________________________________________
* Project Created by Frazor Sharp : 13/02/2022
*
* Twitch : Simple Server Programming in C/C++
*
* Contact Email : daocamberskies@googlemail.com
* Github		: https://github.com/Avengez/Amberskies.git
* Twitch		: frazorbladezsharp
* Youtube		: Frazor Sharp
*
* ______________________________________________________*/





#include "Common.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>

#include "Amberskies/Core/DeltaTime.h"
#include "Amberskies/Events/Event.h"
#include "Amberskies/Events/ApplicationEvent.h"
#include "Amberskies/Events/MouseEvent.h"


namespace Amber
{

	class PerspectiveCamera
	{

		glm::mat4 m_ViewMatrix;

		glm::mat4 m_Projection;

		glm::vec3 m_Position;

		glm::vec3 m_FocalPoint;

		glm::vec2 m_InitialMousePosition;

		float m_FieldOfView;

		float m_AspectRatio;

		float m_NearClipPlane;

		float m_FarClipPlane;

		float m_Distance;

		float m_ViewportWidth;

		float m_ViewportHeight;

		float m_Pitch;

		float m_Yaw;

	public:

		PerspectiveCamera() = default;

		PerspectiveCamera(
			float fieldOfView,
			float aspectRatio,
			float nearClipPlane,
			float farClipPlane
		);

		~PerspectiveCamera() = default;

		void OnUpdate(
			DeltaTime deltaTime
		);

		void OnEvent(
			Event& onEvent
		);

		void SetProjection(
			float fieldOfView,
			float aspectRatio,
			float nearClipPlane,
			float farClipPlane
		);

		const glm::mat4& GetProjection() const { 
			return m_Projection; 
		}

		inline float GetDistance() const {
			return m_Distance;
		}

		inline void SetDistance(float distance) {
			m_Distance = distance;
		}

		inline void SetViewportSize(
			float width,
			float height) 
		{

			m_ViewportWidth = width;

			m_ViewportHeight = height;

			UpdateProjection();

		}

		const glm::vec3& GetPosition() const {
			return m_Position;
		}

		void SetPosition(const glm::vec3& position)
		{

			m_Position = position;

			UpdateView();

		}


		const glm::mat4& GetViewMatrix() const {
			return m_ViewMatrix;
		}


		glm::vec3 GetUpDirection() const;

		glm::vec3 GetRightDirection() const;

		glm::vec3 GetForwardDirection() const;

		glm::quat GetOrientation() const;

		float GetPitch() const {
			return m_Pitch;
		}

		float GetYaw() const {
			return m_Yaw;
		}

	private:

		void UpdateProjection();

		void UpdateView();

		bool OnMouseScroll(
			MouseScrolledEvent& mouseEvent
		);

		bool OnWindowResized(
			WindowResizeEvent& resizeEvent
		);

		void MousePan(
			const glm::vec2& deltaPan
		);

		void MouseRotate(
			const glm::vec2& deltaRotation
		);

		void MouseZoom(
			float deltaZoom
		);

		glm::vec3 CalculatePosition() const;

		std::pair<float, float> PanSpeed() const;

		float RotationSpeed() const;

		float ZoomSpeed() const;

	};

}

