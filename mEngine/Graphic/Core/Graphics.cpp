#include "mEngine/Graphic/Core/Graphics.hpp"
#include "mEngine/Core/Context.hpp"

#include <exception>
#include <iostream>

using std::cerr;
using std::string;

Graphics::Graphics(Context* context):
    Subsystem (context),
    _windowWidth(0),
    _windowHeight(0),
    _windowTitle(""),
    _window(nullptr, SDL_DestroyWindow)
{
    _context->InitSDLSystem(SDL_INIT_VIDEO);
}

Graphics::~Graphics()
{
    DisposeWindow();
    _context->SDLQuit();
    cerr << "Graphics::~Graphics()\n";
}

SDL_Window* Graphics::getWindowHandle() const
{
    if(_window)
        return _window.get();

    return nullptr;
}

std::string Graphics::getWindowTitle() const
{
    return _windowTitle;
}

int Graphics::getWindowWidth() const
{
    return _windowWidth;
}

Graphics& Graphics::setWindowWidth(int width)
{
    _windowWidth = width;

    return *this;
}

int Graphics::getWindowHeight() const
{
    return _windowHeight;
}

Graphics& Graphics::setWindowHeight(int height)
{
    _windowHeight = height;

    return *this;
}

void Graphics::SetVideoMode(string titleWindow, int width, int height, Uint32 windowFlag)
{
    _windowTitle = titleWindow;
    _windowWidth = width;
    _windowHeight = height;
    _windowFlag = windowFlag;

    CreateWindow();
}

void Graphics::CreateWindow()
{
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

void Graphics::DisposeWindow()
{
    _window.get_deleter();
}
