#include "Game.hpp"

#ifdef _WIN32
#include <windows.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
#else
#ifdef _LINUX
int main()
#endif // #ifdef _LINUX
#endif // else
{
    Game g;
	g.Run();
    return 0;
}
