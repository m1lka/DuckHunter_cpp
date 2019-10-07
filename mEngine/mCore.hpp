#ifndef MENGINE_HPP
#define MENGINE_HPP

#include "mEngine/Graphic/Core/Window.hpp"
#include "mEngine/Graphic/Render/Renderer.hpp"
#include "mEngine/Input/Input.hpp"

#include <string>
using std::string;

class mCore
{
public:
    mCore(string titleWindow, int widthWindow, int heightWindow, Uint32 windowFlag);
	virtual ~mCore();
	
	void OnQuit();
	void OnWindowResized(int newWidth, int newHeight);
	
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render(Renderer& renderer) = 0;
	
	void Run();

    SDL_Renderer *getRendererHandle() const;
	
private:
	
    InputEngine* Input;
	
	void EventLoop();
	
	Window _window;
    Renderer _renderer;
	
    bool run;

};

#endif // MENGINE_HPP
