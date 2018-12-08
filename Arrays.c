#include <stdio.h>   

void printfib(int);//to declare the self-defined function first

int main() {  
	printfib(10);
	printfib(20);//to print out a 10-integer array and a 20-array integer

	printfib(50);
	printf("comments:The scope of integer in this computer is from -2147483648 to 2147483647.\n");
	printf("If the integer overflows,it will return to the end of negetive integers.\n");
	printf("So there appears to be negetive integers when we print out a 55-integer array in this computer.\n");

	getchar();
}

void printfib(int size) {
	int fib[50] = { 0,1 };
	int i = 2;

	printf("%i %i ", fib[0], fib[1]);
	for (;i < size;i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
		printf("%i ", fib[i]);
	}//to calculate and print out the Fibonacci numbers
	printf("\n");
}//this is a loop to be used for 3 times
