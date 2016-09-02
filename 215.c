int main()
{
	int head, leg, tail;
	int chick, rabb, crab;
	while(scanf("%d %d %d",&head, &leg, &tail) == 3){
		//chickens & rabbits both have tails, only crabs don't
		crab = head - tail;

		//remaining leg
		int remainingLeg = leg - crab*8; 

		// chick + rabb == tail
		//chick*2 + rabb*4 == remainingLeg
		//use Cramer's rule to solve chick & rabb
		const int delta = 2;
		chick =  abs(tail*4 - 1*remainingLeg)/delta;
		rabb = abs(1*remainingLeg-tail*2)/delta;

		//verify answers
		if (chick>=0 && rabb>=0 && crab>=0 &&
			chick + rabb +crab == head &&
			chick +rabb == tail &&
			chick*2 + rabb*4 +crab*8 == leg )
		{
			printf("%d\n%d\n%d\n", chick, rabb, crab );
		}
		else{
			printf("0\n");
		}

		
	}
	return 0;
}