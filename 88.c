#include <stdio.h>

int main(){
	int var_a, var_b;
	int a=0, b=0;
	int numbers[4] = {-1,-1,-1,-1};
	scanf("%d %d", &var_a, &var_b);
	int digitsA[4];
	int digitsB[4];
	// calculate and store all digits of var_a &var_b
	int j=0;
	for(int i = 10000; i >= 10 ; i /= 10 ){
		digitsA[j] = (var_a%i) / (i/10);
		digitsB[j] = (var_b%i) / (i/10);
		j++;
	}
	// count a
	for (int i = 0; i < 4; i++)
	{
		if (digitsA[i] == digitsB[i])
		{
			a++;
		}
	}

	//count b
	for (int i = 0; i < 4; i++)
	{
		for (int j = i+1 ; j < 4; j++)
		{
			if (digitsA[i] == digitsB[j])
			{
				b++;
			}
			if(digitsA[j] == digitsB[i])
			{
				b++;
			}
		}
	}

	printf("%dA%dB", a, b );

	return 0;
}