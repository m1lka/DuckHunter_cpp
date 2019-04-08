#ifndef _TEXTURE_HPP_
#define _TEXTURE_HPP_

#include <memory>
#include <string>
#include <SDL2/SDL.h>

class Texture
{
public:

	Texture();
	~Texture();
	
	SDL_Texture *getTextureHandle() const;
	
	void LoadFromBMP(std::string path, SDL_Renderer *renderHandle);
	void LoadFromPNG(std::string path, SDL_Renderer *renderHandle);
	
private:
	std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> _texture;
};

#endif // _TEXTURE_HPP_
