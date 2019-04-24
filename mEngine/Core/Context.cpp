#include "mEngine/Core/Context.hpp"
#include "mEngine/Core/Subsystem.hpp"
#include <SDL2/SDL.h>

Context::Context()
{
    cerr << "Context::Context()\n";
}

Context::~Context()
{
    cerr << "_sdlInits: " << _sdlInits << "\n";
    _cacheSystems.clear();
    if(_sdlInits > 0)
        cerr << "Warning: SDL was not turned off\n";
}

void Context::InitSDLSystem(unsigned int flags)
{
    cerr << "Init SDL_System\n";
    if(_sdlInits == 0)
    {
        SDL_Init(0);
    }

    unsigned int needInit = flags & ~SDL_WasInit(0);
    SDL_InitSubSystem(needInit);
    ++_sdlInits;
}

void Context::SDLQuit()
{
    if(--_sdlInits == 0)
    {
        SDL_QuitSubSystem(SDL_INIT_EVERYTHING);
        SDL_Quit();
    }
}

Subsystem* Context::GetSubsystem(string type) const
{
	auto system = _systems.find(type);
	if(system == _systems.end())
	{
		return nullptr;
	}
	
	return system->second;
}
