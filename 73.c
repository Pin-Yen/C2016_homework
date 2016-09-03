#include <stdio.h>

int main(){
	int n, r0 =0, r1 =0, r2 =0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int input, r;
		scanf("%d", &input);
		r = input % 3;

		switch (r){
			case 0:
				r0++;
				break;
			case 1:
				r1++;
				break;
			case 2:
				r2++;
				break;
		}
	}
	printf("%d %d %d", r0, r1, r2 );
	return 0;
}