#include "mEngine/Core/Context.hpp"

Context::Context()
{

}

Context::~Context()
{

}

void Context::InitSDLSystem(unsigned int flags)
{

}

void Context::SDLQuit()
{

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
