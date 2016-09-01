#include <stdio.h>
#include <stdlib.h>

int main()
{
	int head, leg, tail;
	int chick, rabb, crab;
	while(scanf("%d %d %d",&head, &leg, &tail) == 3){
		//chickens & rabbits both have tails, only crabs don't
		crab = head - tail;
		
		//remaining leg
		leg - crab*8; 

		// chick + rabb == tail
		//chick*2 + rabb*4 == leg
		//use Cramer's rule to solve chick & rabb
		const int delta = 2;
		chick =  abs(tail*4 - 1*leg)/delta;
		rabb = abs(1*leg-tail*2)/delta;

		printf("%d\n%d\n%d\n", chick, rabb, crab );
	}
	return 0;
}