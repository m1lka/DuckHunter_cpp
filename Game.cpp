#include "Game.hpp"
#include "mEngine/Core/Context.hpp"

Game::Game():
    Object(new Context())
{
    cerr << "Start Game::Game()\n";
    _core = new mCore(_context);
    cerr << "Stop Game::Game()\n";
}

Game::~Game()
{
    delete _context;
    delete _core;
}

void Game::Run()
{
    _core->Run();
    _core->InitGame();

    while(_core->IsRunning())
        _core->ProcessFrame();
}
