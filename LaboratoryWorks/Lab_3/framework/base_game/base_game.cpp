#include "base_game.h"

BaseGame::BaseGame() : 
window(new Window(
        "Game", 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 
        DEFAULT_WINDOW_WIDTH, 
        DEFAULT_WINDOW_HEIGHT, 
        WINDOW_FLAGS
    )
) {}
    
float BaseGame::getWidth() const {  
    return window->getWidth();
}

float BaseGame::getHeight() const { 
    return window->getHeight();
}

SDL_Renderer* BaseGame::getRenderer() const {
    return window->getRenderer();
}

bool BaseGame::isRunning() const {
    return running;
}

void BaseGame::quit() {
    running = false;
}

BaseGame::~BaseGame() {}