#include <stdio.h>
#include <stdbool.h>
#include <math.h>


bool isOverlap(int x1, int y1, int r1, int x2, int y2, int r2);
int findSWEnd2(int coor1, int r1, int coor2, int r2);
int findSWEnd3(int coor1, int r1, int coor2, int r2, int coor3, int r3);
int findNEEnd2(int coor1, int r1, int coor2, int r2);
int findNEEnd3(int coor1, int r1, int coor2, int r2, int coor3, int r3);
int testPoints(int w, int n, int e, int s, int x[], int y[], int r[], int circles, int count);

int main(){
	int count;
	int cases; // how many input cases
	int x[3], y[3], r[3];
	scanf("%d\n", &cases);
	for (int i = 0; i < cases; i++)
	{
		count = 0;
		for(int k=0; k<3; k++){
			scanf("%d %d %d\n", &(x[k]), &(y[k]), &(r[k]));
		}
		
		if (isOverlap(x[0], y[0], r[0], x[1], y[1], r[1]))
		{
			if (isOverlap(x[1], y[1], r[1], x[2], y[2], r[2]))
			{
				//DDD
				printf("3 ovlp\n");
				// three circles overlap
				//find a rectangle that contains 3 circles, and search in this rectangle
				int westEnd = findSWEnd3(x[0], r[0], x[1], r[1], x[2], r[2]);
				int southEnd = findSWEnd3(y[0], r[0], y[1], r[1], y[2], r[2]);
				int eastEnd = findNEEnd3(x[0], r[0], x[1], r[1], x[2], r[2]);
				int northEnd = findNEEnd3(y[0], r[0], y[1], r[1], y[2], r[2]);
				count = testPoints(westEnd, northEnd, eastEnd, southEnd, x, y, r, 3, count);
			}
			else
			{
				//ddd
				 printf("1,2 ovlp\n");
				// only circle 1 & circle 2 overlap
				int westEnd = findSWEnd2(x[0], r[0], x[1], r[1]);
				int southEnd = findSWEnd2(y[0], r[0], y[1], r[1]);
				int eastEnd = findNEEnd2(x[0], r[0], x[1], r[1]);
				int northEnd = findNEEnd2(y[0], r[0], y[1], r[1]);
				int groupX[2] = {x[0], x[1]};
				int groupY[2] = {y[0], y[1]};
				int groupR[2] = {r[0], r[1]};
				count = testPoints(westEnd, northEnd, eastEnd, southEnd, groupX, groupY, groupR, 2, count);
				int circle3X[1] = {x[2]};
				int circle3Y[1] = {y[2]};
				int circle3R[1] = {r[2]};
				count = testPoints(x[2] - r[2], y[2] + r[2], x[2] + r[2], y[2] - r[2], circle3X, circle3Y, circle3R, 1, count );
			}
		}
		else if(isOverlap(x[0], y[0], r[0], x[2], y[2], r[2])){
			// if circle 1 & 3 overlap
			//ddd
			printf("1,3 ovlp\n");
			int westEnd = findSWEnd2(x[0], r[0], x[2], r[2]);
			int southEnd = findSWEnd2(y[0], r[0], y[2], r[2]);
			int eastEnd = findNEEnd2(x[0], r[0], x[2], r[2]);
			int northEnd = findNEEnd2(y[0], r[0], y[2], r[2]);
			int groupX[2] = {x[0], x[2]};
			int groupY[2] = {y[0], y[2]};
			int groupR[2] = {r[0], r[2]};
			count = testPoints(westEnd, northEnd, eastEnd, southEnd, groupX, groupY, groupR, 2, count);
			int circle2X[1] = {x[1]};
			int circle2Y[1] = {y[1]};
			int circle2R[1] = {r[1]};
			count = testPoints(x[1] - r[1], y[1] + r[1], x[1] + r[1], y[1] - r[1], circle2X, circle2Y, circle2R, 1, count );
		}
		else if(isOverlap(x[1], y[1], r[1], x[2], y[2], r[2])){
			//if circle 2 & 3 overlap
			//ddd
			printf("2,3 ovlp\n");
			int westEnd = findSWEnd2(x[1], r[1], x[2], r[2]);
			int southEnd = findSWEnd2(y[1], r[1], y[2], r[2]);
			int eastEnd = findNEEnd2(x[1], r[1], x[2], r[2]);
			int northEnd = findNEEnd2(y[1], r[1], y[2], r[2]);
			int groupX[2] = {x[1], x[2]};
			int groupY[2] = {y[1], y[2]};
			int groupR[2] = {r[1], r[2]};
			count = testPoints(westEnd, northEnd, eastEnd, southEnd, groupX, groupY, groupR, 2, count);
			int circle1X[1] = {x[0]};
			int circle1Y[1] = {y[0]};
			int circle1R[1] = {r[0]};
			count = testPoints(x[0] - r[0], y[0] + r[0], x[0] + r[0], y[0] - r[0], circle1X, circle1Y, circle1R, 1, count );

		}
		else{
			// none of the circles overlap
			//ddd
			printf("no ovlp\n");
			for(int c = 0; c < 3; c++){
				int circleX[1] = {x[c]};
				int circleY[1] = {y[c]};
				int circleR[1] = {r[c]};
				count = testPoints(x[c] - r[c], y[c] + r[c], x[c] + r[c], y[c] - r[c], circleX, circleY, circleR, 1, count );
			}

		}
		printf("%d\n", count);
	}
	return 0;
}


bool isOverlap(int x1, int y1, int r1, int x2, int y2, int r2){
	if (pow( x2 - x1, 2) + pow( y2 - y1, 2) <= pow( r1 + r2, 2))
		return true;
	else
		return false;
}

int findSWEnd3(int coor1, int r1, int coor2, int r2, int coor3, int r3){
	int w1 = coor1 - r1;
	int w2 = coor2 - r2;
	int w3 = coor3 - r3;
	if (w1 < w2)
	{
		if (w1 < w3)
			return w1;
		else
			return w3;
	}
	else{
		if (w2 < w3)
			return w2;
		else
			return w3;
	}
}
int findSWEnd2(int coor1, int r1, int coor2, int r2){
	if (coor1 - r1 < coor2 - r2)
		return coor1 - r1;
	else
		return coor2 - r2;
}

int findNEEnd3(int coor1, int r1, int coor2, int r2, int coor3, int r3){
	int w1 = coor1 + r1;
	int w2 = coor2 + r2;
	int w3 = coor3 + r3;
	if (w1 > w2)
	{
		if (w1 > w3)
			return w1;
		else
			return w3;
	}
	else{
		if (w2 > w3)
			return w2;
		else
			return w3;
	}
}

int findNEEnd2(int coor1, int r1, int coor2, int r2){
	if (coor1 + r1 > coor2 +r2)
		return coor1 + r1;
	else
		return coor2 +r2;
}

int testPoints(int west, int north, int east, int south, int x[], int y[], int r[], int numOfCircle,int count){
	for(int ver = south; ver <= north; ver++){
		for(int hor = west; hor <= east; hor++){
			int in = 0;
			for(int c = 0; c < numOfCircle; c++){
				if (pow(ver - y[c], 2) + pow(hor - x[c], 2) <= pow(r[c], 2))
				{
					in++;
				}
			}
			if (in % 2 == 1)
			{
				count++;
			}
		}
	}
	return count;
}

