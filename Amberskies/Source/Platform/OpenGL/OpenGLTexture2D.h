#pragma once

/**
* ________________________________________________________
* Project Created by Frazor Sharp : 10/02/2022
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
#include <Amberskies/Renderer/TextureAPI.h>



namespace Amber
{

	class OpenGLTexture2D : public Texture2D
	{

		std::string m_FilePath;

		GLuint m_Width;

		GLuint m_Height;

		GLuint m_RendererID;

	public:

		OpenGLTexture2D(
			const std::string& filePath
		);

		virtual ~OpenGLTexture2D() override;

		virtual u32 GetWidth() const override {
			return m_Width;
		}

		virtual u32 GetHeight() const override {
			return m_Height;
		}

		virtual void Bind(
			u32 slot = 0
		) const override;

	};

}
