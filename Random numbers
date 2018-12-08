#include <stdio.h>
#include<stdlib.h>
#include<time.h>//extra includes to open new files

float getRand() {
	return rand() / (RAND_MAX + 1.0);
}// Get a random number from 0 to 0.9999999 

int rollDie(int multiple) {
	int value = 0;
	do {
		float random_number = getRand();
		int integer1 = random_number * 100;
		float decimal = integer1 / 100.0;
		int integer2 = decimal * 20 + 1;//to get a random positive integer number within 20
		
		if (integer2 <= multiple) {
			value = integer2;
		}
	} while (value == 0);//to take out the number out of scope by a circulation
	
	return value;
}

int main(void) {
	srand(time(NULL));
	getRand();
	
	int value = 0;
	
	value = rollDie(6);
	printf("6-sided die: %i\n", value);

	value = rollDie(20);
	printf("20-sided die: %i\n", value);

	getchar();
}//the main process
