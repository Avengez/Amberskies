#pragma once


/**
* ________________________________________________________
* Project Created by Frazor Sharp : 16/01/2022
*
* Twitch : Mini Game Engine Programming in C/C++
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

#include <algorithm>
#include <array>
#include <fstream>
#include <functional>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include <glm/gtc/type_ptr.hpp>




#include "Amberskies/Core/Application.h"
#include "Amberskies/Core/DeltaTime.h"
#include "Amberskies/Core/UUID.h"
#include "Amberskies/Core/Layer.h"
#include "Amberskies/Core/Log.h"

#include "Amberskies/ECS/ECS.h"

#include "Amberskies/Events/Event.h"
#include "Amberskies/Events/ApplicationEvent.h"
#include "Amberskies/Events/KeyEvent.h"
#include "Amberskies/Events/MouseEvent.h"

#ifdef _DEBUG
#include <imgui.h>
#include "Amberskies/Gui/ImGuiLayer.h"
#endif

#include "Amberskies/Input/Input.h"
#include "Amberskies/Input/KeyCodes.h"
#include "Amberskies/Input/MouseCodes.h"
#include "Amberskies/Input/OrthographicCameraController.h"



//*******************************
//		Render2D
//*******************************
#include "Amberskies/Render2D/OrthographicCamera.h"
#include "Amberskies/Render2D/Render2D.h"
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





