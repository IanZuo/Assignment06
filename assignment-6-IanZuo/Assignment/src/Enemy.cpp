#include "../include/Enemy.h"

Enemy::Enemy(SDL_Renderer* renderer, const std::string& filePath, float x, float y, float speed)
    : GameEntity(renderer, filePath, x, y, speed), moveDirection(1.0f) {}

void Enemy::Update(float deltaTime) {
    float moveSpeed = 500.0f * deltaTime;  // speed

    SetX(GetX() + moveSpeed * moveDirection);

    // bounce back at edge
    if (GetX() <= 0 || GetX() + 40 >= 800) {
        moveDirection *= -1;  
    }
}
