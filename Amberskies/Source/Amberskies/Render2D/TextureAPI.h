#pragma once

/**
* ________________________________________________________
* Project Created by Frazor Sharp : 10/02/2022
*
* Twitch : Mini Game Engine Programming in C/C++
*
* Contact Email : daocamberskies@googlemail.com
* Github		: https://github.com/Avengez/Amberskies.git
* Twitch		: frazorbladezsharp
* Youtube		: Frazor Sharp
*
* ______________________________________________________*/





#include "Common.h"



namespace Amber
{

	class Texture
	{

	public:

		virtual u32 GetWidth() const = 0;

		virtual u32 GetHeight() const = 0;

		virtual void SetData(
			void* data,
			u32 size
		) = 0;

		virtual void Bind(
			u32 slot = 0
		) const = 0;

	};



	class Texture2D : public Texture
	{

	public:

		virtual ~Texture2D() = default;

		static Ref<Texture2D> Create(
			const std::string& filePath
		);

		static Ref<Texture2D> Create(
			u32 width,
			u32 height
		);

	};

}
