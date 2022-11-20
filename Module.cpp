#include "HeaderDisplay.h"
#include <string>
#include <fstream>
using namespace std;

void MakeMove(int** table, int** score) {
	int x = 10, y = 10, ma = 0;
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			if (score[i][j] > ma) { x = i; y = j; ma = score[i][j]; }
	table[x][y] = 1;
}

int FindEvaluation(int(&a)[8]) {
	std::string s = "", n, tmp;
	for (int i = 0; i < 8; i++) {
		char c;
		c = 32;
		switch (a[i])
		{
		case 0:
			c = 48;
			break;
		case 1:
			c = 49;
			break;
		case 2:
			c = 50;
			break;
		}
		s = c + s;
	}
	ifstream file;
	file.open("ai.csv");
	while (!file.eof()) {
		file >> n;
		file >> tmp;
		if (n == s)
			return stoi(tmp);
	}
}
	
void Evaluation (int** table, int** score) {
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			if (table[i][j] == 0) {
				int mas[4][8];
				for (int e = 0; e < 4; e++)
					for (int q = 0; q < 8; q++)
						mas[e][q] = 0;
				
				for (int q = -4, w = 0; q < 4; q++, w++) {
					int h;
					if (q < 0) h = q; else h = q + 1;
					if (j + h < 0 || j + h >= 20 || i + h < 0 || i + h >= 20) mas[0][w] = 0; else mas[0][w] = table[i][j + h];
					if (j + h < 0 || j + h >= 20 || i + h < 0 || i + h >= 20) mas[1][w] = 0; else mas[1][w] = table[i + h][j + h];
					if (j + h < 0 || j + h >= 20 || i + h < 0 || i + h >= 20) mas[2][w] = 0; else mas[2][w] = table[i + h][j];
					if (j + h < 0 || j + h >= 20 || i - h < 0 || i - h >= 20) mas[3][w] = 0; else mas[3][w] = table[i - h][j + h];
				}	
				
				score[i][j] = FindEvaluation(mas[0]) + FindEvaluation(mas[1]) + FindEvaluation(mas[2]) + FindEvaluation(mas[3]);
			}
}


bool IsEnd(int** a, int who) {
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 16; j++)
			if ((a[i][j] == who && a[i][j] == a[i][j + 1] && a[i][j] == a[i][j + 2] && a[i][j] == a[i][j + 3] && a[i][j] == a[i][j + 4]) ||
				(a[j][i] == who && a[j][i] == a[j + 1][i] && a[j][i] == a[j + 2][i] && a[j][i] == a[j + 3][i] && a[j][i] == a[j + 4][i])) {
				return true;
			}

	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			if ((a[i][j] == who && i+1 < 20 && j+1<20 &&  a[i][j] == a[i + 1][j + 1] && a[i][j] == a[i + 2][j + 2] && a[i][j] == a[i + 3][j + 3] && a[i][j] == a[i + 4][j + 4])||
				(a[19-i][j] == who && 19 - i - 4 >= 0 && j + 1 < 20 && a[19 - i][j] == a[19 - i - 1][j + 1] && a[19 - i][j] == a[19 - i - 2][j + 2] && a[19 - i][j] == a[19 - i - 3][j + 3] && a[19 - i][j] == a[19 - i - 4][j + 4])) {
				return true;
			}	
	return false;
}

void MainGame(int** table) {
	InicialisationDisplay(table);
	while (1) {
		int tmp = ShowTable();
		table[tmp / 20][tmp % 20] = 2;
		int** score;
		score = new int* [20];
		for (int i = 0; i < 20; i++) {
			score[i] = new int[20];
			for (int j = 0; j < 20; j++)
				score[i][j] = 0;
		}

		Evaluation(table, score);
		MakeMove(table, score);
		if (IsEnd(table, 1)) {
			YouLoose();
			break;
		}
		else if (IsEnd(table, 2)) {
			YouWin();
			break;
		}
	}
	PostDisplay();
}