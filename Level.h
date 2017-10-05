#ifndef ZOMBIEGAME_LEVEL_H
#define ZOMBIEGAME_LEVEL_H

#define ELEMENT_SIZE 64

#include <vector>
#include <string>
#include <SpriteBatch.h>
#include <ResourceManager.h>

class Level {
public:
    Level(const std::string& fileName);
    ~Level();

    void draw();

    glm::ivec2 getStartPlayerPos() const { return _startPlayerPos; }

    const std::vector<glm::ivec2> &getStatrtZombiePositions() const { return _statrtZombiePositions; }

    const std::vector<std::string> &getLevelData() const;

private:
    std::vector<std::string> _levelData;
    int _numHumans;
    Celofan::SpriteBatch _spriteBatch;

    glm::ivec2 _startPlayerPos;
    std::vector<glm::ivec2> _statrtZombiePositions;
};


#endif //ZOMBIEGAME_LEVEL_H
