#include <stdio.h>

int main(){
	int a, b, count = 0;
	scanf("%d %d", &a, &b);
	for(int i=10000000; i>=100; i /= 10){
		if ( (b%i)/(i/100) == a )
		{
			count++;
		}
	}
	printf("%d\n",count );
	return 0;
}