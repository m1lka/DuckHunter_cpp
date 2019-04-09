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

        texture.LoadFromPNG("./field.png", render.getRendererHandle());
		
		SDL_Rect rect;
		rect.x = 0, rect.y = 0, rect.w = 300, rect.h = 300;
		Sprite s(texture, rect);

		while(run)
		{
            render.Clear();
			SDL_Event event;
			while(SDL_PollEvent(&event) == 1)
			{
				window.Update(event);
			}
			
			render.RenderSprite(s);
            render.Update();
		}
		
		SDL_Quit();
	}	
};
