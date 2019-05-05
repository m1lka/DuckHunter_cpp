#include "Game.hpp"
#include <iostream>

using std::cerr;

Game::Game():
	run(true),
	_window()
{
	SDL_Init(0);
	cerr << "Game()\n";
}

Game::~Game()
{
	_window.DisposeWindow();
	SDL_Quit();
	cerr << "~Game()\n";
}

void Game::Run()
{
    std::cerr << "method Run()\n";
	_window.SetVideoMode("Test", 500, 500, SDL_WINDOW_SHOWN);
	
	while(run)
	{
		SDL_Event event;
		while(SDL_PollEvent(&event) != 0)
		{
			if(event.type == SDL_QUIT)
				run = false;
		}
	}
}
