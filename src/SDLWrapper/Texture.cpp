#include "SDLWrapper/Texture.hpp"
#include <SDL2/SDL_image.h>
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
	{
		_texture = texture._texture;
	}
}


Texture::~Texture()
{
	_texture.reset();
}

void Texture::LoadFromBMP(string path, SDL_Renderer* renderHandle)
{
	if(_texture != nullptr)
		_texture.reset();
	
	SDL_Surface *surface = SDL_LoadBMP(path.c_str());
	if(surface == nullptr)
	{
		string error = string("SDL_LoadBMP error: ") + SDL_GetError();
		cerr << error << "\n";
        throw std::exception();
	}
	
	_texture = MakeSharedTexture(SDL_CreateTextureFromSurface(renderHandle, surface));
	SDL_FreeSurface(surface);
    if(_texture == nullptr)
	{
		string error = string("SDL_CreateTextureFromSurface error: ") + SDL_GetError();
		cerr << error << "\n";
        throw std::exception();
	}
}

void Texture::LoadFromPNG(std::string path, SDL_Renderer* renderHandle)
{
	int initSDLimage = IMG_Init(IMG_INIT_PNG);
	if((initSDLimage & IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		string error = string("IMG_Init error: ") + SDL_GetError();
		cerr << error << "\n";
        throw std::exception();
	}
	
	auto surface = IMG_Load(path.c_str());
	if(surface == nullptr)
	{
		string error = string("IMG_Load PNG error: ") + SDL_GetError();
		cerr << error << "\n";
        throw std::exception();
	}
	
	_texture = MakeSharedTexture(SDL_CreateTextureFromSurface(renderHandle, surface));
	SDL_FreeSurface(surface);
	if(_texture == nullptr)
	{
		string error = string("SDL_CreateTextureFromSurface PNG error: ") + SDL_GetError();
		cerr << error << "\n";
        throw std::exception();
	}
	
	IMG_Quit();
}

SDL_Texture* Texture::getTextureHandle() const
{
	return _texture.get();
}

Texture& Texture::operator=(const Texture& right)
{
	if(this == &right)
	{
		return *this;
	}
	
	_texture = nullptr;
	_texture = right._texture;

	return *this;
}

Texture::SharedTexture Texture::MakeSharedTexture(SDL_Texture* texture)
{
	return SharedTexture(texture, SDL_DestroyTexture);
}


