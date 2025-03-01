#include "../include/Application.h"
#include "../include/ResourceManager.h"
#include <iostream>

Application::Application() : mWindow(nullptr), mRenderer(nullptr), mRun(true) {}

Application::~Application() {
    Shutdown();
}

bool Application::Initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL Init Failed: " << SDL_GetError() << std::endl;
        return false;
    }
    
    mWindow = SDL_CreateWindow("Assignment 05", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
    if (!mWindow || !mRenderer) {
        std::cerr << "Failed to create window or renderer." << std::endl;
        return false;
    }

    auto spaceshipTexture = ResourceManager::GetInstance().LoadTexture(mRenderer, "Assignment/Assets/Spaceship.bmp");
    auto alienTexture = ResourceManager::GetInstance().LoadTexture(mRenderer, "Assignment/Assets/Alien.bmp");

    if (!spaceshipTexture || !alienTexture) {
        std::cerr << "[ERROR] Failed to load textures." << std::endl;
        return false;
    }

    mainCharacter = std::make_unique<Player>(mRenderer, "Assignment/Assets/Spaceship.bmp", 380, 550, 300.0f);

    float startX = 50.0f, startY = 50.0f;
    float spacingX = 60.0f, spacingY = 50.0f;
    
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 12; ++col) {
            float x = startX + col * spacingX;
            float y = startY + row * spacingY;
            mEnemies.push_back(std::make_unique<Enemy>(mRenderer, "Assignment/Assets/Alien.bmp", x, y, 100.0f));
        }
    }
    return true;
}

void Application::Run(int targetFPS) {
    const int frameDelay = 1000 / targetFPS;
    Uint32 frameStart, frameTime;
    Uint32 lastFrameTime = SDL_GetTicks();
    float deltaTime = 0.0f;
    float enemyMoveDirection = 1.0f;

    while (mRun) {
        frameStart = SDL_GetTicks();

        ProcessInput();

        Uint32 currentFrameTime = SDL_GetTicks();
        deltaTime = (currentFrameTime - lastFrameTime) / 1000.0f;
        lastFrameTime = currentFrameTime;
        if (deltaTime > 0.1f) deltaTime = 0.1f;

        if (mainCharacter) {
            mainCharacter->Input(deltaTime);  // let player know input
        }

        Update(deltaTime, enemyMoveDirection);
        Render();

        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < frameDelay) SDL_Delay(frameDelay - frameTime);
    }
}



void Application::ProcessInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            mRun = false;
        }
    }
}

void Application::Update(float deltaTime, float& enemyMoveDirection) {
    // move enemy with every frame
    for (auto& enemy : mEnemies) {
        enemy->Update(deltaTime);
    }

    // player input does not influence enemy
    if (mainCharacter) {
        mainCharacter->Update(deltaTime);
    }
}


void Application::Render() {
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
    SDL_RenderClear(mRenderer);

    if (mainCharacter) mainCharacter->Render();
    for (auto& enemy : mEnemies) {
        enemy->Render();
    }

    SDL_RenderPresent(mRenderer);
}

void Application::Shutdown() {
    std::cout << "[INFO] Shutting down application..." << std::endl;
    
    ResourceManager::GetInstance().Shutdown();

    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
    
    std::cout << "[INFO] Shutdown complete." << std::endl;
}
