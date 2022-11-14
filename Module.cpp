#include "HeaderDisplay.h"
#include <string>
#include <fstream>
using namespace std;

void MakeMove(int(&a)[20][20], int(&b)[20][20]) {
	int x = 10, y = 10, ma = 0;
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			if (b[i][j] > ma) { x = i; y = j; ma = b[i][j]; }
	a[x][y] = 1;
	ShowTable(b);
	ShowTable(a);
}

int Evaluation(int(&a)[8]) {
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
	
void PreEvaluation (int(&a)[20][20], int(&b)[20][20]) {
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			if (a[i][j] == 0) {
				int mas[4][8];
				for (int e = 0; e < 4; e++)
					for (int q = 0; q < 8; q++)
						mas[e][q] = 0;
				
				for (int q = -4, w = 0; q < 4; q++, w++) {
					int h;
					if (q < 0) h = q; else h = q + 1;
					if (j + h < 0 || j + h >= 20 || i + h < 0 || i + h >= 20) mas[0][w] = 0; else mas[0][w] = a[i][j + h];
					if (j + h < 0 || j + h >= 20 || i + h < 0 || i + h >= 20) mas[1][w] = 0; else mas[1][w] = a[i + h][j + h];
					if (j + h < 0 || j + h >= 20 || i + h < 0 || i + h >= 20) mas[2][w] = 0; else mas[2][w] = a[i + h][j];
					if (j + h < 0 || j + h >= 20 || i - h < 0 || i - h >= 20) mas[3][w] = 0; else mas[3][w] = a[i - h][j + h];
				}	
				
				b[i][j] = Evaluation(mas[0]) + Evaluation(mas[1]) + Evaluation(mas[2]) + Evaluation(mas[3]);
			}
}


bool IsEnd(int(&a)[20][20]) {
	ShowTable(a);
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 16; j++)
			if ((a[i][j] != 0 && a[i][j] == a[i][j + 1] && a[i][j] == a[i][j + 2] && a[i][j] == a[i][j + 3] && a[i][j] == a[i][j + 4]) ||
				(a[j][i] != 0 && a[j][i] == a[j + 1][i] && a[j][i] == a[j + 2][i] && a[j][i] == a[j + 3][i] && a[j][i] == a[j + 4][i])) {
				Q(true);
				return true;
			}

	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			if ((a[i][j] != 0 && a[i][j] == a[i + 1][j + 1] && a[i][j] == a[i + 2][j + 2] && a[i][j] == a[i + 3][j + 3] && a[i][j] == a[i + 4][j + 4])||
				(a[20-i][j] != 0 && a[20 - i][j] == a[20 - i - 1][j + 1] && a[20 - i][j] == a[20 - i - 2][j + 2] && a[20 - i][j] == a[20 - i - 3][j + 3] && a[20 - i][j] == a[20 - i - 4][j + 4])) {
				Q(true);
				return true;
			}	
	Q(false);
	return false;
}

/*void MainGame(int(&a)[20][20]) {

}*/