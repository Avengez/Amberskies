
#include "RenderCommand.h"

/**
* ________________________________________________________
* Project Created by Frazor Sharp : 20/01/2022
*
* Twitch : Mini Game Engine Programming in C/C++
*
* Contact Email : daocamberskies@googlemail.com
* Github		: https://github.com/Avengez/Amberskies.git
* Twitch		: frazorbladezsharp
* Youtube		: Frazor Sharp
*
* ______________________________________________________*/




#include "Platform/OpenGL/OpenGLRendererAPI.h"



namespace Amber
{

	RendererAPI* RenderCommand::s_RendererAPI =
		new OpenGLRendererAPI;

}