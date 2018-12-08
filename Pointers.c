#include <stdio.h>
#include<time.h>
#define TIME_DIFFERENCE 8//to adjust time zone

long int getTime();
void getYear_Day(int, int*, int*, long int*);
void getHour_Minute(int, long int*, int*, int*);
void printTime(int, int, int, int);//declare self-defined func

int main() {
	int in_year, in_day, in_hour, in_minute;
	int *year = &in_year, *day = &in_day, *hour = &in_hour, *minute = &in_minute;
	long int in_second_remaining;
	long int *second_remaining = &in_second_remaining;//use of poiners
	
	long int time = getTime();

	getYear_Day(time, year, day, second_remaining);
	getHour_Minute(time, second_remaining, hour, minute);
	printTime(in_year, in_day, in_hour, in_minute);
	getchar();
}//the main body,to use all funcs

void getYear_Day(int time, int*year, int*day, long int* second_remaining) {
	*day = time / 86400;
	*year = *day / 365 + 1970;
	*day %= 365;
	*second_remaining = time % 86400;
}//tunc to get year&day

void getHour_Minute(int time, long int *second_remaining, int*hour, int*minute) {
	*hour = *second_remaining / 3600 + TIME_DIFFERENCE;
	*second_remaining %= 3600;
	*minute = *second_remaining / 60;
}//tunc to get hour&minute

long int getTime() {
	time_t now;
	return now = time(NULL);
}

void printTime(int year, int day, int hour, int minute) {
	if (minute < 10) {
		printf("Present time is:\n%d:0%d in day %d in %d", hour, minute, day, year);
	}
	else {
		printf("Present time is:\n%d:%d in day %d in %d", hour, minute, day, year);
	}
}//the func to output
