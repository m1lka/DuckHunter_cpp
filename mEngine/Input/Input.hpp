#ifndef _INPUT_HPP
#define _INPUT_HPP

#pragma once

#include "mEngine/Input/InputMapping.hpp"
#include "mEngine/Math/Vector2.hpp"

#include <array>
#include <functional>

using std::array;
using std::function;

class InputEngine;

namespace Private
{
	class InputEngineDestroyer
	{
	private:
		InputEngine* _instance;
		
	public:
		~InputEngineDestroyer();
		void Initialize(InputEngine* instance);
	};
}

class InputEngine
{
public:
	~InputEngine();
	
	void Initialize();	
	void Dispose();
	
	void Update();
	
	Vector2& GetMousePosition(bool previosFrame);
	Vector2& GetMouseMovement();
	
	bool IsKeyDown(KeyboardKey key) const;
	bool IsKeyPressed(KeyboardKey key) const;
	
	bool IsMouseButtonPressed(MouseKey key) const;
	bool IsMouseButtonDown(MouseKey key) const;
	
	function<void()> Quit;
	function<void(int, int)> WindowResized;
	
	static InputEngine &instance();
	
protected:
	friend class Private::InputEngineDestroyer;
	
private:
	InputEngine();
	static InputEngine *_instance;
	static Private::InputEngineDestroyer destroyer;
	
	void SetKey(int keycode, bool down);
	void SetMouseButton(int mousebutton, bool down);
	
	unsigned _mouseButtonDown;
	unsigned _mouseButtonPressed;
	
	Vector2 _oldMousePosition;
	Vector2 _currentMousePosition;
	Vector2 _mouseMovement;
	
	array<bool, (size_t)KeyboardKey::MAX> _keyDown;
	array<bool, (size_t)KeyboardKey::MAX> _keyPressed;
};

#endif // _INPUT_HPP
