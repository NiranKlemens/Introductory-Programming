#include <stdio.h>
#include<stdlib.h>
#include<time.h>
// we MUST specify the size for a 3-D array
// (unless you use pointers)
void print_gameboard(char[3][3]);
int location(int*, int*, char[3][3], int*,int*);
void print_step(char[3][3], int*, int*);
float getRand();
int computer(int);
int check(char[3][3]);
int intelligent(char[3][3],int*);//to declare the self-defined functions first before the main function

int main(void) {
	int counter = 0, row = 0, column = 0, result = 0,similarity=0;
	int *address_row = &row, *address_column = &column, *address_counter = &counter,*address_similarity=&similarity;
	char store[3][3];

	print_gameboard(store);//print out the original gameboard

	do {
		result = location(address_row, address_column, store, address_counter,address_similarity);
		print_step(store, address_row, address_column);
	} while ((result == 1)||(*address_counter!=9));//to loop until you or the computer wins
	
	if (*address_counter == 9) {
		printf("The game end in a draw.\n");
	}//judge whether it is a tie

	getchar();
	getchar();//need two of them because of "scanf"
}


void print_gameboard(char store[3][3]) {
	int i, j;

	for (i = 0;i < 3;i++) {
		for (j = 0;j < 3;j++) {
			store[i][j] = '.';
		}
	}//give value to the array

	for (i = 0;i < 3;i++) {
		for (j = 0;j < 3;j++) {
			printf("%c\t", store[i][j]);
		}
		printf("\n");
	}//print them out
}//the function to print out the original gameboard

int location(int *row, int *column, char store[3][3], int *counter,int*similarity) {
	int number, halt = 0, result = 0,modify=0;

	if (*counter % 2 == 0) {
		printf("write down an integer\n");
		scanf_s("%d", &number);

	}
	else {
		modify=intelligent(store,similarity);
		if (modify == 0) {
			srand(time(NULL));
			getRand();
			number = computer(9);
		}
		else {
			*counter+=1;
		}
	}//let you or the computer to give value to 'number'

	system("cls");//clare the output frame

	if (modify == 0) {
		*row = 2 - (number - 1) / 3;
		*column = (number + 2) % 3;//make calculation in order let a number be corresponding to a square

		if ((store[*row][*column] != 'X') && (store[*row][*column] != 'O')) {
			if (*counter % 2 == 0) {
				store[*row][*column] = 'X';
			}
			else {
				store[*row][*column] = 'O';
			}
			*counter += 1;
		}
		else if (*counter % 2 == 0) {
			printf("The square is occupied.Please choose another number.\n");
		}//renew the storage
	}

	result = check(store);

	return result;//use counter to consider the end of the whole procedure
}

void print_step(char store[3][3], int *row, int *column) {
	int i, j;

	for (i = 0;i < 3;i++) {
		for (j = 0;j < 3;j++) {
			printf("%c\t", store[i][j]);
		}
		printf("\n");
	}
}//the function to print out the latest gameboard

float getRand() {
	return rand() / (RAND_MAX + 1.0);
}// Get a random number from 0 to 0.9999999 

int computer(int multiple) {
	float random_number = getRand();
	int integer1 = random_number * 100;
	float decimal = integer1 / 100.0;

	return decimal * multiple + 1;
}//to get a random positive integer number within 9

