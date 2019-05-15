#include "mEngine/mCore.hpp"
#include "mEngine/UI/MessageBox.hpp"

#include <SDL2/SDL.h>
#include <iostream>
#include <exception>

using namespace std;

mCore::mCore(string titleWindow, int widthWindow, int heightWindow, Uint32 windowFlag): 
	_window(),
	_renderer(),
    run(true)
{
	using namespace std::placeholders;
	
	SDL_Log("mCore::mCore() begin");
	SDL_Init(0);
	
	Input = &InputEngine::instance();
	
	_window.SetVideoMode(titleWindow, widthWindow, heightWindow, windowFlag);
	
	_renderer.Initialize(_window.getWindowHandle());
	
	Input->Quit = std::bind(&mCore::OnQuit, this);
	Input->WindowResized = std::bind(&mCore::OnWindowResized, this, _1, _2);
	Input->Initialize();
	
	SDL_Log("mCore::mCore() end");
}

mCore::~mCore()
{
	SDL_Log("mCore::~mCore() begin");
	
	_window.DisposeWindow();
	
	Input->Dispose();
	Input = nullptr;

	SDL_Log("mCore::~mCore() end");
	SDL_Quit();
}

void mCore::EventLoop()
{
	
}

void mCore::OnQuit()
{
	DialogResult res = MessageBox::ShowDialog("Info", "Exit?");
	if(res == DialogResult::No)
		cerr << "Pressed No\n";
	else if(res == DialogResult::Yes)
	{
		cerr << "Pressed Yes\n";
		run = false;
	}
}

void mCore::OnWindowResized(int newWidth, int newHeight)
{
	_window.setWindowWidth(newWidth).setWindowHeight(newHeight);
}

void mCore::Run()
{
	Initialize();
	
	while(run)
	{
		// calc time
		
		Input->Update();
						
		Update();
		Render(_renderer);
	}
}

