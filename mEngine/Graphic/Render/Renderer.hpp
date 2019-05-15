#ifndef _RENDERER_HPP
#define _RENDERER_HPP

#include "mEngine/Graphic/Render/RenderRegion.hpp"
#include "mEngine/Graphic/Core/Sprite.hpp"

#include <SDL2/SDL.h>
#include <memory>

class Renderer 
{
public:
	Renderer();
	~Renderer();
	
	void Initialize(SDL_Window* windowHandle);
	
	void Clear();
	
	void RenderTexture(Texture& texture);
	void RenderSprite(Sprite& sprite);
	
	void Update();
	
	RenderRegion getRenderRegion() const;
	SDL_Renderer *getRendererHandle() const;
	
private:
	RenderRegion _renderRegion;
	
	std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> _renderer;
};

#endif // _RENDERER_HPP
