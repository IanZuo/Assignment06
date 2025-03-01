#include "../include/Player.h"
#include <SDL.h>

Player::Player(SDL_Renderer* renderer, const std::string& filePath, float x, float y, float speed)
    : GameEntity(renderer, filePath, x, y, speed) {}

void Player::Input(float deltaTime) {
    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    float moveSpeed = 300.0f * deltaTime;

    if (keystates[SDL_SCANCODE_LEFT] || keystates[SDL_SCANCODE_A]) {
        SetX(GetX() - moveSpeed);
    }
    if (keystates[SDL_SCANCODE_RIGHT] || keystates[SDL_SCANCODE_D]) {
        SetX(GetX() + moveSpeed);
    }

    // spaceship not run out of edge
    if (GetX() < 0) SetX(0);
    if (GetX() + 40 > 800) SetX(800 - 40);
}

void Player::Update(float deltaTime) {
    GameEntity::Update(deltaTime);  // use `GameEntity::Update()` inherit 
}
