#ifndef ENEMY_H
#define ENEMY_H

#include "GameEntity.h"

class Enemy : public GameEntity {
public:
    Enemy(SDL_Renderer* renderer, const std::string& filePath, float x, float y, float speed);
    void Update(float deltaTime) override;  // move right
private:
    float moveDirection = 1.0f;  // move right at beggining
};

#endif
