#include <SDL2/SDL_keycode.h>
#include "Player.h"

Player::Player() {

}

Player::~Player() {

}

void Player::init(float speed, glm::vec2 pos, Celofan::InputManager* inputManager) {
    _inputManager = inputManager;
    _speed = speed;
    _position = pos;
    _color = Celofan::Color(255, 255, 255, 255);
}

void Player::update(const std::vector<std::string>& levelData,
                    std::vector<Human*>& humans,
                    std::vector<Zombie*>& zombies){
    if(_inputManager->isKeyPress(SDLK_w)){
        _position.y +=_speed;
    }else if(_inputManager->isKeyPress(SDLK_s)){
        _position.y -=_speed;
    }
    if(_inputManager->isKeyPress(SDLK_a)){
        _position.x -= _speed;
    }else if(_inputManager->isKeyPress(SDLK_d)){
        _position.x += _speed;
    }
    this->collideWithLevel(levelData);
}