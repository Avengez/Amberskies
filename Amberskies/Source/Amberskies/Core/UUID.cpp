
#include "UUID.h"

/**
* ________________________________________________________
* Project Created by Frazor Sharp : 14/02/2022
*
* Twitch : Mini Game Engine Programming in C/C++
*
* Contact Email : daocamberskies@googlemail.com
* Github		: https://github.com/Avengez/Amberskies.git
* Twitch		: frazorbladezsharp
* Youtube		: Frazor Sharp
*
* ______________________________________________________*/




#include <random>


//static std::unordered_map<Amber::UUID, std::string> m_Map;


namespace Amber
{

	static std::random_device s_RandomeDevice;

	static std::mt19937_64 s_Engine(
		s_RandomeDevice()
	);

	static std::uniform_int_distribution<uint64_t> s_UniformDistribution;



	UUID::UUID()
		: m_UUID(s_UniformDistribution(s_Engine))
	{

		// Empty

	}



	UUID::UUID(
		uint64_t uuid
	) :
		m_UUID(uuid)
	{

		// Empty

	}



	UUID::UUID(
		const UUID& other
	)	: 
		m_UUID(other.m_UUID)
	{

		// Empty

	}

}