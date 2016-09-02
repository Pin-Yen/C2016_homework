#include <stdio.h>

int main()
{
	int score;
	int input;

	while(scanf("%d", &input) == 1){
		if (input <= 0)
		{
			printf("-100\n");
		}
		else{
			if (input % 3 == 0)
			{
				score += 3;
			}
			if (input % 5 == 0)
			{
				score += 5;
			}
			if (input >= 100 && input <=200)
			{
				score += 50;
			}
			else{
				score -= 50;
			}
			printf("%d\n",score );
		}
	}
	return 0;
}