#include "mEngine/Graphic/Render/Renderer.hpp"
#include <iostream>
#include <exception>

using std::cerr;
using std::string;

Renderer::Renderer():
    _renderRegion({300, 300}),
	_renderer(nullptr, SDL_DestroyRenderer)
{
	SDL_Log("Renderer::Renderer()");
}

Renderer::~Renderer()
{
	_renderer.release();
	SDL_Log("Renderer::~Renderer()");
}

void Renderer::Initialize(SDL_Window* windowHandle)
{
	SDL_Log("Renderer::Initialize()");
	_renderer.reset(SDL_CreateRenderer(windowHandle, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
	if(_renderer == nullptr)
	{
		string error = string("SDL_CreateRenderer Error: ") + SDL_GetError();
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, error.c_str());
        throw std::exception();
	}

	if(SDL_RenderSetLogicalSize(_renderer.get(), _renderRegion.Width, _renderRegion.Height) < 0)
	{
		string error = string("SDL_RenderSetLogicalSize Error: ") + SDL_GetError();
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, error.c_str());
        throw std::exception();
	}
}

void Renderer::Update()
{
	SDL_RenderPresent(_renderer.get());
}

void Renderer::Clear()
{
	SDL_RenderClear(_renderer.get());
}

SDL_Renderer* Renderer::getRendererHandle() const
{
	return _renderer.get();
}

RenderRegion Renderer::getRenderRegion() const
{
	return _renderRegion;
}

void Renderer::RenderTexture(Texture& texture)
{
	SDL_Rect *rect = new SDL_Rect;// = {0, 0, 300, 300};
    rect->x = 0; rect->y = 0; rect->w = 300; rect->h = 300;
	SDL_RenderCopy(_renderer.get(), texture.getHandle(), nullptr, rect);
}

void Renderer::RenderSprite(Sprite& sprite)
{
	SDL_Rect rect = sprite.getBound();
	SDL_Texture *texture = sprite.getTexture().getHandle();
	SDL_RenderCopy(_renderer.get(), texture, nullptr, &rect);
}



