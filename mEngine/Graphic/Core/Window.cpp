#include "mEngine/Graphic/Core/Window.hpp"

#include <exception>
#include <iostream>

using std::cerr;
using std::string;

Window::Window():
    _windowWidth(0),
    _windowHeight(0),
    _windowTitle(""),
    _window(nullptr, SDL_DestroyWindow)
{
	cerr << "Window()\n";
}

Window::~Window()
{
	cerr << "~Window()\n";
}

SDL_Window* Window::getWindowHandle() const
{
    if(_window)
        return _window.get();

    return nullptr;
}

std::string Window::getWindowTitle() const
{
    return _windowTitle;
}

int Window::getWindowWidth() const
{
    return _windowWidth;
}

Window& Window::setWindowWidth(int width)
{
    _windowWidth = width;

    return *this;
}

int Window::getWindowHeight() const
{
    return _windowHeight;
}

Window& Window::setWindowHeight(int height)
{
    _windowHeight = height;

    return *this;
}

void Window::SetVideoMode(string titleWindow, int width, int height, Uint32 windowFlag)
{
	cerr << "SetVideoMode()\n";
    _windowTitle = titleWindow;
    _windowWidth = width;
    _windowHeight = height;
    _windowFlag = windowFlag;

	InitVideoSystem();
    CreateWindow();
}

void Window::CreateWindow()
{
	cerr << "CreateWindow()\n";
    _window.reset(SDL_CreateWindow(
                    _windowTitle.c_str(),
                    SDL_WINDOWPOS_CENTERED,
                    SDL_WINDOWPOS_CENTERED,
                    _windowWidth, _windowHeight,
                    _windowFlag));

    if(_window == nullptr)
    {
        string error = string("SDL_CreateWindow Error: ") + SDL_GetError();
        cerr << error << "\n";
        throw std::runtime_error(error.c_str());
    }
}

void Window::InitVideoSystem()
{
	cerr << "InitVideoSystem()\n";
	SDL_VideoInit(nullptr);
	// SDL_InitSubsystem(SDL_INIT_VIDEO);
}

void Window::DisposeWindow()
{
	cerr << "DisposeWindow()\n";
    _window.get_deleter();
	SDL_VideoQuit();
	
	//SDL_QuitSubSystem(SDL_INIT_VIDEO);
}
