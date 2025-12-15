#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Screen.h"
using namespace std;

int main()
{
    HideCursor();

    int input;
    do{
        Show_Menu();
        cout << "Enter Your Option : ";
        cin >> input;
        if (input == 1)
        {
            PrintTeamNames();
            system("pause");
        }
        else if (input == 2)
        {
            run();
            system("pause");
        }
        else if (input == 3)
        {
            break;
        }
    } while (input <4 && input>0);

    return 0;
}
