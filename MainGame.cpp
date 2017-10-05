#include <iostream>
#include <sstream>
#include <glm/glm.hpp>
#include <cstdlib>
#include <ctime>
#include "MainGame.h"

MainGame::MainGame() :
        _screenWidth(1024),
        _screenHeight(768),
        _gameState(GameState::PLAY),
        _maxFPS(120.0f),
        _player(nullptr){

    _camera.init(_screenWidth,_screenHeight);

}

MainGame::~MainGame(){
    for(Level* l : _levels){
        delete l;
    }
    for(Human* h : _humans){
        delete h;
    }
    for(Zombie* z : _zombies){
        delete z;
    }
    SDL_Quit();
}

void MainGame::run(){

    initSystems();
    gameLoop();
}

void MainGame::initSystems(){

    srand((unsigned int)time(NULL));

    Celofan::init();

    _window.create("Zombie Game", _screenWidth, _screenHeight, 0);
    glClearColor(0.6f, 0.6f, 0.6f, 1.0f);

    initShaders();

    _spriteBatch.init();

    _fpsLimiter.init(_maxFPS);

    initLevels();

    _player = new Player();
    _player->init(4.0f/(_maxFPS/60), _levels[_currentLevel]->getStartPlayerPos(), &_inputManager);

    _humans.push_back((Human*)_player);

    Zombie* zombie;
    for(auto zombiePos : _levels[_currentLevel]->getStatrtZombiePositions()){
        zombie = new Zombie();
        zombie->init(getRandomInRange(1, 3)/(_maxFPS/60), zombiePos);
        _zombies.push_back(zombie);
    }
}

void MainGame::initShaders() {
    _textureProgram.compileShaders("Shaders/colorShading.vert", "Shaders/colorShading.frag");
    _textureProgram.addAttribute("vertexPosition");
    _textureProgram.addAttribute("vertexColor");
    _textureProgram.addAttribute("vertexUV");
    _textureProgram.linkShaders();
}

void MainGame::initLevels() {
    _levels.push_back(new Level("Levels/level1.txt"));
    _currentLevel = 0;
}

void MainGame::gameLoop(){

    while(_gameState != GameState::EXIT){

        _fpsLimiter.begin();

        processInput();

        // Update the humans position
        for(Human* h : _humans){
            h->update(_levels[_currentLevel]->getLevelData(), _humans, _zombies);
        }

        // Update the zombies position
        for(Zombie* z : _zombies){
            z->update(_levels[_currentLevel]->getLevelData(), _humans, _zombies);
        }

        // Update the camera position to the
        _camera.goToPosition(_player->getPosition());
        _camera.update();

        drawGame();

        _fps = _fpsLimiter.end();

        // Print current FPS as the window title each 10 frames
        static int frameCounter = 0;
        frameCounter++;
        if(frameCounter == 10){
            std::ostringstream ss;
            ss << (int)_fps;
            _window.setWindowTitle("FPS = " + ss.str());
            frameCounter = 0;
        }
    }

}

void MainGame::processInput(){

    SDL_Event evnt{};
    while((bool)SDL_PollEvent(&evnt)){
        switch (evnt.type){
            case SDL_QUIT:
                _gameState = GameState::EXIT;
                break;
            case SDL_MOUSEMOTION:
                _inputManager.setMouseCoords(evnt.motion.x, evnt.motion.y);
                break;
            case (SDL_KEYDOWN):
                _inputManager.pressKey((unsigned int)evnt.key.keysym.sym);
                break;
            case SDL_KEYUP:
                _inputManager.releaseKey((unsigned int)evnt.key.keysym.sym);
                break;
            case SDL_MOUSEBUTTONDOWN:
                _inputManager.pressKey(evnt.button.button);
                break;
            case SDL_MOUSEBUTTONUP:
                _inputManager.releaseKey(evnt.button.button);
                break;
            default:
                break;
        }
    }
}

void MainGame::drawGame(){
    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    _textureProgram.use();

    glActiveTexture(GL_TEXTURE0);
    GLint textureLocation = _textureProgram.getUniformLocation("mySampler");
    glUniform1i(textureLocation, 0);

    GLint pLocation = _textureProgram.getUniformLocation("P");
    glm::mat4 cameraMatrix = _camera.getCameraMatrix();
    glUniformMatrix4fv(pLocation, 1, GL_FALSE, &cameraMatrix[0][0]);

    _levels[_currentLevel]->draw();

    _spriteBatch.begin();

    //Draw all the Humans
    for(Human* h : _humans){
        h->draw(_spriteBatch);
    }

    //Draw all the Zombies
    for(Zombie* z : _zombies){
        z->draw(_spriteBatch);
    }

    _spriteBatch.end();

    _spriteBatch.renderBatch();

    glBindTexture(GL_TEXTURE_2D, 0);
    _textureProgram.unuse();

    _window.swapBuffer();
}

int MainGame::getRandomInRange(int min, int max) {
    return (min + (std::rand() % static_cast<int>(max - min + 1)));
}
