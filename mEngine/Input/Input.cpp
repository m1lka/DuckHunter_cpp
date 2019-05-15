#include "mEngine/Input/Input.hpp"
#include <string>
#include <exception>
#include <iostream>

std::unique_ptr<InputEngine> InputEngine::_instance = nullptr;

InputEngine::InputEngine():
	Quit(nullptr),
	WindowResized(nullptr),
	_mouseButtonDown(0),
	_mouseButtonPressed(0),
	_oldMousePosition(0.0f, 0.0f),
	_currentMousePosition(0.0f, 0.0f),
	_mouseMovement(0.0f, 0.0f),
	_keyDown({}),
	_keyPressed({})
{
	SDL_Log("InputEngine::InputEngine()");
}

InputEngine& InputEngine::instance()
{
	if(_instance == nullptr)
	{
        _instance.reset(new InputEngine());
        //destroyer.Initialize(_instance);
	}
	
    return *_instance;
}

InputEngine::~InputEngine()
{
	SDL_Log("InputEngine::~InputEngine()");
}

void InputEngine::Update()
{
	std::fill(_keyPressed.data(), _keyPressed.data() + (_keyPressed.size() - 1), false);
	_mouseButtonPressed = 0;
	
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_WINDOWEVENT:
			{
				switch(event.window.event)
				{
					case SDL_WINDOWEVENT_RESIZED:
						if(WindowResized)
							WindowResized(event.window.data1, event.window.data2);
						break;
				}
				break;
			}
			
			case SDL_QUIT:
				if(Quit)
					Quit();
				break;
				
			case SDL_KEYDOWN:
				if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				{
					if(Quit)
						Quit();
				}
				else
				{
					SetKey(event.key.keysym.scancode, true);
				}
				break;
				
			case SDL_KEYUP:
				SetKey(event.key.keysym.scancode, false);
				break;
				
			case SDL_MOUSEBUTTONDOWN:
				SetMouseButton(1 << (event.button.button - 1), true);
				break;
				
			case SDL_MOUSEBUTTONUP:
				SetMouseButton(1 << (event.button.button - 1), false);
				break;
					
			default:
				break;
		}
	}
	
	_oldMousePosition = _currentMousePosition;
	int newX, newY;
	SDL_GetMouseState(&newX, &newY);
	
	_currentMousePosition.x = (float)newX;
	_currentMousePosition.y = (float)newY;
	
	_mouseMovement.x = _currentMousePosition.x - _oldMousePosition.x;
	_mouseMovement.y = _currentMousePosition.y - _oldMousePosition.y;
}

void InputEngine::Initialize()
{
	if(SDL_InitSubSystem(SDL_INIT_EVENTS) != 0)
	{
		std::string error = std::string("SDL_InitSubSystem Input Error: ") + SDL_GetError();
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, error.c_str());
        throw std::runtime_error(error.c_str());
	}
	SDL_Log("SDL_InitSubSystem: Input succes");
}

void InputEngine::Dispose()
{
	SDL_Log("Dispose input()");
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	Quit = nullptr;
	WindowResized = nullptr;
}

Vector2& InputEngine::GetMousePosition(bool previosFrame)
{
	return (previosFrame? _oldMousePosition: _currentMousePosition);
}

Vector2& InputEngine::GetMouseMovement()
{
	return _mouseMovement;
}

bool InputEngine::IsKeyDown(KeyboardKey key) const
{
	return _keyDown[(int)key];
}

bool InputEngine::IsKeyPressed(KeyboardKey key) const
{
	return _keyPressed[(int)key];
}

bool InputEngine::IsMouseButtonDown(MouseKey key) const
{
	return ((_mouseButtonDown >> ((int)key - 1)) & 1) == 1;
}

bool InputEngine::IsMouseButtonPressed(MouseKey key) const
{
	return ((_mouseButtonPressed >> ((int)key - 1)) & 1) == 1;
}

void InputEngine::SetKey(int keycode, bool down)
{
	if(down)
	{
		if(_keyDown[keycode] == false)
			_keyPressed[keycode] = true;
		_keyDown[keycode] = true;
	}
	else
	{
		_keyDown[keycode] = false;
	}
}

void InputEngine::SetMouseButton(int mousebutton, bool down)
{
	if(down)
	{
		if((_mouseButtonDown & mousebutton) == 0)
		{
			_mouseButtonPressed |= mousebutton;
		}
		_mouseButtonDown |= mousebutton;
	}
	else
	{
		_mouseButtonDown &= ~mousebutton;
	}
}
