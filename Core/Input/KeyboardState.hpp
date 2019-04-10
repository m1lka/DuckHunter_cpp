#ifndef _KEYBOARDSTATE_HPP_
#define _KEYBOARDSTATE_HPP_

#include <SDL2/SDL.h>

namespace Key
{
	enum State
	{
		Pressed = 0,
		Released = 1
	};
}

struct t_KeyboardState
{
public:
	t_KeyboardState(
		uint modifier,
		SDL_Scancode key,
		bool repeat,
		Key::State state,
		uint timeStamp,
		Uint32 type
	):
		_modifier(modifier),
		_key(key),
		_repeat(repeat),
		_state(state),
		_timeStamp(timeStamp),
		_type(type) {}
		
	uint getModifier() const { return _modifier; }
	SDL_Scancode getKey() const { return _key; }
	bool getRepeat() const { return _repeat; }
	Key::State getState() const { return _state; }
	uint getTimestamp() const { return _timeStamp; }
	Uint32 getEventType() const { return _type; }
	
	struct t_KeyboardState& operator=(const struct t_KeyboardState& right)
	{
		if(this == &right)
		{
			return *this;
		}
		
		_modifier = right._modifier;
		_key = right._key;
		_repeat = right._repeat;
		_state = right._state;
		_timeStamp = right._timeStamp;
		_type = right._type;
		
		return *this;
	}
	
private:
	uint _modifier;
	SDL_Scancode _key;
	bool _repeat;
	Key::State _state;
	uint _timeStamp;
	Uint32 _type;
};

using KeyboardState_t = struct t_KeyboardState;

#endif // _KEYBOARDSTATE_HPP_