#pragma once
#include "Snake.h"
Snake::Snake(COORD pos, int vel) {
    this->pos = pos;
    this->vel = vel;
    len = 1;
    direction = 'n';
    body.push_back(pos);
}
void Snake::change_dir(char dir) {
    switch(dir) {
        case 'u':
            if(direction!='d') direction = dir;
            break;
        case 'd':
            if(direction!='u') direction = dir;
            break;
        case 'l':
            if(direction!='r') direction = dir;
            break;
        case 'r':
            if(direction!='l') direction = dir;
            break;
    }
}

void Snake::move_snake()
{
    switch (direction)
    {
    case 'u':
        pos.Y-=vel;
        break;
    case 'd':
        pos.Y+=vel;
        break;
    case 'l': 
        pos.X-=vel;
        break;
    case 'r':
        pos.X+=vel;
        break;
    }

    if(pos.X>=WIDTH-1) pos.X = 0;
    else if (pos.X<1) pos.X = WIDTH-2;
    
    if(pos.Y>=HEIGHT-1) pos.Y=0;
    else if(pos.Y<1) pos.Y = HEIGHT-2;

    body.push_back(pos);
    if(body.size()>len) body.erase(body.begin());
}

COORD Snake::get_pos()
{
    return pos;
}

bool Snake::eaten(COORD food_pos)
{
    if(food_pos.X == pos.X && food_pos.Y == pos.Y) return true;
    else return false;
}

bool Snake::isCollided()
{
    // if(pos.X < 1 || pos.X > WIDTH-2 || pos.Y < 1 || pos.Y > HEIGHT-2) return true;
    for(int i=0; i<len-2; i++) {
        if(pos.X == body[i].X && pos.Y == body[i].Y) return true;
    }
    return false;
}
