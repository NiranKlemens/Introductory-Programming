#include<stdio.h>
#include<stdlib.h>

void drawRoom(int, int, int, int);
void frame(int);
void without_player(int);
void with_player(int, int);
void movement(int position[]);//to declare the user-defined functions at first

int main(void) {
	int position[4] = { 14, 8, 8, 5 };
	drawRoom(position[0], position[1], position[2], position[3]);
	movement(position);

	getchar();
	return 0;
}//the main function


void drawRoom(int total_column, int total_line, int symbol_column, int symbol_line) {
	int i;

	frame(total_column);//to print the first line,also the frame

	for (i = 0;i <= symbol_line - 1; i++) {
		without_player(total_column);
	}//to print the lines above the player's position

	with_player(symbol_column, total_column);//to print the player's line

	for (i = 0;i < total_line - symbol_line - 1;i++) {
		without_player(total_column);
	}//to print the lines below the player's line

	frame(total_column);//to print the last line,also the frame

	printf("\n\n");
}//the user-defined function which is considered to be used for 3 times

void frame(int total_column) {
	printf("+");
	int i;
	for (i = 0;i < total_column;i++) {
		printf("-");
	}
	printf("+\n");
}//to print the first amd the last line,also the frame

void without_player(int total_column) {
	int i;
	printf("|");
	for (i = 0;i < total_column;i++) {
		printf(".");
	}
	printf("|\n");
}//to print the lines without player

void with_player(int symbol_column, int total_column) {
	int i;
	printf("|");
	for (i = 0;i < symbol_column;i++) {
		printf(".");
	}
	printf("@");
	for (i = 0;i < total_column - symbol_column - 1;i++) {
		printf(".");
	}
	printf("|\n");
}//to print the line with the player inside

void movement(int position[]) {
	printf("Print 2,8,4 and 6 in order to represent go upwards,downwards,leftwards and rightwards,\n");
	printf("until you meet the wall\n");
	int direction;
	do {
		scanf("%d", &direction);
		system("cls");
		switch (direction) {
		case 2:
			position[3] -= 1;
			break;
		case 8:
			position[3] += 1;
			break;
		case 4:
			position[2] -= 1;
			break;
		case 6:
			position[2] += 1;
			break;
		default:
			printf("This isn't a correct position.Try again.\n");
		}
		drawRoom(position[0], position[1], position[2], position[3]);
	} while (position[2] != 0 && position[2] != position[0] && position[3] != 0 && position[3] != position[1]);
	system("cls");
	printf("You hit the wall!\n");
	getchar();
	getchar();
}//to implement the movement of the player until it hits the wall