int check(char store[3][3]) {
	int i, result = 0;

	for (i = 0; i < 3;i++) {
		if ((store[i][0] == store[i][1]) && (store[i][1] == store[i][2]) && (store[i][2] == 'X')) {
			result = 1;
		}
		else if ((store[i][0] == store[i][1]) && (store[i][1] == store[i][2]) && (store[i][2] == 'O')) {
			result = 2;
		}
		if ((store[0][i] == store[1][i]) && (store[1][i] == store[2][i]) && (store[2][i] == 'X')) {
			result = 1;
		}
		else if ((store[0][i] == store[1][i]) && (store[1][i] == store[2][i]) && (store[2][i] == 'O')) {
			result = 2;
		}
	}//to make horizontal and vertical checks

	if (((store[0][0] == store[1][1]) && (store[1][1] == store[2][2]) && (store[2][2] == 'X')) | ((store[0][2] == store[1][1]) && (store[2][0] == store[1][1]) && (store[1][1] == 'X'))) {
		result = 1;
	}
	else if (((store[0][0] == store[1][1]) && (store[1][1] == store[2][2]) && (store[2][2] == 'O')) | ((store[0][2] == store[1][1]) && (store[2][0] == store[1][1]) && (store[1][1] == 'O'))) {
		result = 2;
	}//to make the diagonal checks

	if (result == 1) {
		printf("You win.\n");
		return 0;
	}
	else if (result == 2) {
		printf("You lose.\n");
		return 0;
	}
	else return 1;
}//to check if someone win the game

int intelligent(char store[3][3],int*pre_similarity) {
	int i, result = 0;
	int similarity=0;

	for (i = 0; i < 3;i++) {
		if ((store[i][1] == 'X') && (store[i][2] == 'X')) {
			store[i][0] = 'O';
			similarity++;
		}
		else if ((store[i][0] == 'X') && (store[i][2] == 'X')) {
			store[i][1] = 'O';
			similarity++;
		}
		else if ((store[i][0] == 'X') && (store[i][1] == 'X')) {
			store[i][2] = 'O';
			similarity++;
		}
	}
	if (similarity == * pre_similarity) {
		for (i = 0; i < 3;i++) {
			if ((store[1][i] == 'X') && (store[2][i] == 'X')) {
				store[0][i] = 'O';
				similarity++;
			}
			else if ((store[0][i] == 'X') && (store[2][i] == 'X')) {
				store[1][i] = 'O';
				similarity++;
			}
			else if ((store[0][i] == 'X') && (store[1][i] == 'X')) {
				store[2][i] = 'O';
				similarity++;
			}
		}
	}
	if (similarity == * pre_similarity) {
		if ((store[1][1] == 'X') && (store[2][2] == 'X')) {
			store[0][0] = 'O';
			similarity++;
		}
		else if ((store[1][1] == 'X') && (store[0][0] == 'X')) {
			store[2][2] = 'O';
			similarity++;
		}
		else if ((store[2][2] == 'X') && (store[0][0] == 'X')){
			store[1][1] = 'O';
			similarity++;
		}
	}
	if (similarity == *pre_similarity) {
		if ((store[1][1] == 'X') && (store[2][0] == 'X')) {
			store[0][2] = 'O';
			similarity++;
		}
		else if ((store[1][1] == 'X') && (store[0][2] == 'X')) {
			store[2][0] = 'O';
			similarity++;
		}
		else if ((store[2][0] == 'X') && (store[0][2] == 'X')) {
			store[1][1] = 'O';
			similarity++;
		}
	}//to avoid that the player win the game

	if (similarity == * pre_similarity) {
		for (i = 0; i < 3;i++) {
			if ((store[i][1] == 'O') && (store[i][2] == 'O')) {
				store[i][0] = 'O';
				result = 1;
			}
			else if ((store[i][0] == 'O') && (store[i][2] == 'O')) {
				store[i][1] = 'O';
				result = 1;
			}
			else if ((store[i][0] == 'O') && (store[i][1] == 'O')) {
				store[i][2] = 'O';
				result = 1;
			}
		}
	}
	if (similarity == * pre_similarity) {
		for (i = 0; i < 3;i++) {
			if ((store[i][1] == 'O') && (store[i][2] == 'O')) {
				store[0][i] = 'O';
				result = 1;
			}
			else if ((store[i][0] == 'O') && (store[i][2] == 'O')) {
				store[1][i] = 'O';
				result = 1;
			}
			else if ((store[i][1] == 'O') && (store[i][0] == 'O')) {
				store[i][2] = 'O';
				result = 1;
			}
		}
	}//to ensure every posibility that computer win the game

	if ((result == 1) || (similarity >* pre_similarity ) ) {
		*pre_similarity = similarity;
		return 1;
	}
	else {
		return 0;
	}
}//for a intelligent game
