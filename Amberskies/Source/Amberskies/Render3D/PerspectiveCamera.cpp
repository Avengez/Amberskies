
#include "PerspectiveCamera.h"

/**
* ________________________________________________________
* Project Created by Frazor Sharp : 13/02/2022
*
* Twitch : Mini Game Engine Programming in C/C++
*
* Contact Email : daocamberskies@googlemail.com
* Github		: https://github.com/Avengez/Amberskies.git
* Twitch		: frazorbladezsharp
* Youtube		: Frazor Sharp
*
* ______________________________________________________*/




#include "Amberskies/Input/Input.h"
#include "Amberskies/Input/KeyCodes.h"
#include "Amberskies/Input/MouseCodes.h"



namespace Amber
{

	PerspectiveCamera::PerspectiveCamera(
		float fieldOfView,
		float aspectRatio,
		float nearClipPlane,
		float farClipPlane
	) :
		m_ViewMatrix(1.0f),
		m_Projection(1.0f),
		m_Position(0.0f, 0.0f, -4.0f),
		m_FocalPoint(0.0f, 0.0f, 0.0f),
		m_InitialMousePosition(0.0f, 0.0f),
		m_FieldOfView(fieldOfView),
		m_AspectRatio(aspectRatio),
		m_NearClipPlane(nearClipPlane),
		m_FarClipPlane(farClipPlane),
		m_Distance(4.0f),
		m_ViewportWidth(1920.0f),
		m_ViewportHeight(1080.0f),
		m_Pitch(0.0f),
		m_Yaw(0.0f)
	{

		UpdateProjection();

		UpdateView();

	}



	void PerspectiveCamera::OnUpdate(
		DeltaTime deltaTime)
	{
		
		if (Input::IsKeyPressed(AMBER_KEY_LEFT_ALT))
		{
			const glm::vec2& mouse
				{ Input::GetMouseX(), 
				  Input::GetMouseY() };

			glm::vec2 delta =
				(mouse - m_InitialMousePosition) *  0.003f;

			m_InitialMousePosition = 
				mouse;

			if (Input::IsMouseButtonPressed(AMBER_MOUSE_BUTTON_MIDDLE))
				MousePan(delta);
			else if (Input::IsMouseButtonPressed(AMBER_MOUSE_BUTTON_LEFT))
				MouseRotate(delta);
			else if (Input::IsMouseButtonPressed(AMBER_MOUSE_BUTTON_RIGHT))
				MouseZoom(delta.y);
		}

		UpdateView();

	}



	void PerspectiveCamera::OnEvent(
		Event& onEvent)
	{
		
		EventDispatcher dispatcher(
			onEvent
		);

		dispatcher.Dispatch<MouseScrolledEvent>(
			BIND_EVENT_FN(
				PerspectiveCamera::OnMouseScroll
			)
		);

		dispatcher.Dispatch<WindowResizeEvent>(
			BIND_EVENT_FN(
				PerspectiveCamera::OnWindowResized
			)
		);

	}



	void PerspectiveCamera::SetProjection(
		float fieldOfView,
		float aspectRatio,
		float nearClipPlane,
		float farClipPlane)
	{

		m_FieldOfView =
			fieldOfView;

		m_AspectRatio =
			aspectRatio;

		m_NearClipPlane =
			nearClipPlane;

		m_FarClipPlane =
			farClipPlane;

		UpdateProjection();

	}



	glm::vec3 PerspectiveCamera::GetUpDirection() const
	{
		
		return glm::rotate(
			GetOrientation(), 
			glm::vec3(
				0.0f, 
				1.0f, 
				0.0f
			)
		);

	}



	glm::vec3 PerspectiveCamera::GetRightDirection() const
	{
		
		return glm::rotate(
			GetOrientation(), 
			glm::vec3(
				1.0f, 
				0.0f, 
				0.0f
			)
		);

	}



	glm::vec3 PerspectiveCamera::GetForwardDirection() const
	{
		return glm::rotate(
			GetOrientation(),
			glm::vec3(
				 0.0f,
				 0.0f,
				-1.0
			)
		);
	}



