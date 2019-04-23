#include "mEngine/Core/mCore.hpp"

mCore::mCore(Context* context): 
    Object(context),
    _graphics(nullptr),
    run(true)
{
    // = nullptr
}

mCore::~mCore()
{
    _context->SDLQuit();
}

void mCore::Run()
{
    // инициализация компонентов

    _context->InitSDLSystem(SDL_INIT_VIDEO);

    _graphics = _context->RegisterSubsystem<Graphics>();

    _graphics->SetVideoMode("Test", 500, 500, SDL_WINDOW_SHOWN);
}

void mCore::InitGame()
{
    // настройка компонентов
}

void mCore::ProcessFrame()
{
    // обновление и рендер компонентов
    SDL_Event event;
    while(SDL_PollEvent(&event) == 1)
    {
        if(event.type == SDL_QUIT)
        {
            DoExit();
        }
    }
}

bool mCore::IsRunning() const
{
    return run;
}

void mCore::DoExit()
{
    run = false;
}
