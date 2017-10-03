#ifndef ZOMBIEGAME_MAINGAME_H
#define ZOMBIEGAME_MAINGAME_H

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <GLSLProgram.h>
#include <Window.h>
#include <Celofan.h>
#include <Camera2D.h>
#include <InputManager.h>
#include <Timing.h>
#include <SpriteBatch.h>
#include "Level.h"
#include "Human.h"
#include "Player.h"
#include "Zombie.h"

enum class GameState{PLAY, EXIT};

class MainGame {
public:
    MainGame();

    ~MainGame();

    void run();

private:
    void initSystems();

    void initShaders();

    void initLevels();

    void gameLoop();

    void processInput();

    void drawGame();

    int getRandomInRange(int min, int max);

    Celofan::Window _window;
    int _screenWidth;
    int _screenHeight;

    Celofan::GLSLProgram _textureProgram;

    Celofan::Camera2D _camera;

    Celofan::InputManager _inputManager;
    Celofan::FPSLimiter _fpsLimiter;

    float _fps;
    float _maxFPS;

    Celofan::SpriteBatch _spriteBatch;

    GameState _gameState;

    std::vector<Level*> _levels;
    int _currentLevel;

    Player* _player;
    std::vector<Human*> _humans;
    std::vector<Zombie*> _zombies;

};


#endif //ZOMBIEGAME_MAINGAME_H
