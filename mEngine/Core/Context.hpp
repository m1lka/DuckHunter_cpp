#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#pragma once

#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <memory>

//#include "mEngine/Core/Subsystem.hpp"
class Subsystem;

using std::cerr;
using std::string;
using std::vector;
using std::unordered_map;
using std::unique_ptr;

class Context
{
public:
	Context();
	~Context();
	
	void InitSDLSystem(unsigned flags);
	void SDLQuit();
	
	Subsystem* GetSubsystem(string type) const;
	
	template<typename T>
	T* GetSubsystem() const
	{
		string classType = T::GetTypeInfo();
		auto system = static_cast<T*>(GetSubsystem(classType));
		if(system == nullptr)
		{
			cerr << "GetSubsystem<" << classType << ": Subsystem wasnt registered\n";
			return nullptr;
		}
		
		return system;
	}
	
	template<typename T, typename ...Args>
	T* RegisterSubsystem(Args... args)
	{
        cerr << "Register: " << T::GetTypeInfo() << "\n";
		string classType = T::GetTypeInfo();
		
		auto pSystem = _systems.find(classType);
		if(pSystem != _systems.end())
		{
			cerr << "RegisterSubsystem<" << classType << ": Subsystem was registered\n";
			return nullptr;
		}
		
		unique_ptr<T> upSystem(new T(this, args...));
		_cacheSystems.push_back(std::move(upSystem));
		
		Subsystem* system = _cacheSystems[_cacheSystems.size() - 1].get();
		_systems[classType] = system;
		
		return static_cast<T*>(system);
	}
	
private:
	vector<unique_ptr<Subsystem>> _cacheSystems;
	unordered_map<string, Subsystem*> _systems;
	
    short _sdlInits;
};

#endif
