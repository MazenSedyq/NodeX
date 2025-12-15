#pragma once
#include "Entity.h"
#include "Utils.h"
//Maze logic
using namespace std;

class Maze
{
	void InitializeMaze()
	{
		for (int i = 0; i < Height; i++)
		{
			for (int j = 0; j < Width; j++)
			{
					grid[i][j] = new Block();
			}
		}
	}
	void CarveExist()
	{
		Vector<pair<int, int>>ValidExist;
		//up side
			for (int j = 0; j < Width; j++)
			{
				if (grid[1][j]->GetEntityType() == enEmpty)
					ValidExist.push_back({ 0,j });
			}
			//down side
			for (int j = 0; j < Width; j++)
			{
				if (grid[Height-2][j]->GetEntityType() == enEmpty)
					ValidExist.push_back({ Height-1,j });
			}
			//Left side
			for (int j = 0; j < Height; j++)
			{
				if (grid[j][1]->GetEntityType() == enEmpty)
					ValidExist.push_back({ j,0 });
			}
			//Right side
			for (int j = 0; j < Height; j++)
			{
				if (grid[j][Width - 2]->GetEntityType() == enEmpty)
					ValidExist.push_back({ j,Width - 1 });
			}
			Exist = ValidExist[rand() % ValidExist.size()];

	}
	void Generate_maze(int stx, int sty)
	{
		delete grid[sty][stx];
		grid[sty][stx] = new Entity();
		bool Visited[100][100] = { false };

		Stack<pair<int, int>>cells;
		//          down-up-right-left
		int dx[4] = { 0,0,2,-2 };
		int dy[4] = { 2,-2,0,0 };
		cells.push({ stx,sty });
		Visited[sty][stx] = true;
		while (!cells.empty())
		{

			int x = cells.top().first;
			int y = cells.top().second;

			vector<int>ValidDirections;
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx > 0 && ny > 0 && ny < Height - 1 && nx < Width - 1 && !Visited[ny][nx])
				{
					ValidDirections.push_back(i);
				}
			}
			if (!ValidDirections.empty())
			{
				int dir = ValidDirections[rand() % ValidDirections.size()];
				int Next_x = x + dx[dir];
				int Next_y = y + dy[dir];
				/*delete grid[Next_y][Next_x];
				delete grid[y + dy[dir] / 2][x + dx[dir] / 2];*/

				grid[Next_y][Next_x] = new Entity();
				grid[y + dy[dir] / 2][x + dx[dir] / 2] = new Entity();
				Visited[Next_y][Next_x] = true;
				cells.push({ Next_x, Next_y });
			}
			else {
				cells.pop();
			}
		}
	}

public :
	Entity *grid[100][100];
	int Height;
	int Width;
	int stx = 1;
	int sty = 1;
	pair<int, int>Exist;

	Maze(int height, int width):grid{nullptr}
	{
		srand(time(0));
		Height = height;
		Width = width;
		InitializeMaze();
		Generate_maze(stx,sty);
		CarveExist();
	}

	void Draw_Maze()
	{

		for (int i = 0; i < Height; i++)
		{
			for (int j = 0; j < Width; j++)
			{
				if (i == Exist.first && j == Exist.second)
				{
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, 2);
					cout << (char)178;
					SetConsoleTextAttribute(hConsole, 7);
				}
				else
				{
					grid[i][j]->Print();
				}


			}
			cout << "\n";
		}

	}

	Vector<pair<int,int>>GetEmptyCells()
	{
		Vector<pair<int, int>>EmptyCells;
		for (int i = 0; i < Height; i++)
		{
			for (int j = 0; j < Width; j++)
			{

				if (grid[i][j]->GetEntityType() == enEmpty&&make_pair(i,j)!=Exist)
				{
					EmptyCells.push_back({ i,j });
				}

			}
		}
		return EmptyCells;
	}

};
