#include <stdio.h>

int main(){
	long i, n, maxv, minv, num;

	scanf("%ld", &n);
	scanf("%ld", &minv);
	scanf("%ld", &num);
	maxv = num - minv;
	if(minv >= num){
		minv = num;
	}
	else{
		//none
	}

	for( i=1; i<(n-1); i++	){
		scanf("%ld", &num);
		if( maxv <= (num - minv) ){
			maxv = (num - minv);
		}
		else{
			//none
		}

		if( minv >= num){
			minv = num;
		}
		else{
			//none
		}
	}

	printf("%ld\n", maxv);

	return 0;
}
