#include <ResourceManager.h>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <afxres.h>
#include "Agent.h"
#include "Level.h"

Agent::Agent() {

}

Agent::~Agent() {

}

void Agent::update(const std::vector<std::string>& levelData, std::vector<Human*>& humans, std::vector<Zombie*>& zombies){

}

void Agent::collideWithLevel(const std::vector<std::string> &levelData) {
    std::vector<glm::vec2> collideTilePositions;

    //Check for corners
    glm::vec2 vec = glm::vec2(floorf(_position.x / (float)ELEMENT_SIZE),
                               floorf(_position.y / (float)ELEMENT_SIZE));

    if(levelData[vec.y][vec.x] != '.'){
        collideTilePositions.push_back(vec * (float)ELEMENT_SIZE + glm::vec2((float)ELEMENT_SIZE/ 2.0f));
    }

    vec = glm::vec2(floorf((_position.x + AGENT_WIDTH) / (float)ELEMENT_SIZE),
                    floorf(_position.y / (float)ELEMENT_SIZE));

    if(levelData[vec.y][vec.x] != '.'){
        collideTilePositions.push_back(vec * (float)ELEMENT_SIZE + glm::vec2((float)ELEMENT_SIZE/ 2.0f));
    }

    vec = glm::vec2(floorf(_position.x / (float)ELEMENT_SIZE),
                    floorf((_position.y + AGENT_WIDTH) / (float)ELEMENT_SIZE));

    if(levelData[vec.y][vec.x] != '.'){
        collideTilePositions.push_back(vec * (float)ELEMENT_SIZE + glm::vec2((float)ELEMENT_SIZE/ 2.0f));
    }

    vec = glm::vec2(floorf((_position.x + AGENT_WIDTH) / (float)ELEMENT_SIZE),
                    floorf((_position.y + AGENT_WIDTH) / (float)ELEMENT_SIZE));

    if(levelData[vec.y][vec.x] != '.'){
        collideTilePositions.push_back(vec * (float)ELEMENT_SIZE + glm::vec2((float)ELEMENT_SIZE/ 2.0f));
    }


    glm::vec2 agentCenterPos = _position + (float)AGENT_WIDTH / 2.0f;
    float minDist = (float)ELEMENT_SIZE / 2.0f + (float)AGENT_WIDTH / 2.0f;

    for(glm::vec2 pos : collideTilePositions){

        glm::vec2 distVec = agentCenterPos - pos;

        float xDepth = minDist - fabsf(distVec.x);
        float yDepth = minDist - fabsf(distVec.y);

        if(xDepth > 0 || yDepth > 0){

            if(std::max(xDepth, 0.0f) < std::max(yDepth, 0.0f)){
                if(distVec.x < 0){
                    _position.x -= xDepth;
                }else{
                    _position.x += xDepth;
                }
            }else{
                if(distVec.y < 0){
                    _position.y -= yDepth;
                }else{
                    _position.y += yDepth;
                }
            }
        }
    }
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