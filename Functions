#include <stdio.h>

float ohm_law(float voltage, float Rparallel_3) {
	return voltage / Rparallel_3;
}//to set up a function for calculating the current

float series(float R1_series,float R2_series) {
	return R1_series+ R2_series;
}//to set up a function for calculating the value of resistor in series

float parallel(float R1_parallel, float R2_parallel) {
	return 1 / (1 / R1_parallel + 1 / R2_parallel);
}//to set up a function for calculating the value of resistor in parallel

float parallel_three(float R1_parallel_three, float R2_parallel_three,float R3_parallel_three) {
	return 1 / (1 / R1_parallel_three + 1 / R2_parallel_three + 1 / R3_parallel_three);
}// on condition that there're 3 resistors

float process(float r1,float r2,float r3,float r4,float r5,float r6,float r7){
	float R1_series = r1;
	float R2_series = r2;
	float Rseries1 = series(R1_series, R2_series);

	float R1_parallel = r3;
	float R2_parallel = r4;
	float Rparallel1 = parallel(R1_parallel, R2_parallel);

	R1_parallel = r6;
	R2_parallel = r7;
	float Rparallel2 = parallel(R1_parallel, R2_parallel);

	float Rseries2 = series(Rparallel2, r5);

	float Rparallel3 = parallel_three(Rseries1, Rparallel1, Rseries2);

	float voltage = 12;
	float current = ohm_law(voltage,Rparallel3);

	return current;
}//the main process of calculation on this circuit

void print(float current,short sequence) {
	printf("the current of the data in the %d group is %.2f mA.\n", sequence,current*1000);
}//to output

int main(void) {
	short sequence = 1;
	float r1 = 100, r2 = 200, r3 = 300, r4 = 400, r5 = 500, r6 = 600, r7 = 700;
	float current=process(r1, r2, r3, r4, r5, r6, r7);
	print(current,sequence);

	++sequence;
	r1 = 123, r2 = 234, r3 = 345, r4 = 456, r5 = 567, r6 = 678, r7 = 789;
	current = process(r1, r2, r3, r4, r5, r6, r7);
	print(current, sequence);

	getchar();
}//Given two groups of number,I need this main code to use the main process twice
