#ifndef APPLICATION_H
#define APPLICATION_H

#include <SDL.h>
#include <vector>
#include <memory>
#include "Player.h"
#include "Enemy.h"

class Application {
public:
    Application();
    ~Application();
    bool Initialize();
    void Run(int targetFPS);
    void Shutdown();

private:
    void ProcessInput();
    void Update(float deltaTime, float& enemyMoveDirection);
    void Render();

    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;
    bool mRun;

    std::unique_ptr<Player> mainCharacter;
    std::vector<std::unique_ptr<Enemy>> mEnemies;
};

#endif // APPLICATION_H
