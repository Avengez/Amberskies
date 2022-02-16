
/**
* ________________________________________________________
* Project Created by Frazor Sharp : 03/02/2022
*
* Twitch : Simple Server Programming in C/C++
*
* Contact Email : daocamberskies@googlemail.com
* Github		: https://github.com/Avengez/Amberskies.git
* Twitch		: frazorbladezsharp
* Youtube		: Frazor Sharp
*
* ______________________________________________________*/






#include <Amberskies.h>

#include "Core.h"




class Sand_Rogue : public Amber::Application
{

public:

	Sand_Rogue()
	{
		
		PushLayer(
			new CoreLayer()
		);

	}

	~Sand_Rogue()
	{
		//empty
	}

};



//*******************************
// Main Entry Point for the User
//*******************************
#include "Amberskies/Core/MainEntryPoint.h"

Amber::Application* Amber::CreateApplication()
{

	return new Sand_Rogue();

}


