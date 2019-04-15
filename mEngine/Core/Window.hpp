#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_

#include <memory>
#include <string>
#include <SDL2/SDL.h>
#include <functional>

class Window
{
public:
	
	Window(std::string title, int width, int height, Uint32 windowFlag, Uint32 systemFlag);
	~Window();
	
	SDL_Window* getHandle() const;
	std::string getTitle() const;
	
	int getWidth() const;
	void setWidth(int width);
	
	int getHeight() const;
	void setHeight(int height);
	
	std::function<void()> Quit;
	
	void Initialize();
	void Update(SDL_Event &currentEvent);
	
private:
	int _width;
	int _height;
	std::string _title;
	Uint32 _systemFlag;
	Uint32 _windowFlag;
	
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> _window;
	
	void CreateWindow();
	void Dispose();
};

#endif // _WINDOW_HPP_
