#include <stdio.h>

int main(){
	int specPrNo[3];
	int fstPrNo[3];
	const int award[6] = {200000, 40000 ,10000 , 4000, 1000, 200};
	scanf("%d %d %d %d %d %d\n", &(specPrNo[0]),&(specPrNo[1]),&(specPrNo[2]), &(fstPrNo[0]), &(fstPrNo[1]), &(fstPrNo[2]));
	int totalAward =0;
	
	int receptNo;
	while(scanf("%d\n", &receptNo) == 1){

		// special price
		for (int i = 0; i < 3; i++)
		{
			if (specPrNo[i] == receptNo)
			{
				totalAward += 10000000;
				continue;
			}
		}
		

		// first~sixth prize
		int awardIndex = 0;
		for(int i=100000000; i >= 1000; i /= 10 ){

			for (int pr = 0; pr < 3; pr++)
			{
				if (receptNo % i == fstPrNo[pr] % i)
				{
					totalAward += award[awardIndex];
					 /* Again, C does't support labeled for/break,
					 	so I'll just terminate the outer "for" this way. */
					i = -1;
					break;
				}
			}
			awardIndex++;
		}
	}

	printf("%d\n", totalAward);
	return 0;
}
