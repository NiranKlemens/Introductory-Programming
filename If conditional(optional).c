#include <stdio.h>
#include<stdlib.h>
#include<time.h>//extra includes to open new files

float getRand() {
	return rand() / (RAND_MAX + 1.0);
}// Get a random number from 0 to 0.9999999 

float enlarge(int multiple) {
	return multiple *getRand();
}//to get a positive decimal within 32

int comparison(float correct_answer) {
	float guess,distance;
	printf("Please guess a positive decimal within 32.\n");
	scanf("%f", &guess);
	if (guess == correct_answer) {
		printf("correct\nYou win.\n");
		return 1;
		}else if (guess > correct_answer) {
			distance = guess - correct_answer;
			printf("Your answer is bigger than the correct answer");
			}else {
				distance = correct_answer - guess;
				printf("Your answer is smaller than the correct answer");
			}//to find the absolute value by pamparing which is bigger
	if (distance <= 0.1) {
		printf("but you win.\nYou guess a number within 0.1 of the correct one.\n");
		return 1;
	}else {
		printf(",too far away.\n");
		return 0;
	}
}//use return an int to make the programme judge whether to continue the comparison


int main(void) {
	srand(time(NULL));
	getRand();

	float value = enlarge(32);

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
