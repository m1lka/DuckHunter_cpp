#ifndef _SPRITE_HPP_
#define _SPRITE_HPP_

#include "mEngine/Graphic/Core/Texture.hpp"

class Sprite
{
public:
    Sprite();
	Sprite(Texture &texture, SDL_Rect bound);
	~Sprite();

    void reset(Texture &texture, SDL_Rect bound);
	
	Texture& getTexture();
	SDL_Rect getBound() const;
	
	Sprite& operator=(const Sprite& right);
	
private:
	Texture _texture;
	SDL_Rect _bound;
};

#endif
