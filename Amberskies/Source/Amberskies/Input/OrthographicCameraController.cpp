
#include "OrthographicCameraController.h"

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
#include "Amberskies/Input/Input.h"



namespace Amber
{

	OrthographicCameraController::OrthographicCameraController(
		float aspectRatio,
		bool rotation
	) :
		m_AspectRatio(aspectRatio),
		m_Rotate(rotation),
		m_Zoom(1.0f),
		m_Camera(-m_AspectRatio, m_AspectRatio, -m_Zoom, m_Zoom)
	{
	}



	void OrthographicCameraController::OnUpdate(DeltaTime deltaTime)
	{

		float dt =
			deltaTime.GetSeconds();

		// Key Left
		if (Input::IsKeyPressed(AMBER_KEY_A))
			m_CameraPosition.x -= m_CameraSpeed * dt;

		// Key Right
		if (Input::IsKeyPressed(AMBER_KEY_D))
			m_CameraPosition.x += m_CameraSpeed * dt;

		// Key UP
		if (Input::IsKeyPressed(AMBER_KEY_W))
			m_CameraPosition.y += m_CameraSpeed * dt;

		// Key Down
		if (Input::IsKeyPressed(AMBER_KEY_S))
			m_CameraPosition.y -= m_CameraSpeed * dt;

		if (m_Rotate)
		{

			// Rotate Anti-Clockwise
			if (Input::IsKeyPressed(AMBER_KEY_Q))
				m_CameraRotation += m_CameraRotationSpeed * dt;

			// Rotate Clockwise
			if (Input::IsKeyPressed(AMBER_KEY_E))
				m_CameraRotation -= m_CameraRotationSpeed * dt;

			m_Camera.SetRotationZ(
				m_CameraRotation
			);

		}

		m_Camera.SetPosition(
			m_CameraPosition
		);

		m_CameraSpeed =
			m_Zoom;

	}
	
	
	
	void OrthographicCameraController::OnEvent(Event& event)
	{

		EventDispatcher dispatcher(event);

		dispatcher.Dispatch<MouseScrolledEvent>(
			BIND_EVENT_FN(OrthographicCameraController::OnMouseScrolled)
		);

		dispatcher.Dispatch<WindowResizeEvent>(
			BIND_EVENT_FN(OrthographicCameraController::OnWindowResized)
		);

	}
	
	
	
	bool OrthographicCameraController::OnMouseScrolled(MouseScrolledEvent& event)
	{

		m_Zoom -= 
			event.GetYoffset() * 0.1f;

		if (m_Zoom < 0.1f)
			m_Zoom = 0.1f;

		m_Camera.SetProjection(
			-m_AspectRatio * m_Zoom,
			 m_AspectRatio * m_Zoom,
			-m_Zoom, 
			 m_Zoom
		);

		return false;
	}
	
	
	
	bool OrthographicCameraController::OnWindowResized(WindowResizeEvent& event)
	{

		m_AspectRatio =
			(float)event.GetWidth() /
			(float)event.GetHeight();

		m_Camera.SetProjection(
			-m_AspectRatio * m_Zoom,
			 m_AspectRatio * m_Zoom,
			-m_Zoom,
			 m_Zoom
		);

		return false;
	
	}

}
