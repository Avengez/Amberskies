#pragma once

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





#include "Common.h"

#include <glm/glm.hpp>



namespace Amber
{

	class OrthographicCamera
	{

		glm::mat4 m_ProjectionMatrix;

		glm::mat4 m_ViewMatrix;

		glm::mat4 m_ViewProjectionMatrix;

		glm::vec3 m_Position;

		float m_RotationZ = 0.0f;

	public:

		OrthographicCamera() = default;

		OrthographicCamera(
			float left,
			float right,
			float bottom,
			float top
		);

		const glm::vec3& GetPosition() const { 
			return m_Position; }

		void SetPosition(const glm::vec3& position) {
			m_Position = position; RecalculateViewMatrix();
		}

		float GetRotation() const { return m_RotationZ; }

		void SetRotationZ(const float rotationZ) { 
			m_RotationZ = rotationZ; RecalculateViewMatrix(); }

		const glm::mat4& GetProjectionMatrix() const { 
			return m_ProjectionMatrix; }

		const glm::mat4& GetViewMatrix() const { 
			return m_ViewMatrix; }

		const glm::mat4& GetViewProjectionMatrix() const { 
			return m_ViewProjectionMatrix; }

	private:

		void RecalculateViewMatrix();

	};

}
