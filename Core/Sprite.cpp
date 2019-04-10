#include "Core/Sprite.hpp"
#include <iostream>

Sprite::Sprite(Texture& texture, SDL_Rect bound):
	_texture(texture),
	_bound(bound)
{

}

Sprite::~Sprite()
{
	
}

SDL_Rect Sprite::getBound() const
{
	return _bound;
}

Texture &Sprite::getTexture()
{
	return _texture;
}

Sprite& Sprite::operator=(const Sprite& right)
{
	if(this == &right)
	{
		return *this;
	}
	
	_texture = right._texture;
	_bound = right._bound;

	return *this;
}

