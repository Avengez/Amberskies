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




#ifdef AMBER_PLATFORM_WINDOWS

#include <Windows.h>

#else

	#error Amber supports windows only

#endif



#ifdef AMBER_DEBUG

	#define AMBER_ENABLE_ASSERTS

#endif



#ifdef AMBER_ENABLE_ASSERTS

	#define DEV_ASSERT(x, ...) { if(!(x)) { DEV_ERROR("Assert Failure: {0}", __VA_ARGS__); __debugbreak(); }}

	#define AMBER_ASSERT(x, ...) { if(!(x)) { AMBER_ERROR("Assert Failure: {0}", __VA_ARGS__); __debugbreak(); }}

#else

	#define DEV_ASSERT(x, ...)

	#define AMBER_ASSERT(x, ...)

#endif



#define BIT(x) (1 << x)

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)



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




#include "Amberskies/Core/Log.h"
#include "Platform/OpenGL/glad.h"



// Typedefs *********************************************

typedef uint8_t		u8;
typedef uint32_t    u32;
typedef uint64_t	u64;
typedef int8_t		i8;
typedef int32_t     i32;
typedef int64_t     i64;

// ******************************************************

namespace Amber
{

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}
