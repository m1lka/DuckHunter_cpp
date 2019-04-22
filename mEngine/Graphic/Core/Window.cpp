#include "mEngine/Graphic/Core/Window.hpp"
#include "mEngine/UI/MessageBox.hpp"

#include <iostream>
#include <exception>
#include <functional>

#include "mEngine/Input/Input.hpp"


using std::cerr;

Window::Window():
    _width(0),
    _height(0),
    _title("Window"),
    _windowFlag(0),
	_window(nullptr, SDL_DestroyWindow)
{

}

Window::~Window()
{
	Dispose();
}

void Window::Initialize(std::string title, int width, int heght, Uint32 windowFlags)
{
    if (SDL_WasInit(SDL_INIT_VIDEO) != 0) {
        cerr << "Window::Initialize ok\n";
    } else {
        std::string error = "ERROR::Video system is not initialized\n";
        cerr << error << "\n";
        throw std::bad_function_call();
    }

    _title = title;
    _width = width;
    _height = heght;
    _windowFlag = windowFlags;
	
	CreateWindow();
}

void Window::CreateWindow()
{
	_window.reset(SDL_CreateWindow(
					_title.c_str(), 
                    SDL_WINDOWPOS_CENTERED,
                    SDL_WINDOWPOS_CENTERED,
					_width, _height, 
					_windowFlag));
	
	if(_window == nullptr)
	{
		std::string error = std::string("SDL_CreateWindow Error: ") + SDL_GetError();
		cerr << error << "\n";
		throw std::bad_function_call();
	}
}

void Window::Dispose()
{
    _window.get_deleter();
}

SDL_Window* Window::getHandle() const
{
	return _window.get();
}

std::string Window::getTitle() const
{
	return _title;
}

int Window::getWidth() const
{
	return _width;
}

Window& Window::setWidth(int width)
{
	_width = width;
    return *this;
}

int Window::getHeight() const
{
	return _height;
}

Window& Window::setHeight(int height)
{
	_height = height;
    return *this;
}

