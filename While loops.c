#include <stdio.h>
#include<stdlib.h>
#include<time.h>//extra includes to open new files

float getRand() {
	return rand() / (RAND_MAX + 1.0);
}// Get a random number from 0 to 0.9999999 

int rollDie(int multiple) {
	float random_number = getRand();
	int integer1 = random_number * 100;
	float decimal = integer1 / 100.0;
	return decimal * multiple + 1;//to get a random positive integer number within 32
}

int comparison(int correct_answer) {
	int guess,number=0;
	do {
		printf("Please guess an integer within 32.\n");
		scanf("%d", &guess);
		if (guess == correct_answer) {
			printf("correct\n");
		}
		else if (guess > correct_answer) {
			printf("too high\n");
			}else printf("too low\n");
		number++;
	} while (guess != correct_answer);
	printf("It takes %d guesses for you to win.\n",number);
	return number;
}//this is the process in each game


int main(void) {
	srand(time(NULL));
	getRand();

	int number = comparison(rollDie(32));
	int fewest_number = number;

	while (fewest_number > 4) {
		number = comparison(rollDie(32));
		if (number <= fewest_number)
			fewest_number = number;
		printf("The fewest number of guesses is %d.\n", fewest_number);
	}
	printf("You make it to guess with 4 or fewer times.\n ");

	getchar();
	getchar();
}//the main process,to make loops until the player guess less or equaling to 4 times
