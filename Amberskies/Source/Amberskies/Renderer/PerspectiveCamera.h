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



namespace Amber
{

	class PerspectiveCamera
	{

		glm::mat4 m_ProjectionMatrix;

		glm::mat4 m_ViewMatrix;

		glm::mat4 m_ViewProjectionMatrix;

		glm::vec3 m_Position;

		glm::vec3 m_Rotation;

	public:

		PerspectiveCamera() = default;

		PerspectiveCamera(
			float left,
			float right,
			float bottom,
			float top
		);

		void SetProjection(
			float left,
			float right,
			float bottom,
			float top
		);

		const glm::vec3& GetPosition() const {
			return m_Position;
		}

		void SetPosition(const glm::vec3& position)
		{

			m_Position = position;

			RecalculateViewMatrix();

		}

		glm::vec3 GetRotation() const {
			return m_Rotation;
		}

		void SetRotationZ(const glm::vec3 rotation)
		{

			m_Rotation = rotation;

			RecalculateViewMatrix();

		}

		const glm::mat4& GetProjectionMatrix() const {
			return m_ProjectionMatrix;
		}

		const glm::mat4& GetViewMatrix() const {
			return m_ViewMatrix;
		}

		const glm::mat4& GetViewProjectionMatrix() const {
			return m_ViewProjectionMatrix;
		}

	private:

		void RecalculateViewMatrix();

	};

}

