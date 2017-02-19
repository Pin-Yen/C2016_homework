#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int main(){
	int* xCoor, *yCoor, *cap, *occup;
	int lots, bikes;
	scanf("%d", &lots);
	xCoor =(int*) malloc(sizeof(int)*lots);
	yCoor =(int*) malloc(sizeof(int)*lots);
	cap =(int*) malloc(sizeof(int)*lots);
	occup =(int*) malloc(sizeof(int)*lots);

	// get parking lot info
	for (int i = 0; i < lots; i++)
	{
		scanf("%d %d %d", &(xCoor[i]), &(yCoor[i]), &(cap[i]));
		occup[i] = 0;
	}

	scanf("%d", &bikes);
	for (int i = 0; i < bikes; i++)
	{
		int bX, bY;
		scanf("%d %d", &bX, &bY);
		int minDist = INT_MAX, lotNo = -1;
		for (int k = 0; k < lots; k++)
		{
			// first make sure the lot isn't full yet.
			if (occup[k] != cap[k])
			{
				int dist = abs(bX - xCoor[k]) + abs(bY - yCoor[k]);
				if(dist < minDist){
					minDist = dist;
					lotNo = k;
				}
				// if two lot have the same distance
				else if(dist == minDist){
					// compare X coordinates first
					if (xCoor[k] < xCoor[lotNo])
					{
						lotNo = k;
					}
					// If X coordinates are the same, compare Y coordinates
					else if(xCoor[k] == xCoor[lotNo]){
						if (yCoor[k] < yCoor[lotNo])
						{
							lotNo = k;
						}
					}
				}
			}
		}
		occup[lotNo]++;
	}

	for (int i = 0; i < lots; i++)
	{
		printf("%d\n", occup[i] );
	}

	free (xCoor);
	free (yCoor);
	free (cap);
	free (occup);
	return 0;
}
