#include "mEngine/Core/Window.hpp"
#include "mEngine/Core/MessageBox.hpp"

#include <iostream>
#include <exception>
#include <functional>

#include "mEngine/Core/Input/Input.hpp"


using std::cerr;

Window::Window(std::string title, int width, int height, Uint32 windowFlag, Uint32 systemFlag):
	Quit(nullptr),
	_width(width),
	_height(height),
	_title(title),
	_systemFlag(systemFlag),
	_windowFlag(windowFlag),
	_window(nullptr, SDL_DestroyWindow)
{

}

Window::~Window()
{
	Dispose();
}

void Window::Initialize()
{
	if(SDL_Init(_systemFlag) != 0)
	{
		std::string error = std::string("SDL_Init Error: ") + SDL_GetError();
		cerr << error << "\n";
		throw std::bad_function_call();
	}
	
	CreateWindow();
}

void Window::CreateWindow()
{
	_window.reset(SDL_CreateWindow(
					_title.c_str(), 
				    500, 500, 
					_width, _height, 
					_windowFlag));
	
	if(_window == nullptr)
	{
		std::string error = std::string("SDL_CreateWindow Error: ") + SDL_GetError();
		cerr << error << "\n";
		throw std::bad_function_call();
	}
}

void Window::Update(SDL_Event& currentEvent)
{
	auto windowEvent = currentEvent.window;
	_width = windowEvent.data1;
	_height = windowEvent.data2;
	
	if(currentEvent.quit.type == SDL_QUIT ||
		currentEvent.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
	{
		DialogResult res = MessageBox::ShowDialog("Info", "Do you pressed Exit?");
		if(res == DialogResult::No)
			cerr << "Pressed NO\n";
		else if(res == DialogResult::Yes)
			cerr << "Pressed YES\n";
		if(Quit)
			Quit();
	}
}

void Window::Dispose()
{
	_window.release();
	Quit = nullptr;
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

void Window::setWidth(int width)
{
	_width = width;
}

int Window::getHeight() const
{
	return _height;
}

void Window::setHeight(int height)
{
	_height = height;
}

