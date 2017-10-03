#ifndef ZOMBIEGAME_ZOMBIE_H
#define ZOMBIEGAME_ZOMBIE_H

#include <vector>
#include "Agent.h"
#include "Human.h"

class Zombie : public Agent {
public:
    Zombie();
    ~Zombie();
    void init(float speed, glm::vec2 pos);
    void update(std::vector<Human*> const &humans);
};


#endif //ZOMBIEGAME_ZOMBIE_H
