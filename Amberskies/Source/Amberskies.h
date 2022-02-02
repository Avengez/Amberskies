#pragma once


/**
* ________________________________________________________
* Project Created by Frazor Sharp : 16/01/2022
*
* Twitch : Simple Server Programming in C/C++
*
* Contact Email : daocamberskies@googlemail.com
* Github		: https://github.com/Avengez/Amberskies.git
* Twitch		: frazorbladezsharp
* Youtube		: Frazor Sharp
*
* ______________________________________________________*/



/**
* To add a git sub module use in the Solution Dir
* Open a Command Promt and type :
* 
* git submodule add URL Destination
* 
* ie :
*	git submodule add https://github.com/glfw/glfw AmberEngine/Vendor/GLFW
* 
*/


// main include file for the user of the Engine.



#include "Amberskies/Core/Application.h"
#include "Amberskies/Core/Input.h"
#include "Amberskies/Core/KeyCodes.h"
#include "Amberskies/Core/Layer.h"
#include "Amberskies/Core/Log.h"
#include "Amberskies/Core/MouseCodes.h"

#include "Amberskies/Gui/ImGuiLayer.h"

//*******************************
//		Renderer
//*******************************
#include "Amberskies/Renderer/Buffer.h"
#include "Amberskies/Renderer/OrthographicCamera.h"
#include "Amberskies/Renderer/RenderCommand.h"
#include "Amberskies/Renderer/Renderer.h"
#include "Amberskies/Renderer/Shader.h"
#include "Amberskies/Renderer/VertexArray.h"

//*******************************
// Main Entry Point for the User
//*******************************
#include "Amberskies/Core/MainEntryPoint.h"

