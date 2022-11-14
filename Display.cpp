#include <windows.h>
#include <iostream>
#include <iomanip>
//SetConsoleOutputCP(1251);

void ShowTable(int(&a)[20][20]) {
	
	//char32_t b = '0';
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			//if (a[i][j] == 1) b = '⛌'; else if (a[i][j] == 2)  b = '⚪'; else b = '_';
			std::cout << std::setw(2) << a[i][j] << ' ';
		}
			
		std::cout << std::endl;
	}
	std :: cout << "\n";
}

void Q(bool k) {
	BOOL WINAPI SetConsoleMode(
		_In_ HANDLE hConsoleHandle,
		_In_ DWORD  dwMode
	);
	std::cout << k;
}

void YouWin() {

}

void YouLoose() {

}