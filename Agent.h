#ifndef ZOMBIEGAME_AGENT_H
#define ZOMBIEGAME_AGENT_H


#include <glm/glm.hpp>
#include <SpriteBatch.h>
#include <Vertex.h>

const int AGENT_WIDTH = 50;

class Human;
class Zombie;

class Agent {
public:
    Agent();
    virtual ~Agent();

    virtual void update(const std::vector<std::string>& levelData, std::vector<Human*>& humans, std::vector<Zombie*>& zombies);

    void collideWithLevel(const std::vector<std::string>& levelData);

    void draw(Celofan::SpriteBatch& spriteBatch);

    glm::vec2 getPosition() const { return _position; }

protected:
    glm::vec2 _position;
    Celofan::Color _color;
    float _speed;
};


#endif //ZOMBIEGAME_AGENT_H
