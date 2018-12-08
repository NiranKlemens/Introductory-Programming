#include <stdio.h>
#include<stdlib.h>
#include<time.h>//extra includes to open new files

float getRand() {
	return rand() / (RAND_MAX + 1.0);
}// Get a random number from 0 to 0.9999999 

int rollDie(int multiple) {
	float random_number = getRand();
	return random_number * multiple;//to get a random positive integer number within 128
}

void comparison(int correct_answer) {
	int guess, number = 0;
	do {
		printf("Please guess an integer between 32 and 156,which is the integral multiple of 4.\n");
		scanf("%d", &guess);
		if (guess == correct_answer) {
			printf("correct\n");
		}
		else if (guess > correct_answer) {
			printf("too high\n");
		}
		else printf("too low\n");
		number++;
	} while (guess != correct_answer);
	printf("It takes %d guesses for you to win.\n", number);
}//the comparison process


int main(void) {
	int correct_answer;
	do {
		srand(time(NULL));
		getRand();
		correct_answer = 28 + rollDie(128);
	} while (correct_answer % 4 != 0);//to get a number between 32 and 156,which is also the integral multiple of 4

	comparison(correct_answer);

	getchar();
	getchar();
}
