#include <ResourceManager.h>
#include "Agent.h"

Agent::Agent() {

}

Agent::~Agent() {

}

void Agent::draw(Celofan::SpriteBatch &spriteBatch) {

    static GLuint textureID = Celofan::ResourceManager::glTexture("Textures/oscar101.png").id;
    glm::vec4 destRect = glm::vec4(_position.x, _position.y, AGENT_WIDTH, AGENT_WIDTH);
    glm::vec4 uvRect = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);

    spriteBatch.draw(destRect,
                     uvRect,
                     textureID,
                     0.0f,
                     _color);
}