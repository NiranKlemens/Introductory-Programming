#include<stdio.h>

void drawRoom(int, int, int, int);
void frame(int);
void without_player(int);
void with_player(int, int);//to declare the user-defined functions at first

int main(void){
	drawRoom(2, 2, 0, 1);     
	drawRoom(5, 3, 1, 2);      
	drawRoom(14, 8, 8, 5);

	getchar();      
	return 0;
}//the main function


void drawRoom(int total_column, int total_line, int symbol_column,int symbol_line) {
	int i;

	frame(total_column);//to print the first line,also the frame
	
	for (i= 0;i<= symbol_line-1; i++) {
		without_player(total_column);
	}//to print the lines above the player's position

	with_player(symbol_column,total_column);//to print the player's line

	for (i = 0;i < total_line-symbol_line-1;i++) {
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

void with_player(int symbol_column,int total_column) {
	int i;
	printf("|");
	for (i=0;i< symbol_column;i++) {
		printf(".");
	}
	printf("@");
	for (i = 0;i< total_column - symbol_column - 1;i++) {
		printf(".");
	}
	printf("|\n");
}//to print the line with the player inside
