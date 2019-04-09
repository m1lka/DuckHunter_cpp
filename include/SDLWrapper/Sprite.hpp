#ifndef _SPRITE_HPP_
#define _SPRITE_HPP_

#include "SDLWrapper/Texture.hpp"

class Sprite
{
public:
	Sprite(Texture &texture, SDL_Rect bound);
	~Sprite();
	
	Texture& getTexture();
	SDL_Rect getBound() const;
	
	Sprite& operator=(const Sprite& right);
	
private:
	Texture _texture;
	SDL_Rect _bound;
};

#endif