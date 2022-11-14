// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>
#include "HeaderModule.h"
#include <fstream>
using namespace std;

int main()
{
   ifstream task;
   task.open("123.txt");
   int table[20][20];
   for (int i = 0; i < 20; i++) {
	   for (int j = 0; j < 20; j++) {
			task >> table[i][j];
	   }
   }
   task.close();

   int score[20][20];          //перенести в Module
   for (int i = 0; i < 20; i++)
	   for (int j = 0; j < 20; j++)
		   score[i][j] = 0;
   
   PreEvaluation(table, score);
   MakeMove(table, score);

   task.close();

   system("pause");

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