	glm::quat PerspectiveCamera::GetOrientation() const
	{

		return  glm::quat(
			glm::vec3(
				-m_Pitch, 
				-m_Yaw, 
				0.0f
			)
		);

	}



	void PerspectiveCamera::UpdateProjection()
	{

		m_AspectRatio = 
			m_ViewportWidth / m_ViewportHeight;

		m_Projection = 
			glm::perspective(
				m_FieldOfView, 
				m_AspectRatio, 
				m_NearClipPlane, 
				m_FarClipPlane
		);

	}



	void PerspectiveCamera::UpdateView()
	{

		// Lock camera's rotation ???

		m_Position = 
			CalculatePosition();

		glm::quat orientation =
			GetOrientation();

		m_ViewMatrix =
			glm::translate(
				glm::mat4(1.0f),
				m_Position
			) *
			glm::toMat4(
				orientation
		);

		m_ViewMatrix =
			glm::inverse(
				m_ViewMatrix
		);

	}



	bool PerspectiveCamera::OnMouseScroll(
		MouseScrolledEvent& mouseEvent)
	{

		float delta = 
			mouseEvent.GetYoffset() * 0.05f;
		
		MouseZoom(delta);
		
		UpdateView();
		
		return false;
		
	}

	bool PerspectiveCamera::OnWindowResized(
		WindowResizeEvent& resizeEvent)
	{
		
		SetViewportSize(
			(float)resizeEvent.GetWidth(),
			(float)resizeEvent.GetHeight()
		);
		m_AspectRatio =
			(float)resizeEvent.GetWidth() /
			(float)resizeEvent.GetHeight();

		return false;
	}




	void PerspectiveCamera::MousePan(const glm::vec2& deltaPan)
	{

		auto [xSpeed, ySpeed] = 
			PanSpeed();
		
		m_FocalPoint += 
			-GetRightDirection() * deltaPan.x * xSpeed * m_Distance;
		
		m_FocalPoint += 
			GetUpDirection() * deltaPan.y * ySpeed * m_Distance;

	}



	void PerspectiveCamera::MouseRotate(const glm::vec2& deltaRotation)
	{

		float yawSign = 
			GetUpDirection().y < 0 ? -1.0f : 1.0f;
		
		m_Yaw += 
			yawSign * deltaRotation.x * RotationSpeed();
		
		m_Pitch += 
			deltaRotation.y * RotationSpeed();

	}



	void PerspectiveCamera::MouseZoom(float deltaZoom)
	{

		m_Distance -= 
			deltaZoom * ZoomSpeed();
		
		if (m_Distance < 1.0f)
		{

			m_FocalPoint += GetForwardDirection();
			
			m_Distance = 1.0f;
		
		}

	}



	glm::vec3 PerspectiveCamera::CalculatePosition() const
	{
		
		return m_FocalPoint -
			GetForwardDirection() *
			m_Distance;
	
	}

	

	std::pair<float, float> PerspectiveCamera::PanSpeed() const
	{

		float x = 
			std::min(
				m_ViewportWidth / 1000.0f,
				2.4f
		);
		
		float xFactor = 
			0.0366f * (x * x) - 0.1778f * x + 0.3021f;

		float y = 
			std::min(
				m_ViewportHeight / 1000.0f, 
				2.4f
		);

		float yFactor = 
			0.0366f * (y * y) - 0.1778f * y + 0.3021f;

		return { xFactor, yFactor };

	}



	float PerspectiveCamera::RotationSpeed() const
	{
		return 0.8f;
	}



	float PerspectiveCamera::ZoomSpeed() const
	{
		
		float distance = 
			m_Distance * 0.25f;
		
		distance = 
			std::max(
				distance, 
				0.0f
		);

		float speed = 
			distance * distance * 2.5f; 

		speed = 
			std::min(
				speed, 
				100.0f
		); 
		
		return speed;

	}

}
