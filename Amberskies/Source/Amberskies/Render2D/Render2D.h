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
#include "Amberskies/Render3D/PerspectiveCamera.h"
#include "Amberskies/Render3D/ShaderAPI.h"

#include "Amberskies/Render2D/TextureAPI.h"

namespace Amber
{
	class Render2D
	{

	public:

		static void Initialize();

		static void Shutdown();

		static void BeginScene(
			const PerspectiveCamera& camera
		);

		static void EndScene();

		static void DrawQuad(
			const glm::vec3& position ,
			const float rotationRad ,
			const glm::vec2& size ,
			const glm::vec4& color ,
			const Ref<Texture2D> texture
		);




	};
}
