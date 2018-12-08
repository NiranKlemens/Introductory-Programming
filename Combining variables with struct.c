/*Math formulas:
give_pence-cost_pence=return_pence
if return_pence>or=200
	then [return_pence/200]=_2pounds & return_pence mod 200=new return_pence
	else circulation
*/
#include<stdio.h>

struct Change {
	int cost_pence, give_pence;
	int _2pounds, _1pounds, _50pence, _20pence, _10pence;
	int _5pence, _2pence, _1pence;
};//to declare structures variable

void printChange(struct Change);
int calculation(int,int*);//delare the self-defined funcs first

struct Change getChange(int cost_pence1, int give_pence1) {
	struct Change myChange;//define variable of data type structure 

	int *return_pence;
	int in_return_pence = 0;

	return_pence = &in_return_pence;
	*return_pence = give_pence1 - cost_pence1;

	myChange.cost_pence = cost_pence1;
	myChange.give_pence = give_pence1;
	myChange._2pounds = calculation(200, return_pence);
	myChange._1pounds = calculation(100, return_pence);
	myChange._50pence = calculation(50, return_pence);
	myChange._20pence = calculation(20, return_pence);
	myChange._10pence = calculation(10, return_pence);
	myChange._5pence = calculation(5, return_pence);
	myChange._2pence = calculation(2, return_pence);
	myChange._1pence = *return_pence;

	return myChange;// we need to return this to main()  
}

int main() {
	struct Change coins;

	coins = getChange(7, 10);
	printChange(coins);
	coins = getChange(56, 70);
	printChange(coins);
	coins = getChange(124, 200);
	printChange(coins);
	coins = getChange(1232, 2000);
	printChange(coins);

	getchar();
	return 0;
}//the main body


void printChange(struct Change myChange) {
	printf("Customer gave %d pence,", myChange.give_pence);
	printf(" item(s) cost %d pence.\n", myChange.cost_pence);
	printf("Give customer: \n");
	printf("200\t100\t50\t20\t10\t5\t2\t1\n");
	printf("%d\t%d\t", myChange._2pounds, myChange._1pounds);
	printf("%d\t%d\t%d\t", myChange._50pence, myChange._20pence, myChange._10pence);
	printf("%d\t%d\t%d\t\n\n", myChange._5pence, myChange._2pence, myChange._1pence);
}//a func to output

int calculation(int value, int *remaining) {
	int store;

	store = *remaining;
	if (*remaining >= value) {
		*remaining %= value;
		return store / value;
	}
	else return 0;
}//the circulation used in getChange
