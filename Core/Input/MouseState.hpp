#ifndef _MOUSESTATE_HPP_
#define _MOUSESTATE_HPP_

#include <SDL2/SDL.h>

namespace Mouse
{
	enum ButtonState
	{
		Pressed = 0,
		Released = 1
	};
	
	enum Click
	{
		Single = 1,
		Double = 2
	};
	
	enum Button
	{
		Left = 1,
		Middle = 2,
		Right = 3,
		X1 = 4,
		X2 = 5
	};
}

struct t_MouseState
{
public:
	t_MouseState(
		Mouse::Button button,
		Mouse::ButtonState buttonState,
		Mouse::Click click,
		int positionX,
		int positionY,
		int scroll
	):
		_button(button),
		_buttonState(buttonState),
		_click(click),
		_positionX(positionX),
		_positionY(positionY),
		_scroll(scroll) {}
		
	~t_MouseState() {}
	
	struct t_MouseState& operator=(const struct t_MouseState& right)
	{
		if(this == &right)
		{
			return *this;
		}
		
		_button = right._button;
		_buttonState = right._buttonState;
		_click = right._click;
		_positionX = right._positionX;
		_positionY = right._positionY;
		_scroll = right._scroll;
		
		return *this;
	}
	
	Mouse::Button getButton() const { return _button; }
	Mouse::ButtonState getButtonState() const { return _buttonState; }
	Mouse::Click getClick() const { return _click; }
	int getPositionX() const { return _positionX; }
	int getPositionY() const { return _positionY; }
	int getScroll() const { return _scroll; }
	
private:
	Mouse::Button _button;
	Mouse::ButtonState _buttonState;
	Mouse::Click _click;
	int _positionX;
	int _positionY;
	int _scroll;
};

using MouseState_t = struct t_MouseState;

#endif // _MOUSESTATE_HPP_