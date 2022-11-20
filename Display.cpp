#include <windows.h>
#include <iostream>
#include "curses.h"
#include <stdio.h>
#include <string>  
using namespace std;
//SetConsoleOutputCP(1251);

#define WIDTH 43
#define HEIGHT 24 
WINDOW* menu_win;

int startx = 0;
int starty = 0;
int** table;
int highlight = 0;


void print_menu(WINDOW* menu_win)
{
	int x, y, i, j;
	//char buf[20];

	x = 2;
	y = 2;
	box(menu_win, 0, 0);
	for (i = 0; i < 20; ++i)
	{
		for (j = 0; j < 20; ++j)
		{
			char ch[2]; ch[1] = 0;
			if (table[i][j] == 0)
				ch[0] = '.';
			else if (table[i][j] == 1)
				ch[0] = 'X';
			else if (table[i][j] == 2)
				ch[0] = 'O';
			else ch[0] = '-';
			//sprintf_s(buf, "%i", table[i][j]);
			if (highlight == i*20 + j)
			{
				wattron(menu_win, A_REVERSE);
				mvwprintw(menu_win, y, x+j*2, "%s", /*buf*/ch);
				wattroff(menu_win, A_REVERSE);
			}
			else
				mvwprintw(menu_win, y, x+j*2, "%s", ch);
			
		}
		++y;
	}
	wrefresh(menu_win);
}


int ShowTable() {

	int choice = -1;
	int c;
	mvprintw(0, 0, "Use arrow keys to go up and down, press enter to select a cell. The task is to collect 5 in a row.");
	refresh();
	print_menu(menu_win);
	while (1)
	{
		c = wgetch(menu_win);
		clrtoeol();
		switch (c)
		{
		case KEY_UP:
			if (highlight <= 19)
				highlight += 380;
			else
				highlight -= 20;
			break;
		case KEY_DOWN:
			if (highlight > 379)
				highlight = 380-highlight;
			else
				highlight += 20;
			break;
		case KEY_RIGHT:
			if (highlight % 20 == 19)
				highlight -= 19;
			else
				highlight += 1;
			break;
		case KEY_LEFT:
			if (highlight % 20 == 0)
				highlight += 19;
			else
				highlight -= 1;
			break;
		case 10:
			if (table[highlight/20][highlight%20] == 0)
				choice = highlight;
			break;
		default:
			break;
		}
		print_menu(menu_win);
		if (choice != -1)	/* User did a choice come out of the infinite loop */
			break;
	}
	//mvprintw(23, 0, "AAA", choice, table[highlight / 20][highlight % 20]);
	clrtoeol();
	refresh();
	return highlight;

	/*//char32_t b = '0';
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			//if (a[i][j] == 1) b = '⛌'; else if (a[i][j] == 2)  b = '⚪'; else b = '_';
			printw("%d", a[i][j]);
			printw(" ");
		}

		printw("\n");
	}
}

/*#define KEY_DOWN      0x102   Down arrow key
#define KEY_UP        0x103   Up arrow key
#define KEY_LEFT      0x104   Left arrow key
#define KEY_RIGHT     0x105  Right arrow key
#define KEY_ENTER     0x157  /* enter or send (unreliable)

const char* choices[] = {
			"Choice 1",
			"Choice 2",
			"Choice 3",
			"Choice 4",
			"Exit",
};

int n_choices = sizeof(choices) / sizeof(char*);
*/
}


void Q(bool k) {
}

void YouWin() {
	clear();
	mvprintw(0, 0, "  _   _    ___    _   _");
	mvprintw(1, 0, " | \\_/ |  / _ \\  | | | |");
	mvprintw(2, 0, " \\     / / / \\ \\ | | | |");
	mvprintw(3, 0, "  \\   /  | | | | | | | |");
	mvprintw(4, 0, "   | |   | | | | | |_| |	");
	mvprintw(5, 0, "   | |   \\ \\_/ / |     |");
	mvprintw(6, 0, "   |_|    \\___/  \\_____|");
	mvprintw(7, 0, " _  _  _    ___    _____");
	mvprintw(8, 0, "| || || |  / _ \\  |     \\");
	mvprintw(9, 0, "| || || | / / \\ \\ |  _  |");
	mvprintw(10, 0, "| || || | | | | | | | | |");
	mvprintw(11, 0, "| || || | | | | | | | | |");
	mvprintw(12, 0, "\\       / \\ \\_/ / | | | |");
	mvprintw(13, 0, " \\_____/   \\___/  |_| |_|");
	refresh();
	getch();
}

void YouLoose() {
	clear();
	mvprintw(0, 0,  "  ____    _____     _____     _____");
	mvprintw(1, 0,  " /  __/  /  _  \\   /     \\   /  _  \\");
	mvprintw(2, 0,  "/  /     | |_| |  /       \\ /  | |  \\");
	mvprintw(3, 0,  "| /   _  |  _  |  | || || | |  _____|");
	mvprintw(4, 0,  "| \\  / \\ | | | |  | || || | |  \\____");
	mvprintw(5, 0,  "\\  \\_/ | | | | |  | || || | \\       \\");
	mvprintw(6, 0,  " \\_____/ |_| |_|  |_||_||_|  \\______/");
	mvprintw(7, 0,  "    ___    _   _    _____    _____ ");
	mvprintw(8, 0,  "   / _ \\  | | | |  /  _  \\  /  _  \\");
	mvprintw(9, 0,  "  / / \\ \\ | | | | /  | |  \\ | |_| |");
	mvprintw(10, 0, "  | | | | | | | | |  _____| |  _  /");
	mvprintw(11, 0, "  | | | | | \\_/ | |  \\____  | | \\ \\");
	mvprintw(12, 0, "  \\ \\_/ / \\     / \\       \\ | | | |");
	mvprintw(13, 0, "   \\___/   \\___/   \\______/ |_| |_|");
	refresh();
	getch();
}

void InicialisationDisplay(int** a) {

	initscr();
	clear();
	noecho();
	cbreak();	/* Line buffering disabled. pass on everything */
	startx = (60 - WIDTH) / 2;
	starty = (30 - HEIGHT) / 2;
	menu_win = newwin(HEIGHT, WIDTH, starty, startx);
	keypad(menu_win, TRUE);
	table = a;
}

void PostDisplay() {
	endwin();
}

