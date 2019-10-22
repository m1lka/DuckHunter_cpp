#ifndef _TEXTURE_HPP_
#define _TEXTURE_HPP_

#include <memory>
#include <string>
#include <SDL2/SDL.h>

class Sprite;

class Texture
{
public:
	Texture();
 	Texture(const Texture& texture);
	~Texture();
	
	SDL_Texture* getHandle() const;
	
	void LoadFromBMP(std::string path, SDL_Renderer* renderHandle);
	void LoadFromPNG(std::string path, SDL_Renderer* renderHandle);
	
	Texture& operator=(const Texture& right);
	
private:
    using SharedTexture = std::shared_ptr<SDL_Texture>;
	
    static SharedTexture MakeSharedTexture(SDL_Texture* texture);
    void Clear();
	
    std::shared_ptr<SDL_Texture> _texture;

    bool isInitted() const;

    friend class Sprite;
};

#endif // _TEXTURE_HPP_
