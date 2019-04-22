#include "mEngine/Core/mCore.hpp"

mCore::mCore(Context* context): 
    Object(context),
    _graphics(nullptr)
{
    // = nullptr
}

mCore::~mCore()
{

}

void mCore::Run()
{
    // инициализация компонентов

    _graphics = _context->RegisterSubsystem<Graphics>();
}

void mCore::InitGame()
{
    // настройка компонентов
}

void mCore::ProcessFrame()
{
    // обновление и рендер компонентов
}
