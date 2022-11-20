#include <windows.h>
#include "HeaderModule.h"
#include <fstream>
using namespace std;

int main()
{
   ifstream task;
   task.open("123.txt");
   int** table;
   table = new int* [20];
   for (int i = 0; i < 20; i++) {
	   table[i] = new int[20];
	   for (int j = 0; j < 20; j++) {
			task >> table[i][j];
	   }
   }
   task.close();

   MainGame(table);
   //PreEvaluation(table, score);
   //MakeMove(table, score);

   task.close();

}



