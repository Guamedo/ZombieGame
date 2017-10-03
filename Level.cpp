#include "Level.h"

#include <fstream>
#include <Errors.h>
#include <iostream>
#include <Vertex.h>
#include <glm/glm.hpp>

Level::Level(const std::string& fileName) {
    std::fstream file;
    file.open(fileName);
    if(file.fail()){
        Celofan::fatalError("Failde to open: " + fileName);
    }
    std::string temp;
    file >> temp >> _numHumans;

    while (std::getline(file, temp)){
        _levelData.push_back(temp);
    }

    _spriteBatch.init();
    _spriteBatch.begin();

    for(int y = 0; y < _levelData.size(); y++){
        for(int x = 0; x < _levelData[y].size(); x++){
            char tile = _levelData[y][x];
            switch (tile){
                case 'B':
                case 'R':
                    _spriteBatch.draw(glm::vec4(x * ELEMENT_SIZE, y * ELEMENT_SIZE, ELEMENT_SIZE, ELEMENT_SIZE),
                                      glm::vec4(0.0, 0.0, 1.0, 1.0),
                                      Celofan::ResourceManager::glTexture("Textures/red_bricks.png").id,
                                      0.0f,
                                      Celofan::Color(255, 255, 255, 255));
                    break;
                case 'L':
                    _spriteBatch.draw(glm::vec4(x * ELEMENT_SIZE, y * ELEMENT_SIZE, ELEMENT_SIZE, ELEMENT_SIZE),
                                      glm::vec4(0.0, 0.0, 1.0, 1.0),
                                      Celofan::ResourceManager::glTexture("Textures/light_bricks.png").id,
                                      0.0f,
                                      Celofan::Color(255, 255, 255, 255));
                    break;
                case 'G':
                    _spriteBatch.draw(glm::vec4(x * ELEMENT_SIZE, y * ELEMENT_SIZE, ELEMENT_SIZE, ELEMENT_SIZE),
                                      glm::vec4(0.0, 0.0, 1.0, 1.0),
                                      Celofan::ResourceManager::glTexture("Textures/glass.png").id,
                                      0.0f,
                                      Celofan::Color(255, 255, 255, 255));
                    break;
                case '@':
                    _startPlayerPos = glm::ivec2(x * ELEMENT_SIZE, y * ELEMENT_SIZE);
                    break;
                case 'Z':
                    _statrtZombiePositions.emplace_back(x * ELEMENT_SIZE, y * ELEMENT_SIZE);
                    break;
                case '.':
                    break;
                default:
                    std::printf("Unexpected symbol %c at (%d, %d)", tile, x, y);
                    break;
            }
        }
    }

    _spriteBatch.end();
}

Level::~Level() {

}

void Level::draw() {
    _spriteBatch.renderBatch();
}