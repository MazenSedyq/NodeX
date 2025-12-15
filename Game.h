#include "random"
#include <conio.h>
#include "Entity.h"
#include "Maze.h"
#include "windows.h"
#include "Move.h"
#include "Utils.h"

//Game Engine
using namespace std;

class Game {
Vector<Monster*> monsters;
Vector<Key*> keys;
int numberOfMonsters;
int numberOfKeys;
Maze *maze;
Player *player;
int delay ;

public:
    Game(int Height, int Width, int NumberOfMonsters, int NumberOfKeys, int MonstersDelay){
        numberOfMonsters = NumberOfMonsters;
        numberOfKeys = NumberOfKeys;
        delay = MonstersDelay;
        maze =new Maze(Height,Width);
        GenerateEntities(numberOfKeys,numberOfMonsters);
    }

    bool StartGame() {
        int count = 0;
        system("cls");
        maze->Draw_Maze();

        while(true){
          if (_kbhit()){
              int ch = _getch();
              MovementDirection dir = static_cast<MovementDirection>(ch);
              enEntity nextCell = player->Move(maze, dir, numberOfKeys);
              if (nextCell == enMonster)
                    return false;
              else if (nextCell == enKey)
                numberOfKeys--;
              if(numberOfKeys < 1 && player->x == maze->Exist.second && player->y == maze->Exist.first)
                    return true;
          }

          if(count >=delay){
                count =0;
                enEntity check;
                for(int i = 0;i<numberOfMonsters;i++){
                        check = monsters[i]->Move(maze);
                        if(check == enEntity::enPlayer)
                           return false;
                }
          }
          count++;
          Sleep(30);
        }
}

private:

    void GenerateEntities(int numKeys, int numMonsters){
        Vector<pair<int, int>> emptyCells = maze->GetEmptyCells();

        auto getRandomCell = [&](){
            int index = rand() %emptyCells.size();
            pair<int, int> cell = emptyCells[index];
            emptyCells.erase(index);
            return cell;
        };

        pair<int, int> pPos = getRandomCell();
        player = new Player(pPos.first, pPos.second);
        maze->grid[pPos.first][pPos.second] = player;

        for(int i =0; i < numKeys ; i++){
                pair<int, int> kPos = getRandomCell();
                keys.push_back(new Key(kPos.first, kPos.second)) ;
                maze->grid[kPos.first][kPos.second] = keys[i];
        }

        for(int i = 0; i < numMonsters ; i++){
            pair<int, int> mPos = getRandomCell();
            monsters.push_back(new Monster(mPos.first, mPos.second)) ;
            maze->grid[mPos.first][mPos.second] = monsters[i];
        }
    }


};





