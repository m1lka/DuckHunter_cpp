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
        t.LoadFromPNG("./field.png", getRendererHandle());
	}
    
    void Update() override
    {
		
    }
    
    void Render(Renderer& renderer) override
    {
		renderer.Clear();
        renderer.RenderTexture(t);
		renderer.Update();
    }

private:
    Texture t;
};
