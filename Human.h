#ifndef ZOMBIEGAME_HUMAN_H
#define ZOMBIEGAME_HUMAN_H

#include "Agent.h"

class Human : public Agent{
public:
    Human();
    virtual ~Human();
    virtual void update();
};


#endif //ZOMBIEGAME_HUMAN_H
