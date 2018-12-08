struct Change {
	int cost_pence, give_pence;
	int _2pounds, _1pounds, _50pence, _20pence, _10pence;
	int _5pence, _2pence, _1pence;
};//to declare structures variable

void printChange(struct Change);
int calculation(float, float*);//delare the self-defined funcs first

struct Change getChange(float cost_pence1, float give_pence1) {
	struct Change myChange;//define variable of data type structure 

	float *return_pounds;
	float in_return_pounds = 0;

	return_pounds = &in_return_pounds;
	*return_pounds = (give_pence1 - cost_pence1)/100;

	myChange.cost_pence = cost_pence1;
	myChange.give_pence = give_pence1;
	myChange._2pounds = calculation(2, return_pounds);
	myChange._1pounds = calculation(1, return_pounds);
	myChange._50pence = calculation(0.5, return_pounds);
	myChange._20pence = calculation(0.2, return_pounds);
	myChange._10pence = calculation(0.1, return_pounds);
	myChange._5pence = calculation(0.05, return_pounds);
	myChange._2pence = calculation(0.02, return_pounds);
	myChange._1pence = *return_pounds==0?0:1;

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

int calculation(float value, float *remaining) {
	float store;
	int number;

	store = *remaining;
	if (*remaining >= value) {
		number=store / value;
		*remaining=*remaining-value*number;
		return number;
	}
	else return 0;
}//the circulation used in getChange
