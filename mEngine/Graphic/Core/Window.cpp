#include "mEngine/Graphic/Core/Window.hpp"
#include "mEngine/UI/MessageBox.hpp"

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
	SDL_Log("Window::Window()");
}

Window::~Window()
{
	SDL_Log("Window::~Window()");
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
	SDL_Log("Window::SetVideoMode");
    _windowTitle = titleWindow;
    _windowWidth = width;
    _windowHeight = height;
    _windowFlag = windowFlag;

	InitVideoSystem();
    InitWindow();
}

void Window::InitWindow()
{
	SDL_Log("Window::CreateWindow");
    _window.reset(SDL_CreateWindow(
                    _windowTitle.c_str(),
                    SDL_WINDOWPOS_CENTERED,
                    SDL_WINDOWPOS_CENTERED,
                    _windowWidth, _windowHeight,
                    _windowFlag));

    if(_window == nullptr)
    {
        string error = string("SDL_CreateWindow Error: ") + SDL_GetError();
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, error.c_str());
        throw std::runtime_error(error.c_str());
    }
}

void Window::InitVideoSystem()
{
	SDL_Log("Window::InitVideoSystem");
	SDL_VideoInit(nullptr);
	// SDL_InitSubsystem(SDL_INIT_VIDEO);
}

void Window::DisposeWindow()
{
	SDL_Log("Window::DisposeWindow");

	_window.get_deleter();
	SDL_VideoQuit();
	
	//SDL_QuitSubSystem(SDL_INIT_VIDEO);
}

void Window::Update(SDL_Event& currentEvent)
{
// 	auto windowEvent = currentEvent.window;
// 	_windowWidth = windowEvent.data1;
// 	_windowHeight = windowEvent.data2;
// 	
// 	if(currentEvent.quit.type == SDL_QUIT ||
// 		currentEvent.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
// 	{
// 		DialogResult res = MessageBox::ShowDialog("Info", "Exit?");
// 		if(res == DialogResult::No)
// 			cerr << "Pressed No\n";
// 		else if(res == DialogResult::Yes)
// 		{
// 			cerr << "Pressed Yes\n";
// 			if(Quit)
// 				Quit();
// 		}
// 	}
}

