#include "mEngine/Graphic/Core/Sprite.hpp"
#include <iostream>

Sprite::Sprite():
    _bound({0, 0, 0, 0})
{

}

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
    if(_texture.isInitted())
        return _texture;
    else
        throw std::exception();
}

void Sprite::reset(Texture &texture, SDL_Rect bound)
{
    if(_texture.isInitted())
        _texture.Clear();

    _texture = texture;
    _bound = bound;
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

