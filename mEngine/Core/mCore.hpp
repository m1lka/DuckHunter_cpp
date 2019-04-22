#ifndef MENGINE_HPP
#define MENGINE_HPP

#include "mEngine/Core/Object.hpp"
#include "mEngine/Graphic/Core/Graphics.hpp"

class mCore: public Object
{
public:
    mCore(Context* context);
	virtual ~mCore();
	
	void Run();
	void InitGame();
	
	void ProcessFrame();
	
private:
	
	// pointer for subsystems
    Graphics* _graphics;
};

#endif // MENGINE_HPP
