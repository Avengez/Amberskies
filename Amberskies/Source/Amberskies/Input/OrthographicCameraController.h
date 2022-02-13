#pragma once

/**
* ________________________________________________________
* Project Created by Frazor Sharp : 11/02/2022
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
#include "Amberskies/Render2D/OrthographicCamera.h"
#include "Amberskies/Core/DeltaTime.h"
#include "Amberskies/Events/ApplicationEvent.h"
#include "Amberskies/Events/MouseEvent.h"


namespace Amber
{

	class OrthographicCameraController
	{

		float m_AspectRatio;

		bool m_Rotate;

		float m_Zoom;

		OrthographicCamera m_Camera;

		glm::vec3 m_CameraPosition = { 0.0f, 0.0f, 0.0f };

		float m_CameraRotation = 0.0f;

		float m_CameraSpeed = 1.0f;

		float m_CameraRotationSpeed = 90.0f;

	public:

		OrthographicCameraController(
			float aspectRatio,
			bool rotation = false
		);

		~OrthographicCameraController() = default;

		void OnUpdate(
			DeltaTime deltaTime
		);

		void OnEvent(
			Event& event
		);

		OrthographicCamera& GetCamera() {
			return m_Camera; }

		const OrthographicCamera& GetCamera() const {
			return m_Camera;
		}

	private:

		bool OnMouseScrolled(
			MouseScrolledEvent& event
		);

		bool OnWindowResized(
			WindowResizeEvent& event
		);

	};

}
