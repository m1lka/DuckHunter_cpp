#include "mEngine/Core/mCore.hpp"

#include <iostream>

class Game: public Object
{
public:
    Game();

    virtual ~Game();
	
    void Run();

private:
    mCore *_core;
};
