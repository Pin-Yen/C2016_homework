#include <stdio.h>
#include <stdlib.h>
int main(){
	int a1,a2,b1,b2,c1,c2,d1,d2;
	while(scanf("%d %d %d %d %d %d %d %d"
		,&a1, &a2, &b1, &b2, &c1, &c2, &d1, &d2) == 8){

		//area 1: the area enclosed by linking the four points
		int twoTimesArea1 = abs(a1*b2 +b1*c2 +c1*d2 +d1*a2
		 - b1*a2 - c1*b2 - d1*c2 - a1*d2);

		//area 2: the sum of area of the four triangles △OAB △OBC △OCD △ODA
		int twoTimesArea2 = abs(a1*b2 - b1*a2) + abs(b1*c2 - c1*b2) +abs(c1*d2 - c2*d1) +abs(d1*a2 - a1*d2);
		if (twoTimesArea1 == twoTimesArea2)
		{
			printf("1\n");
		}
		else{
			printf("0\n");
		}
	}
	return 0;
}
