#include <stdio.h>

int main(){
	int input;
	
	while(scanf("%d", &input) == 1){
		if (input % 3 == 0 && input % 5 == 0 && input % 7 != 0 )
		{
			printf("0\n");
		}
		else{
			printf("1\n");
		}
	}
	
	return 0;
}