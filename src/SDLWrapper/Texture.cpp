#include "SDLWrapper/Texture.hpp"
#include <iostream>

using std::cerr;
using std::string;

Texture::Texture():
	_texture(nullptr, SDL_DestroyTexture)
{
	
}

Texture::~Texture()
{
	_texture.reset();
}

void Texture::LoadFromBMP(string path, SDL_Renderer *renderHandle)
{
	if(_texture != nullptr)
		_texture.reset();

    cerr << "renderer ptr " << renderHandle << "\n";
	
	SDL_Surface *surface = SDL_LoadBMP(path.c_str());
	if(surface == nullptr)
	{
		string error = string("SDL_LoadBMP error: ") + SDL_GetError();
		cerr << error << "\n";
        throw std::exception();
	}
	
	_texture.reset(SDL_CreateTextureFromSurface(renderHandle, surface));
    if(_texture == nullptr)
	{
		string error = string("SDL_CreateTextureFromSurface error: ") + SDL_GetError();
		cerr << error << "\n";
        throw std::exception();
	}
}

void Texture::LoadFromPNG(std::string path, SDL_Renderer* renderHandle)
{
	// TODO
}

SDL_Texture* Texture::getTextureHandle() const
{
	return _texture.get();
}
