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



#ifdef AMBER_PLATFORM_WINDOWS


extern Amber::Application* Amber::CreateApplication();

int main(int argc, char** argv)
{

	Amber::Log::Initialize();

	printf(
		"\nWelcome to Amberskies.\n\n"
	);

	auto app = 
		Amber::CreateApplication();

	app->Run();

	delete app;

}

#endif
