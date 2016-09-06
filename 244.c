#include <stdio.h>

int main(){
	int specPrNo;
	int fstPrNo[3];
	const int award[6] = {200000, 40000 ,10000 , 4000, 1000, 200};
	scanf("%d %d %d %d", &specPrNo, &(fstPrNo[0]), &(fstPrNo[1]), &(fstPrNo[2]));
	int totalAward =0;
	// int incomeTax, stampDuty;
	int receptNo;
	while(scanf("%d", &receptNo) == 1){

		// special price
		if (specPrNo == receptNo)
		{
			totalAward += 10000000;
			// incomeTax += 10000000* 0.2;
			// stampDuty += 10000000* 0.0004;
			continue;
		}

		// first~sixth prize
		int awardIndex = 0;
		for(int i=100000000; i >= 1000; i /= 10 ){

			for (int pr = 0; pr < 3; pr++)
			{
				if (receptNo % i == fstPrNo[pr])
				{
					/*
					totalAward += award[awardIndex];
					if (i < 5)
					{
						stampDuty += award[awardIndex] * 0.004;
						if (i < 4)
						{
							incomeTax += award[awardIndex] * 0.2;
						}
					}
					*/

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
	//printf("Accoring to The Income Tax Act & Stamp Tax Act, You should pay %d to the Ministry Of Finance XD", incomeTax+stampDuty );
	return 0;
}