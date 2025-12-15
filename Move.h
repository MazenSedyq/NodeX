#pragma once
#include "Entity.h"
#include "Utils.h"
#include "Maze.h"

using namespace std;

pair<int, int> Player::Get_Direction_Updates(MovementDirection dir) {
	switch (dir)
	{

	case E_up:
		return make_pair(-1, 0);

	case E_down:
		return make_pair(1, 0);

	case E_right:
		return make_pair(0, 1);

	case E_left:
		return make_pair(0, -1);
	}

	return make_pair(0, 0);
}

enEntity Player::Move(Maze* maze, MovementDirection dir, int Number_Of_Keys) {
	pair<int, int> Position_Updates = Get_Direction_Updates(dir);

	int newY = y + Position_Updates.first;
	int newX = x + Position_Updates.second;
	enEntity Next_Cell = maze->grid[newY][newX]->GetEntityType();
		if ((make_pair(newY, newX) == maze->Exist && Number_Of_Keys == 0) || (Next_Cell != enBlock))
		{
			if (Next_Cell == enEntity::enMonster)
			{
				return enEntity::enMonster;
			}

            SetCursor(x,y);
			maze->grid[y][x] = new Entity();
			maze->grid[y][x]->Print();

			SetCursor(newX,newY);
			maze->grid[newY][newX] = this;
			maze->grid[newY][newX]->Print();

			y = newY;
			x = newX;
		}
	return Next_Cell;
}


enEntity Monster::Move(Maze* maze){
        pair<int, int>* validMoves = new std::pair<int, int>[4];
        int moveCount = 0;

        // UP
        if (maze->grid[y - 1][x]->GetEntityType() != enBlock &&
            maze->grid[y - 1][x]->GetEntityType() != enMonster)
        {
            if (maze->grid[y - 1][x]->GetEntityType() == enKey &&
                maze->grid[y - 2][x]->GetEntityType() != enBlock &&
                maze->grid[y - 2][x]->GetEntityType() != enMonster)
            {
                validMoves[moveCount++] = { x, y - 2 }; // move two steps
            }
            else
            {
                validMoves[moveCount++] = { x, y - 1 };// move one step
            }
        }

        //  DOWN
        if (maze->grid[y + 1][x]->GetEntityType() != enBlock &&
            maze->grid[y + 1][x]->GetEntityType() != enMonster)
        {
            if (maze->grid[y + 1][x]->GetEntityType() == enKey &&
                maze->grid[y + 2][x]->GetEntityType() != enBlock &&
                maze->grid[y + 2][x]->GetEntityType() != enMonster)
            {
                validMoves[moveCount++] = { x, y + 2 };
            }
            else
            {
                validMoves[moveCount++] = { x, y + 1 };
            }
        }

        //  RIGHT
        if (maze->grid[y][x + 1]->GetEntityType() != enBlock &&
            maze->grid[y][x + 1]->GetEntityType() != enMonster)
        {
            if (maze->grid[y][x + 1]->GetEntityType() == enKey &&
                maze->grid[y][x + 2]->GetEntityType() != enBlock &&
                maze->grid[y][x + 2]->GetEntityType() != enMonster)
            {
                validMoves[moveCount++] = { x + 2, y };
            }
            else
            {
                validMoves[moveCount++] = { x + 1, y };
            }
        }

        //  LEFT
        if (maze->grid[y][x - 1]->GetEntityType() != enBlock &&
            maze->grid[y][x - 1]->GetEntityType() != enMonster)
        {
            if (maze->grid[y][x - 1]->GetEntityType() == enKey &&
                maze->grid[y][x - 2]->GetEntityType() != enBlock &&
                maze->grid[y][x - 2]->GetEntityType() != enMonster)
            {
                validMoves[moveCount++] = { x - 2, y };
            }
            else
            {
                validMoves[moveCount++] = { x - 1, y };
            }
        }

        //  NO MOVES
        if (moveCount == 0)
        {
            delete[] validMoves;
            return enEmpty;
        }

        int index = rand() % moveCount;
        int newX = validMoves[index].first;
        int newY = validMoves[index].second;

        delete[] validMoves;

        enEntity result = maze->grid[newY][newX]->GetEntityType();

        if (result !=  enKey){
        SetCursor(x,y);
        maze->grid[y][x] = new Entity();
        maze->grid[y][x]->Print();

        SetCursor(newX,newY);
        maze->grid[newY][newX] = this;
        maze->grid[newY][newX]->Print();

        x = newX;
        y = newY;

        }
        return result;
    }

