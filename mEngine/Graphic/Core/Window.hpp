#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <memory>
#include <string>
#include <SDL2/SDL.h>
#include <functional>

class Window
{
public:
    Window();
    ~Window();

    SDL_Window* getWindowHandle() const;
    std::string getWindowTitle() const;

    int getWindowWidth() const;
    Window& setWindowWidth(int width);

    int getWindowHeight() const;
    Window& setWindowHeight(int height);

    void SetVideoMode(std::string titleWindow, int width, int height, Uint32 windowFlag);
	void DisposeWindow();
		
	void Update(SDL_Event& currentEvent);

private:
    int _windowWidth;
    int _windowHeight;
    std::string _windowTitle;
    Uint32 _windowFlag;

    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> _window;

    void InitVideoSystem();
    void InitWindow();
};

#endif // GRAPHICS_H
