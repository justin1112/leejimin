#include <stdio.h>

#include <windows.h>

#include <conio.h>



void gotoxy(int x, int y);



int strlen_s(char i[100]);

int WWBDYW();

int SITE();



void research(int p, int o, char i[100]);

void save(char i[100]);

void Delete();



int main() {



	system("title 브라우저 선택기");

	system("mode 100, 30");



	int a;

	int b;



	char str[100];



	a = WWBDYW();



	system("cls");



	if (a != 3) {



		b = SITE();



		system("cls");



		gotoxy(20, 15);

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

		printf("검색어를 입력해주세요");



		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);



		gotoxy(20, 19);

		gets_s(str);//검색어를 받아줌



		research(a, b, str);



		system("cls");



		printf("완료되었습니다 5초 후 종료됩니다");



		Sleep(5000);

	}



	exit(0);



}



int WWBDYW() {

	int w;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

	gotoxy(20, 15);

	printf("어느 웹브라우저를 선택하시겠습니까?");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

	gotoxy(20, 17);

	printf("1.Chrome\t\t2.Internet Explorer");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

	gotoxy(20, 24);

	printf("검색 기록을 지우고 싶으면 3을 입력하세요^^");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);



	while (1) {



		gotoxy(20, 19);

		printf("                                     ");



		w = _getch();



		switch (w) {

		case '1': w = 1; break;

		case '2': w = 2; break;

		case '3': w = 3; break;

		default: gotoxy(20, 19);

			printf("1 또는 2 또는 3을 입력해주세요");

			Sleep(300);

		}

		if (w == 1 || w == 2 || w == 3) {

			break;

		}

	}



	if (w == 3) {

		Delete();

	}



	return w;

}



int SITE() {

	int x;



	gotoxy(20, 15);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

	printf("어느 사이트를 방문하시겠습니까?");



	gotoxy(20, 17);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

	printf("1.Naver\t\t2.Google\t\t3.youtube");



	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);



	while (1) {



		gotoxy(20, 19);

		printf("                               ");



		x = _getch();



		switch (x) {

		case '1': x = 1; break;

		case '2': x = 2; break;

		case '3': x = 3; break;

		default: gotoxy(20, 19);

			printf("1 또는 2 또는 3 을 입력해주세요");

			Sleep(300);

		}

		if (x == 1 || x == 2 || x == 3) {

			break;

		}

	}



	return x;



}



void research(int p, int o, char i[100]) {

	const char * l;

	const char * k;

	char url[100] = "start";

	int size;



	switch (p) {

	case 1: l = "chrome"; break;

	case 2: l = "iexplore.exe"; break;

	}



	switch (o) {

	case 1: k = "https://search.naver.com/search.naver?query="; break;

	case 2: k = "https://google.com/search?q="; break;

	case 3: k = "https://youtube.com/search?q="; break;

	}



	size = strlen_s(i);



	for (int change = 0; change < size; change++) {

		if (i[change] == ' ') {

			i[change] = '+';

		}

	}

	strcat(url, " ");

	strcat(url, l);

	strcat(url, " ");

	strcat(url, k);

	strcat(url, i);

	system(url);



	save(url);

}



void gotoxy(int x, int y) {

	COORD pos = { x,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}



int strlen_s(char i[100]) {

	int cnt;

	for (cnt = 0; cnt < 100; cnt++) {

		if (i[cnt] == '\0') {

			return cnt;

		}

	}

}



void save(char i[100]) {

	int size;

	size = strlen_s(i);

	FILE * file;

	for (int change = 0; change < size; change++) {

		if (i[change] == '+') {

			i[change] = ' ';

		}

	}

	file = fopen("검색 기록.txt", "a");

	fprintf(file, "%s\n\n", i);

	fclose(file);

}



void Delete() {

	const char * ch;

	ch = "";

	FILE * file;

	file = fopen("검색 기록.txt", "w");

	fprintf(file, "%s", ch);

	fclose(file);

}