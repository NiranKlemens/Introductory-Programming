#include <stdio.h>

int main() {

	char Home_city[100] = " Chengdu";
	int Gap, My_Age = 18, Brother_Age = 16;
	float Pin_money = 7.5;//to declare 4 variables

	Gap = My_Age - Brother_Age;//To calculate our gap

	printf("Greetings!\tI am \\Yang Yuxin\\ who come from %s.My age is %d\n", Home_city, My_Age);//To introduce my origin and my age
	printf("My brother is %d years younger than me.\n", Gap);//To introduce the year gap between me and my brother
	printf("I have %.2f pounds of money each day.", Pin_money);/*The exact money I've got for each day.*/
	printf("My house lies in central city.\n");//To explain the location of my house.
	printf("In my family, we say\'wish you good luck\'a lot.\n");/*One custom of my family.*/
	printf("Do you want to see my grades?Well let\'s see.\n\tWeek\tGrade\n\t1\t\"C+\"\n\t2\t\"B\"\n\t3\t\"A+\"");/*My grade of first three weeks*/

//Wait for a keypress
	getchar();
}
