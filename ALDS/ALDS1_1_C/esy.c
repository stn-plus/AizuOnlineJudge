// Aizu Onlime Judge
// ALDS1_1_C:   Prime Numbers
// Created esy-na

#include <stdio.h>
#include <math.h>

int main(){

	long x;
	int i, flag, count;

	count = 0;

	while( scanf("%ld", &x) != EOF ){
		flag = 0;

		if( x == 2 ){
			//none
		}
		else if( (x < 2) || (( x % 2) == 0 )){
			flag = 1;	//Not prime number
		}
		else{
			i=3;
			while( i <= sqrt(x) ){
				if( x % i == 0 ){
					flag = 1;	//Not prime number
					break;
				}
				i += 2;
			}
		}

		if( flag == 1 ){
			//none
		}
		else{
			count++;
		}
	}

	printf("%d\n", count);

	return 0;
}
