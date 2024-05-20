#ifndef STATE_HPP
#define STATE_HPP

class State
{
public:
    virtual void handleInput() = 0;
    virtual void update(float dt) = 0;
    virtual void draw() = 0;
};

#endif // STATE_HPP