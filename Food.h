#ifndef FOOD_H
#define FOOD_H
#define WIDTH 50
#define HEIGHT 25

#include <windows.h>
#include <cstdlib> 

class Food {
private:
    COORD pos;
public:
    Food();
    void gen_food();
    COORD get_pos() {return pos;}
};

#endif
