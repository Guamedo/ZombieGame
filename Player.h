#ifndef ZOMBIEGAME_PLAYER_H
#define ZOMBIEGAME_PLAYER_H

#include <InputManager.h>
#include "Human.h"

class Player : public Human {
public:
    Player();
    ~Player() override;

    void init(float speed, glm::vec2 pos, Celofan::InputManager* inputManager);

    void update() override;

private:
    Celofan::InputManager* _inputManager;

};

#endif //ZOMBIEGAME_PLAYER_H
