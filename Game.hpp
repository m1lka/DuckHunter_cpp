#include <iostream>
#include "mEngine/mCore.hpp"
#include "mEngine/Input/Input.hpp"
#include "mEngine/Graphic/Core/Sprite.hpp"

class Game: public mCore
{
public:
    Game(): 
        mCore("Test", 500, 500, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE) {}
	    
    virtual ~Game() 
	{

	}
    	
    void Initialize() override
    {
        Texture t;
        t.LoadFromPNG("./field.png", getRendererHandle());
        SDL_Rect r;
        r.x = 0; r.y = 0; r.w = 300; r.h = 300;
        sprite.reset(t, r);
	}
    
    void Update(Renderer& renderer) override
    {
		
    }
    
    void Render(Renderer& renderer) override
    {
		renderer.Clear();
        renderer.RenderSprite(sprite);
		renderer.Update();
    }

private:
    Sprite sprite;
};
