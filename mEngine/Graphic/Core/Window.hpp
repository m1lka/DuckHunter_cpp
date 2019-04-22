#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <memory>
#include <string>
#include <SDL2/SDL.h>
#include <functional>

class Window
{
public:
	
    Window();
	~Window();
	
	SDL_Window* getHandle() const;
	std::string getTitle() const;
	
	int getWidth() const;
    Window& setWidth(int width);
	
	int getHeight() const;
    Window& setHeight(int height);
		
    void Initialize(std::string title, int width, int heght, Uint32 windowFlags);
	
private:
	int _width;
	int _height;
	std::string _title;
	Uint32 _windowFlag;
	
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> _window;
	
    void CreateWindow();
    void Dispose();
};

#endif // _WINDOW_HPP_
