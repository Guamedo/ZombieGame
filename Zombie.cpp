#include "Zombie.h"

Zombie::Zombie() {

}

Zombie::~Zombie() {

}

void Zombie::init(float speed, glm::vec2 pos) {
    _speed = speed;
    _position = pos;
    _color = Celofan::Color(0, 128, 0, 255);
}

void Zombie::update(std::vector<Human *> const &humans) {
    int index = 0;
    float min = powf(humans[0]->getPosition().x - _position.x, 2) + powf(humans[0]->getPosition().y - _position.y, 2);
    for(int i = 1; i < humans.size(); i++){
        if(powf(humans[i]->getPosition().x - _position.x, 2) + powf(humans[i]->getPosition().y - _position.y, 2) < min){
            min = powf(humans[i]->getPosition().x - _position.x, 2) + powf(humans[i]->getPosition().y - _position.y, 2);
            index = i;
        }
    }
    glm::vec2 dir = humans[index]->getPosition() - _position;
    dir = glm::normalize(dir);
    _position += dir * _speed;
}