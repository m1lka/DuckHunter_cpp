#ifndef _TEXTURE_HPP_
#define _TEXTURE_HPP_

#include <memory>
#include <string>
#include <SDL2/SDL.h>

class Texture
{
public:

	Texture();
 	Texture(const Texture& texture);
	~Texture();
	
	SDL_Texture* getTextureHandle() const;
	
	void LoadFromBMP(std::string path, SDL_Renderer* renderHandle);
	void LoadFromPNG(std::string path, SDL_Renderer* renderHandle);
	
	Texture& operator=(const Texture& right);
	
	long int getCount() const
	{
		return _texture.use_count();
	}
	
private:
	using SharedTexture = std::shared_ptr<SDL_Texture>;
	
	SharedTexture MakeSharedTexture(SDL_Texture* texture);
	
	SharedTexture _texture;
};

#endif // _TEXTURE_HPP_
