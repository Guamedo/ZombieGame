#ifndef ZOMBIEGAME_ZOMBIE_H
#define ZOMBIEGAME_ZOMBIE_H

#include <vector>
#include <string>
#include "Agent.h"
#include "Human.h"

class Zombie : public Agent {
public:
    Zombie();
    ~Zombie();
    void init(float speed, glm::vec2 pos);
    void update(const std::vector<std::string>& levelData,
                std::vector<Human*>& humans,
                std::vector<Zombie*>& zombies);
};


#endif //ZOMBIEGAME_ZOMBIE_H
