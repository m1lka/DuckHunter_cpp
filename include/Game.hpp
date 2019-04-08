#include "SDLWrapper/Window.hpp"
#include "SDLWrapper/Render/Renderer.hpp"
#include "SDLWrapper/Texture.hpp"

#include <iostream>

class Game
{
public:
	
	bool run;
	
	Game():
		run(true)
	{
		
	}
	
	void Quit()
	{
		run = false;
	}
	
	void Run()
	{
		Window window("Test", 400, 400, SDL_WINDOW_SHOWN, SDL_INIT_EVERYTHING);

        Renderer render;
		
		window.Initialize();
		window.Quit = std::bind(&Game::Quit, this);
		
		render.Initialize(window.getHandle());
		
		Texture texture;
		
        texture.LoadFromBMP("./field.bmp", render.getRendererHandle());
		
		while(run)
		{
            render.Clear();
			SDL_Event event;
			while(SDL_PollEvent(&event) == 1)
			{
				window.Update(event);
			}
			
			render.RenderTexture(texture.getTextureHandle());
            render.Update();
		}
		
		SDL_Quit();
	}	
};
