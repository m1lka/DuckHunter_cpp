#include "mEngine/mCore.hpp"
#include <iostream>

#include <SDL2/SDL.h>
#include <exception>

using namespace std;

mCore::mCore(): 
    run(true)
{
    // = nullptr
    cerr << "mCore::mCore()\n";
	SDL_Init(0);
}

mCore::~mCore()
{
	SDL_Quit();
}

void mCore::Run()
{
    // инициализация компонентов
    
}

void mCore::InitGame()
{
    // настройка компонентов
}

void mCore::ProcessFrame()
{
    // обновление и рендер компонентов
}

bool mCore::IsRunning() const
{
    return run;
}

void mCore::DoExit()
{
    run = false;
}
