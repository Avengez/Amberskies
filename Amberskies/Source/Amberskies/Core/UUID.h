#pragma once

/**
* ________________________________________________________
* Project Created by Frazor Sharp : 14/02/2022
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
#include <xhash>



namespace Amber
{

	class UUID
	{

		uint64_t m_UUID;

	public:

		UUID();

		UUID(uint64_t uuid);

		UUID(const UUID& other);

		operator uint64_t () { 
			return m_UUID; 
		}

		operator uint64_t() const {
			return m_UUID;
		}

	};

}



namespace std
{

	template<>
	struct hash<Amber::UUID>
	{

		std::size_t operator()(const Amber::UUID& uuid) const
		{

			return hash<uint64_t>()((uint64_t)uuid);

		}

	};

}