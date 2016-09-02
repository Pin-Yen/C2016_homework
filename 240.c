#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int n;
	scanf("%d", &n);

	int *x = (int *)malloc(sizeof(int)*4*n);
	int *y = (int *)malloc(sizeof(int)*4*n);

	for(int i=0; i<n; i++){
		for(int j=0; j<4; j++){
			scanf("%d %d", &(x[i*4+j]), &(y[i*4+j]));
		}
	}

	for(int i=0; i<n; i++){
		int length[6];
		int lengthIndex = 0;

		for(int j=0; j<4; j++){
			for(int k=j+1; k<4; k++){
				length[lengthIndex] = (int) pow((x[i*4 + j] - x[i*4 + k]),2) + pow((y[i*4 + j] - y[i*4 + k]),2);
				lengthIndex++ ;
			}
		}
		//initialize 3 buckets to store different side length
		int bucket[3];
		//put the first side length into the 1st bucket
		bucket[0] = length[0];
		int occupiedBucket = 1;

		for (int l = 1; l < 6; l++ )
		{
			for (int m = 0; m < occupiedBucket; m++)
			{
				if (length[l] != bucket[m])
				{
					//If you havn't checked all filled buckets yet.
					if (m != occupiedBucket -1)
					{
						continue;
					}
					//If 3 buckets are already filled
					if (occupiedBucket == 3)
					{
						occupiedBucket++;
						// Exit both for statements (Why aren't there "labeled for/break" in C?)
						m = occupiedBucket;
						l = 6;
					}
					else{
						// fill a new bucket
						bucket[occupiedBucket] = length[l];
						occupiedBucket++;
					}
					
				}
				else{
					// Found a belonging bucket, then sort next length
					m =occupiedBucket;
				}
			}
		}
		switch(occupiedBucket){
			case 4:
				printf("other\n");
				break;

			case 3:
				if (bucket[0] + bucket[1] == bucket[2] ||
					bucket[1] + bucket[2] == bucket[0] ||
					bucket[2] + bucket[0] == bucket[1])
				{
					printf("rectangle\n");
				}
				else{
					printf("diamond\n");
				}
				break;
			
			case 2:
				printf("square\n");
				break;
		}
	}
	free(x);
	free(y);
	return 0;
}