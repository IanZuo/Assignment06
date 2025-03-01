#ifndef PLAYER_H
#define PLAYER_H

#include "GameEntity.h"

class Player : public GameEntity {
public:
    Player(SDL_Renderer* renderer, const std::string& filePath, float x, float y, float speed);
    
    void Input(float deltaTime) override;  
    void Update(float deltaTime) override; 
};

#endif // PLAYER_H
