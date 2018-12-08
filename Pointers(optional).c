#include <stdio.h>
#include<time.h>
#define TIME_DIFFERENCE 8//to adjust time zone

long int getTime();
void getYear(int, int*, int*, int*,long int*);
void getHour_Minute(int, long int*, int*, int*);
void printTime(int, int, int, int,int);
void getMonth_Day(int*,int*);//declare self-defined func


int main() {
	int in_year, in_day, in_hour, in_minute, in_month;
	long int in_second_remaining;
	int *year = &in_year, *day = &in_day, *hour = &in_hour, *minute = &in_minute,*month=&in_month;
	long int *second_remaining = &in_second_remaining;//use of poiners
	
	long int time = getTime();
	
	getYear(time, year, day, month, second_remaining);
	getHour_Minute(time, second_remaining, hour, minute);
	printTime(in_year, in_day, in_hour, in_minute, in_month);
	
	getchar();
}//the main body,to use all funcs


void getYear(int time, int*year, int*day,int*month,long int* second_remaining) {
	int i,count_leapyear=0;
	
	*day = time / 86400;
	*year = *day / 365;
	*year += 1970;

	for (i = 1970;i <= *year ;i++) {
		if (((i % 4) == 0) && ((i % 100 )!= 0/*note that the year 2000 isn't a leap year*/)) {
			count_leapyear++;
		}
	}
	
	*day = (*day - (*year-1970) * 365)-count_leapyear;
	getMonth_Day(day, month);
	*second_remaining = time % 86400;
}//func to get month&day

void getHour_Minute(int time, long int *second_remaining, int*hour, int*minute) {
	*hour = *second_remaining / 3600 + TIME_DIFFERENCE;
	*second_remaining %= 3600;
	*minute = *second_remaining / 60;
}//tunc to get hour&minute

void getMonth_Day(int *day,int *month) {
	if (*day <= 31) {
		*month = 1;
	}
	else if (*day <= 59) {
		*day -= 31;
		*month = 2;
	}
	else if (*day <= 90) {
		*day -= 59;
		*month = 3;
	}
	else if (*day <= 120) {
		*day -= 90;
		*month = 4;
	}
	else if (*day <= 151) {
		*day -= 120;
		*month = 5;
	}
	else if (*day <= 181) {
		*day -= 151;
		*month = 6;
	}
	else if (*day <= 212) {
		*day -= 181;
		*month = 7;
	}
	else if (*day <= 243) {
		*day -= 212;
		*month = 8;
	}
	else if (*day <= 273) {
		*day -= 243;
		*month = 9;
	}
	else if (*day <= 304) {
		*day -= 273;
		*month = 10;
	}
	else if (*day <= 334) {
		*day -= 304;
		*month = 11;
	}
	else {
		*day -= 334;
		*month = 12;
	}
}// the func inside one self-defined func

long int getTime() {
	time_t now;
	return now = time(NULL);
}

void printTime(int year, int day, int hour, int minute,int month) {
	if (minute < 10) {
		printf("Present time is:\n%d:0%d in day %d in ", hour, minute, day);
	}
	else {
		printf("Present time is:\n%d:%d in day %d in ", hour, minute, day);
	}
	
	switch (month) {
	case 1:
		printf("January");
		break;
	case 2:
		printf("February");
		break;
	case 3:
		printf("March");
		break;
	case 4:
		printf("April");
		break;
	case 5:
		printf("May");
		break;
	case 6:
		printf("June");
		break;
	case 7:
		printf("July");
		break;
	case 8:
		printf("August");
		break;
	case 9:
		printf("September");
		break;
	case 10:
		printf("October");
		break;
	case 11:
		printf("November");
		break;
	case 12:
		printf("December");
		break;
	}
	
	printf(" in %d", year);
}//the func to output
