#pragma once

/**
* ________________________________________________________
* Project Created by Frazor Sharp : 19/01/2022
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

#include "Amberskies/Renderer/RenderCommand.h"
#include "Amberskies/Renderer/OrthographicCamera.h"
#include "Amberskies/Renderer/Shader.h"



namespace Amber
{
	
	class Renderer
	{

		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static SceneData* m_SceneData;


	public:

		static void BeginScene(
			OrthographicCamera& camera
		);

		static void EndScene();

		static void Submit(
			const std::shared_ptr<Shader>& shader,
			const std::shared_ptr<VertexArray>& vertexArray
		);

		inline static RendererAPI::API GetAPI() { 
			return RendererAPI::GetAPI(); }
		
	};

}
