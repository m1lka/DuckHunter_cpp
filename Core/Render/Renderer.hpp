#ifndef _RENDERER_HPP
#define _RENDERER_HPP

#include "Core/Render/RenderRegion.hpp"
#include "Core/Sprite.hpp"

#include <SDL2/SDL.h>
#include <memory>

class Renderer 
{
public:
	Renderer();
	~Renderer();
	
	void Initialize(SDL_Window* windowHandle);
	void Update();
	void Clear();
	
	RenderRegion getRenderRegion() const;
	SDL_Renderer *getRendererHandle() const;
	
	void RenderTexture(Texture& texture);
	void RenderSprite(Sprite& sprite);
	
private:
	RenderRegion _renderRegion;
	
	std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> _renderer;
};

#endif // _RENDERER_HPP
