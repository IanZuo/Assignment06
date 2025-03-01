#include "../include/Sprite.h"
#include "../include/ResourceManager.h"
#include <iostream>

Sprite::Sprite(SDL_Renderer* renderer, const std::string& filePath, float x, float y, float speed)
    : mRenderer(renderer) {
    
    mSprite.x = x;
    mSprite.y = y;
    mSprite.w = 40.0f;
    mSprite.h = 40.0f;

    mTexture = ResourceManager::GetInstance().LoadTexture(renderer, filePath);
    
    if (!mTexture) {
        std::cerr << "[ERROR] Failed to load texture: " << filePath << std::endl;
    }
}

Sprite::~Sprite() {
    //  `mTexture` is `shared_ptr`,no need to manually set
}

void Sprite::Render() {
    if (mTexture) {
        SDL_RenderCopyF(mRenderer, mTexture.get(), nullptr, &mSprite);
    }
}
