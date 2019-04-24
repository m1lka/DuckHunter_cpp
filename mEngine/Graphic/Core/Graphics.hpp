#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "mEngine/Core/Subsystem.hpp"
#include <memory>
#include <string>
#include <SDL2/SDL.h>

class Graphics: public Subsystem
{
public:
    Graphics(Context* context);
    virtual ~Graphics();

    static string GetTypeInfo() { return string("Graphic"); }
    static string GetBaseTypeInfo() { return string("Subsystem"); }

    SDL_Window* getWindowHandle() const;
    std::string getWindowTitle() const;

    int getWindowWidth() const;
    Graphics& setWindowWidth(int width);

    int getWindowHeight() const;
    Graphics& setWindowHeight(int height);

    void SetVideoMode(string titleWindow, int width, int height, Uint32 windowFlag);

private:
    int _windowWidth;
    int _windowHeight;
    std::string _windowTitle;
    Uint32 _windowFlag;

    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> _window;

    void CreateWindow();
    void DisposeWindow();
};

#endif // GRAPHICS_H
