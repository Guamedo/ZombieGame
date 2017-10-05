#ifndef ZOMBIEGAME_HUMAN_H
#define ZOMBIEGAME_HUMAN_H

#include <string>
#include "Agent.h"

class Human : public Agent{
public:
    Human();
    virtual ~Human();
    virtual void update(const std::vector<std::string>& levelData,
                        std::vector<Human*>& humans,
                        std::vector<Zombie*>& zombies);
};


#endif //ZOMBIEGAME_HUMAN_H
