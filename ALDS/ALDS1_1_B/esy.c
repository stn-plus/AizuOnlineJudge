// Aizu Onlime Judge
// ALDS1_1_B:   Greatest Common Divisor
// Created esy-na

#include <stdio.h>

void swap(long *x, long *y);

int main(){
	long x, y, temp;
	scanf("%ld", &x);
	scanf("%ld", &y);

	if( x < y ){
		//Swap x and y
		temp = x;
		x = y;
		y = temp;
	}
	else{
		//none
	}

	while(y>0){
		temp = x % y;
		x = y;
		y = temp;
	}

	printf("%ld\n", x);

	return 0;
}
