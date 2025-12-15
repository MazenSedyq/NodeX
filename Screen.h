#include "Game.h"
#include "LevelSetting.h"
#include "Utils.h"

using namespace std;

void run(){
	LevelSetting level;

	while (level.currentLevel != nullptr) {
		Game G(level.currentLevel->height,
			level.currentLevel->width,
			level.currentLevel->numberOfMonsters,
			level.currentLevel->numberOfKeys,
			level.currentLevel->monstersDelay);

		if (G.StartGame()) {
			    level.currentLevel = level.currentLevel->right;
		}
		else {
			    level.currentLevel = level.currentLevel->left;
		}
	}
}

void TypeWriter(const string& text, int speed = 25)
{
	for (char c : text)
	{
		cout << c;
		Sleep(speed);
	}
	cout << endl;
}

void Show_Menu()
{
	system("cls");
	cout << "================================================\n";
	cout << "                       Menu\n";
	cout << "================================================\n";
	cout << "[1] Our amazing Team \n";
	cout << "[2] Start Game\n";
	cout << "[3] Start Exist\n";
	cout << "================================================\n";

}

void PrintTeamNames()
{
	system("cls");

	setColor(11); // Light Blue
	TypeWriter("===== THE FORGOTTEN MAZE : CREDITS =====\n", 40);
	Sleep(600);

	setColor(14); // Yellow
	TypeWriter("Mazen Sedyq           -> The Visionary Leader who guided us through the darkness");
	Sleep(250);

	setColor(10); // Green
	TypeWriter("Ahmed Mohamed         -> The Architect of Secrets, mastering the art of data");
	Sleep(250);

	setColor(9); // Blue
	TypeWriter("Hazem Ashraf          -> The Pillar of Creation who laid the foundation of the maze");
	Sleep(250);

	setColor(13); // Purple
	TypeWriter("Ahmed Alsaieed        -> The Force of Motion who granted the player the power to move");
	Sleep(250);

	setColor(12); // Red
	TypeWriter("Mohammed Abd Elfattah -> The Dark Master who commands the monsters within the maze");
	Sleep(250);

	setColor(6); // Gold
	TypeWriter("Mohammed Al-Desouqy   -> The Overseer who governs the maze and its rules");
	Sleep(250);

	setColor(4); // Dark Red
	TypeWriter("Ahmed Khedr          -> The Lord of Trials who shapes the hardest paths");
	Sleep(250);

	setColor(2); // Dark Green
	TypeWriter("Ahmed Elasid          -> The Silent Savior who carved the hidden exit");
	Sleep(250);

	setColor(11); // Light Blue
	TypeWriter("Ezz Eldien            -> The Voice of Fate who narrates the tale");
	Sleep(250);

	setColor(15); // White
	TypeWriter("Kamal Ahmed           -> The Mad Engineer who built the maze... yet cannot contain it\n", 35);

	setColor(7); // Reset


}

