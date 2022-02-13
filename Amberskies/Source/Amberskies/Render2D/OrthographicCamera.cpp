
#include "OrthographicCamera.h"

/**
* ________________________________________________________
* Project Created by Frazor Sharp : 20/01/2022
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

	OrthographicCamera::OrthographicCamera(
		float left, 
		float right, 
		float bottom, 
		float top
	) :
		m_ProjectionMatrix(glm::ortho(left, right, bottom, top, -1.0f, 1.0f)),
		m_ViewMatrix(1.0f),
		m_Position(0.0f, 0.0f, 0.0f)
	{

		RecalculateViewMatrix();

	}



	void OrthographicCamera::SetProjection(float left, float right, float bottom, float top)
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



	void OrthographicCamera::RecalculateViewMatrix()
	{

		glm::mat4 transform = 
			glm::translate(
				glm::mat4(1.0f),
				m_Position
			) *
			glm::rotate(
				glm::mat4(1.0f),
				m_RotationZ,
				glm::vec3(0, 0, 1)
		);
		
		m_ViewMatrix =
			glm::inverse(
				transform
		);

		m_ViewProjectionMatrix =	// note for openGL we multiply
			m_ProjectionMatrix *	// matrices in reverse order.
			m_ViewMatrix;

	}

}
