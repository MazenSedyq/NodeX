#pragma once
#include "Utils.h"

using namespace std;

class Maze;

class Entity
{
    public:
     virtual enEntity GetEntityType(){
     return enEmpty;
     }
     virtual char GetSymbol(){
     return ' ';
     }
     virtual void Print(){
     cout << GetSymbol();
     }

     virtual ~Entity(){}
};

class Key : public Entity
{
    public:
        int x, y;

        Key(int y, int x) : y(y), x(x) {}

        enEntity GetEntityType(){
       return enKey;
       }
       char GetSymbol(){
           return 'K' ;
       }
       void Print(){
       setColor(10);
       Entity::Print();
       setColor(7);
       }

};

class Block : public Entity
{
    public:
       enEntity GetEntityType(){
       return enBlock;
       }
       char GetSymbol(){
         return (char)219;
       }
       void Print(){
       cout << GetSymbol();
       }
};

class Character : public Entity
{
    public:
     int x,y;
     Character(int y,int x){
     this->x = x;
     this->y = y;
     }
};

class Player : public Character
{
    public:
     Player(int y, int x) : Character(y,x) {}

     enEntity GetEntityType(){
     return enPlayer;
     }

     char GetSymbol(){
           return 'P' ;
       }

     void Print(){
       setColor(14);
       Entity::Print();
       setColor(7);
       }

       std::pair<int, int> Get_Direction_Updates(MovementDirection dir);
       enEntity Move(Maze* maze, MovementDirection dir, int Number_Of_Keys);
};

class Monster : public Character
{
    public:
      Monster(int y, int x) : Character(y,x){}

      enEntity GetEntityType(){
      return enMonster;
      }

      char GetSymbol(){
           return 'M' ;
       }

       void Print(){
       setColor(12);
       Entity::Print();
       setColor(7);
       }

       enEntity Move(Maze* maze);
 };



