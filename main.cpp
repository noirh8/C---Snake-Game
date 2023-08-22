#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>
#include <ctime>

#include "Snake.h"
#include "Snake.cpp"
#include "Food.h"
#include "Food.cpp"

using namespace std;

#define WIDTH 50
#define HEIGHT 25

Snake snake({WIDTH/2,HEIGHT/2},1);
Food food;
int score;

void board() {
    COORD snake_pos = snake.get_pos();
    COORD food_pos = food.get_pos();

    vector<COORD> snake_body = snake.get_body();

    cout << "SCORE: " << score << "\n\n";

    for(int i=0; i<HEIGHT; i++) {
        cout << "#";
        for(int j=0; j<WIDTH-2; j++) {
            if(i==0 || i==HEIGHT-1) cout << "#";
            else if(i==snake_pos.Y && j+1==snake_pos.X) cout << "0";
            else if(i==food_pos.Y && j+1==food_pos.X) cout << "*";
            else {
                bool isBodyPart = false;
                for(int k=0; k<snake_body.size(); k++) {
                    if(i==snake_body[k].Y && j+1 == snake_body[k].X) {
                        cout << 'o';
                        isBodyPart = true;
                        break;
                    }
                }
                if(!isBodyPart) cout << ' ';
            }
        }
        cout << "#\n";
    }
}


int main() {
    srand(time(NULL));

    score = 0;

    bool game_over = false;
    while(!game_over) {
        
        board();

        if(kbhit()) {
            switch (getch())
            {
            case 72:
                snake.change_dir('u');
                break;
            case 80:
                snake.change_dir('d');
                break;
            case 75:
                snake.change_dir('l');
                break;
            case 77:
                snake.change_dir('r');
                break;
            }
        }

        if(snake.eaten(food.get_pos())) {
            food.gen_food();
            snake.grow();
            score+=1;
        }

        if(snake.isCollided()) {
            game_over = true;
        }

        snake.move_snake();

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
        system("cls");
    }
    if(game_over==true) cout << "GAME OVER\n";
    cout << "Score: " << score << endl;
}
