#include "mEngine/Core/mCore.hpp"

#include <iostream>

class Game: public Object
{
public:
    Game():
        Object(new Context())
	{
        _core = new mCore(_context);
	}

    virtual ~Game()
    {
        delete _context;
        delete _core;
    }
	
	void Run()
	{
        while(_core->IsRunning())
            _core->ProcessFrame();
	}	

private:
    mCore *_core;
};
