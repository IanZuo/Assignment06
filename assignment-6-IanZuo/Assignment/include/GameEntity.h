#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include <SDL.h>
#include <string>
#include <memory>
#include "Sprite.h"

class GameEntity {
public:
    GameEntity(SDL_Renderer* renderer, const std::string& filePath, float x, float y, float speed);
    virtual ~GameEntity() = default;

    virtual void Input(float deltaTime) {}  // let subclass can cover
    virtual void Update(float deltaTime);   // let subclass cover
    virtual void Render();

    float GetX() const { return mSprite.GetX(); }
    float GetY() const { return mSprite.GetY(); }
    void SetX(float x) { mSprite.SetX(x); }
    void SetY(float y) { mSprite.SetY(y); }

protected:
    Sprite mSprite;
    float mSpeed;
};

#endif // GAME_ENTITY_H
