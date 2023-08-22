#pragma once
#include "Food.h"

Food::Food() {
    gen_food();
}
void Food::gen_food() {
    pos.X = 1 + rand() % (WIDTH-2);
    pos.Y = 1 + rand() % (HEIGHT-2);

}
