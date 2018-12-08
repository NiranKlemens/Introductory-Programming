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
	int guess;
	printf("Please write down an integer within 32.\n");
	scanf("%d", &guess);
	if (guess == correct_answer) {
		printf("correct\nYou win.\n");
		return 1;
	}
	else if (guess > correct_answer) {
		printf("too high\n");
	}
	else printf("too low\n");
	return 0;
}//use return an int to make the programme judge whether to continue the comparison


int main(void) {
	srand(time(NULL));
	getRand();

	int value = rollDie(32);

	int return_value = comparison(value);

	if (return_value == 0)
		return_value = comparison(value);
	if (return_value == 0)
		return_value = comparison(value);
	if (return_value == 0)
		return_value = comparison(value);
	if (return_value == 0)
		return_value = comparison(value);//compare it for 5 times at most
	if (return_value == 0)
		printf("You lose.");

	getchar();
	getchar();
}//the main process
