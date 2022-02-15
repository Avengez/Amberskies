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
#include "Amberskies/Core/DeltaTime.h"
#include "Amberskies/Core/UUID.h"
#include "Amberskies/Core/Layer.h"
#include "Amberskies/Core/Log.h"

#include "Amberskies/ECS/Components.h"
#include "Amberskies/ECS/Scene.h"

#include "Amberskies/Gui/ImGuiLayer.h"

#include "Amberskies/Input/Input.h"
#include "Amberskies/Input/KeyCodes.h"
#include "Amberskies/Input/MouseCodes.h"
#include "Amberskies/Input/OrthographicCameraController.h"



//*******************************
//		Render2D
//*******************************
#include "Amberskies/Render2D/OrthographicCamera.h"
#include "Amberskies/Render2D/TextureAPI.h"
 

//*******************************
//		Render3D
//*******************************
#include "Amberskies/Render3D/Buffer.h"

#include "Amberskies/Render3D/PerspectiveCamera.h"
#include "Amberskies/Render3D/RenderCommand.h"
#include "Amberskies/Render3D/Renderer.h"
#include "Amberskies/Render3D/ShaderAPI.h"

#include "Amberskies/Render3D/VertexArray.h"





