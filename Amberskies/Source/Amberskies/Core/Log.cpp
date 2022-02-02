
#include "Log.h"

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




namespace Amber
{

	std::shared_ptr<spdlog::logger> Log::s_AmberLogger;

	std::shared_ptr<spdlog::logger> Log::s_DevLogger;

	

	void Log::Initialize()
	{

		// [Time] which Logger: message
		spdlog::set_pattern(
			"%^[%T] %n: %v%$"
		);

		s_AmberLogger =
			spdlog::stdout_color_mt(
				"Amber Engine"
			);

		s_AmberLogger->set_level(
			spdlog::level::trace
		);

		s_DevLogger =
			spdlog::stdout_color_mt(
				"Application"
			);

		s_DevLogger->set_level(
			spdlog::level::trace
		);

	}

}
