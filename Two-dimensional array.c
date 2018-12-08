#include <stdio.h>
#include<stdlib.h>
// we MUST specify the size for a 3-D array
// (unless you use pointers)
void print_gameboard(char[3][3]);
int location(int*, int*, char[3][3], int);
void print_step(char[3][3], int*, int*);//to declare the self-defined functions first before the main function

int main(void) {
	int counter = 0, row = 0, column = 0;
	int *address_row = &row, *address_column = &column;
	char store[3][3];

	print_gameboard(store);

	do {
		counter=location(address_row, address_column, store, counter);
		print_step(store, address_row, address_column);
	} while (counter != 9);//to loop until the squares are filled

	printf("All squares are filled.");
	
	getchar();
	getchar();//need two of them because of "scanf"
}


void print_gameboard(char store[3][3]) {
	int i, j;

	for (i = 0;i < 3;i++) {
		for (j = 0;j < 3;j++) {
			store[i][j] = '.';
		}
	}

	for (i = 0;i < 3;i++) {
		for (j = 0;j < 3;j++) {
			printf("%c\t", store[i][j]);
		}
		printf("\n");
	}
}//the function to print out the original gameboard

int location(int *row, int *column, char store[3][3], int counter) {
	int number;

	printf("write down an integer\n");
	scanf_s("%d", &number);

	system("cls");

	*row = 2-(number-1)/3;
	*column = (number+2)%3;//make calculation in order let a number be corresponding to a square

	if (store[*row][*column] != 'X') {
		store[*row][*column] = 'X';
		counter++;
	}
	else {
		printf("The square is occupied.Please choose another number.\n");
	}//renew the storage

	return counter;//use counter to consider the end of the whole procedure
}

void print_step(char store[3][3], int *row, int *column) {
	int i, j;

	for (i = 0;i < 3;i++) {
		for (j = 0;j < 3;j++) {
			if ((store[i][j] != 'X') | (store[i][j] != 'X')) {
				printf(".\t");
			}
			else {
				printf("X\t");
			}
		}
		printf("\n");
	}
}//the function to print out the latest gameboard
