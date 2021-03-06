#include "mEngine/Graphic/Core/Texture.hpp"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_log.h>
#include <iostream>

using std::cerr;
using std::string;

Texture::Texture():
    _texture(nullptr, SDL_DestroyTexture)
{
	
}

Texture::Texture(const Texture& texture):
	_texture(nullptr, SDL_DestroyTexture)
{
    if(texture._texture != nullptr)
        _texture = texture._texture;
}

Texture::~Texture()
{
    Clear();
}

void Texture::LoadFromBMP(string path, SDL_Renderer* renderHandle)
{
    Clear();
	
	SDL_Surface *surface = SDL_LoadBMP(path.c_str());
	if(surface == nullptr)
	{
		string error = string("SDL_LoadBMP error: ") + SDL_GetError();
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, error.c_str());
        throw std::exception();
	}
	
	_texture = MakeSharedTexture(SDL_CreateTextureFromSurface(renderHandle, surface));
	SDL_FreeSurface(surface);
    if(_texture == nullptr)
	{
		string error = string("SDL_CreateTextureFromSurface error: ") + SDL_GetError();
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, error.c_str());
        throw std::exception();
	}
}

void Texture::LoadFromPNG(std::string path, SDL_Renderer* renderHandle)
{
	int initSDLimage = IMG_Init(IMG_INIT_PNG);
	if((initSDLimage & IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		string error = string("IMG_Init error: ") + SDL_GetError();
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, error.c_str());
        throw std::exception();
	}

    Clear();
	
	auto surface = IMG_Load(path.c_str());
	if(surface == nullptr)
	{
		string error = string("IMG_Load PNG error: ") + SDL_GetError();
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, error.c_str());
        throw std::exception();
	}
	
	_texture = MakeSharedTexture(SDL_CreateTextureFromSurface(renderHandle, surface));
	SDL_FreeSurface(surface);
	if(_texture == nullptr)
	{
		string error = string("SDL_CreateTextureFromSurface PNG error: ") + SDL_GetError();
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, error.c_str());
        throw std::exception();
	}

    IMG_Quit();
}

SDL_Texture* Texture::getHandle() const
{
    return (isInitted()? _texture.get(): nullptr);
}

Texture& Texture::operator=(const Texture& right)
{
	if(this == &right)
	{
		return *this;
	}
	
    _texture.reset();
	_texture = right._texture;

	return *this;
}

Texture::SharedTexture Texture::MakeSharedTexture(SDL_Texture* texture)
{
	return SharedTexture(texture, SDL_DestroyTexture);
}

void Texture::Clear()
{
    if(_texture != nullptr)
    {
        _texture.reset();
        _texture = nullptr;
    }
}

bool Texture::isInitted() const
{
    return (_texture != nullptr? true: false);
}
