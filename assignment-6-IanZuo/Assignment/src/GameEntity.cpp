#include "../include/GameEntity.h"

GameEntity::GameEntity(SDL_Renderer* renderer, const std::string& filePath, float x, float y, float speed)
    : mSprite(renderer, filePath, x, y, speed), mSpeed(speed) {}

void GameEntity::Update(float deltaTime) {
    // default
    // let subclass use
}

void GameEntity::Render() {
    mSprite.Render();
}
