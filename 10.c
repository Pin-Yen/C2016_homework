#include <stdio.h>
#include <math.h>

int main()
{
	int a,n;

	while(scanf("%d %d", &a, &n) == 2){
		int answer = (int) pow(a,n);
		printf("%d\n", answer);
	}
	
	return 0;
}