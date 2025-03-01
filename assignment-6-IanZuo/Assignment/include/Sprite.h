#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <string>
#include <memory>

class Sprite {
public:
    Sprite(SDL_Renderer* renderer, const std::string& filePath, float x, float y, float speed);
    ~Sprite();

    void Render();

    float GetX() const { return mSprite.x; }
    float GetY() const { return mSprite.y; }
    void SetX(float x) { mSprite.x = x; }
    void SetY(float y) { mSprite.y = y; }

private:
    SDL_FRect mSprite;
    std::shared_ptr<SDL_Texture> mTexture;
    SDL_Renderer* mRenderer;
};

#endif // SPRITE_H

