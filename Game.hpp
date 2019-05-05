#include <iostream>
#include "mEngine/Graphic/Core/Window.hpp"

class Game
{
public:
    Game();

    ~Game();
	
	Window _window;
	bool run;
	
    void Run();
};
