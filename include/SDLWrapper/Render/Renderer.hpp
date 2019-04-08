#ifndef _RENDERER_HPP
#define _RENDERER_HPP

#include <SDL2/SDL.h>
#include <memory>
#include "SDLWrapper/Render/RenderRegion.hpp"

class Renderer 
{
public:
	Renderer();
	~Renderer();
	
	void Initialize(SDL_Window *windowHandle);
	void Update();
	void Clear();
	
	RenderRegion getRenderRegion() const;
	SDL_Renderer *getRendererHandle() const;
	
	void RenderTexture(SDL_Texture *texture);
	
private:
	RenderRegion _renderRegion;
	
	std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> _renderer;
};

#endif // _RENDERER_HPP
