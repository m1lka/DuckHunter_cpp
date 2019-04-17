#ifndef _INPUT_HPP
#define _INPUT_HPP

#include "mEngine/Input/MouseState.hpp"
#include "mEngine/Input/KeyboardState.hpp"

#include <memory>
#include <SDL2/SDL.h>

namespace Input
{
	using p_KeyboardState = std::shared_ptr<KeyboardState_t>;
	using p_MouseState = std::shared_ptr<MouseState_t>;
	
	static p_KeyboardState Keyboard = nullptr;
	static p_MouseState MouseState = nullptr;
	
	static void UpdateMouseState(SDL_Event &currentEvent)
	{
		SDL_MouseButtonEvent mouseButtonEvent = currentEvent.button;
		auto buttonType = mouseButtonEvent.type;
		auto buttonTimespamp = mouseButtonEvent.timestamp;
		auto buttonWhich = mouseButtonEvent.which;
		auto buttonButton = (Mouse::Button)mouseButtonEvent.button;
		auto buttonState = (Mouse::ButtonState)mouseButtonEvent.state;
		auto buttonClicks = (Mouse::Click)mouseButtonEvent.clicks;
		auto buttonPositionX = mouseButtonEvent.x;
		auto buttonPositionY = mouseButtonEvent.y;
		
		SDL_MouseWheelEvent mouseWheelEvent = currentEvent.wheel;
		auto wheelType = mouseWheelEvent.type;
		auto wheelTimespamp = mouseWheelEvent.timestamp;
		auto wheelWhich = mouseWheelEvent.which;
		auto scrollX = mouseWheelEvent.x;
		auto scrollY = mouseWheelEvent.y;
		
		SDL_MouseMotionEvent mouseMotionEvent = currentEvent.motion;
		auto motionType = mouseMotionEvent.type;
		auto motionTimestamp = mouseMotionEvent.timestamp;
		auto motionWhich = mouseMotionEvent.which;
		auto motionState = mouseMotionEvent.state;
		auto motionX = mouseMotionEvent.x;
		auto motionY = mouseMotionEvent.y;
		auto motionXRel = mouseMotionEvent.xrel;
		auto motionYRel = mouseMotionEvent.yrel;
		
		MouseState.reset(new MouseState_t(
								buttonButton,
								buttonState,
								buttonClicks,
								buttonPositionX,
								buttonPositionY,
								scrollY));
	}
	
	static void UpdateKeyboardState(SDL_Event &currentEvent)
	{
		auto keyEvent = currentEvent.key;
		
		auto keySym = keyEvent.keysym;
		auto modifier = keySym.mod;
		auto key = keySym.scancode;
		
		bool repeat = (keyEvent.repeat != 0? true: false);
		
		Key::State state = (keyEvent.state == 0? Key::Released: Key::Pressed);
		
        unsigned short timestamp = keyEvent.timestamp;
		auto type = keyEvent.type;
		
		Keyboard.reset(new KeyboardState_t(
								modifier,
								key,
								repeat,
								state,
								timestamp,
								type));
	}
	
	static void Update(SDL_Event &currentEvent)
	{
		UpdateMouseState(currentEvent);
		UpdateKeyboardState(currentEvent);
	}
	
	static void Clear()
	{
		Keyboard.reset();
		MouseState.reset();
	}
}

#endif // _INPUT_HPP
