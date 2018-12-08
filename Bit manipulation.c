#include<stdio.h>

void XOR(long int [3][20]);
void seperation(long int [3][20]);
void print(long int [3][20]);//finc's prototype


int main() {
	long int secret[3][20] = { 15643,6913,6916,23040,2377,6985,6408,3657,5638,3084,2119,15910,23079,13629,23101,10300,10557,23073,13092,23369 };
	
	XOR(secret);
	seperation(secret);	
	print(secret);
	
	getchar();
}//rhe main body


void XOR(long int secret[3][20]) {
	int i;
	
	for (i = 0;i < 20;i++) {
		secret[0][i] ^= 31337;
	}
}//func to XOR

void seperation(long int secret[3][20]) {
	int i;
	
	for (i = 0;i < 20;i++) {
		secret[2][i] = secret[0][i] & 255;
		secret[1][i] = (secret[0][i]&65280)>>8;
	}
}//func to split a large integer into two separate letters

void print(long int secret[3][20]) {
	int i;
	
	for (i = 0;i < 20;i++) {
		printf("%c%c", secret[1][i], secret[2][i]);
	}
}//func to output
