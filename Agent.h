#ifndef ZOMBIEGAME_AGENT_H
#define ZOMBIEGAME_AGENT_H


#include <glm/glm.hpp>
#include <SpriteBatch.h>
#include <Vertex.h>

const float AGENT_WIDTH = 50;

class Agent {
public:
    Agent();
    virtual ~Agent();

    void draw(Celofan::SpriteBatch& spriteBatch);

    glm::vec2 getPosition() const { return _position; }

protected:
    glm::vec2 _position;
    Celofan::Color _color;
    float _speed;
};


#endif //ZOMBIEGAME_AGENT_H
