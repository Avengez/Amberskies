
#include "PerspectiveCamera.h"

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




#include "glm/gtc/matrix_transform.hpp"



namespace Amber
{

	PerspectiveCamera::PerspectiveCamera(
		float left,
		float right,
		float bottom,
		float top
	) :
		m_ProjectionMatrix(glm::ortho(left, right, bottom, top, -1.0f, 1.0f)),
		m_ViewMatrix(1.0f),
		m_Position(0.0f, 0.0f, 0.0f),
		m_Rotation(0.0f, 0.0f, 0.0f)
	{

		RecalculateViewMatrix();

	}



	void PerspectiveCamera::SetProjection(float left, float right, float bottom, float top)
	{

		m_ProjectionMatrix =
			glm::ortho(
				left,
				right,
				bottom,
				top,
				-1.0f,
				1.0f
			);

		RecalculateViewMatrix();

	}



	void PerspectiveCamera::RecalculateViewMatrix()
	{

		glm::mat4 transform =
			glm::translate(
				glm::mat4(1.0f),
				m_Position
			); /**
			glm::rotate(
				glm::mat4(1.0f),
				m_Rotation.x,
				glm::vec3(1.0f, 0.0f, 0.0f)
			) *
			glm::rotate()*/

		m_ViewMatrix =
			glm::inverse(
				transform
			);

		m_ViewProjectionMatrix =	// note for openGL we multiply
			m_ProjectionMatrix *	// matrices in reverse order.
			m_ViewMatrix;

	}

}
