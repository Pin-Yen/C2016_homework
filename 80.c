#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int *x1, *x2, *x3, *y1, *y2, *y3;
	int n;
	scanf("%d", &n);

	//allocate memory
	x1 = (int*)malloc(sizeof(int)*n);
	x2 = (int*)malloc(sizeof(int)*n);
	x3 = (int*)malloc(sizeof(int)*n);
	y1 = (int*)malloc(sizeof(int)*n);
	y2 = (int*)malloc(sizeof(int)*n);
	y3 = (int*)malloc(sizeof(int)*n);

	// scan input
	for(int i=0; i<n; i++){
		scanf("%d %d %d %d %d %d",&(x1[i]), &(y1[i]), &(x2[i]), &(y2[i]), &(x3[i]), &(y3[i]) );
	}

	for(int i=0; i<n; i++){
		int length1sq =(int) pow((x2[i] - x1[i]), 2) + pow((y2[i] - y1[i]), 2);
		int length2sq =(int) pow((x3[i] - x2[i]), 2) + pow((y3[i] - y2[i]), 2);
		int length3sq =(int) pow((x1[i] - x3[i]), 2) + pow((y1[i] - y3[i]), 2);		

		if (length1sq == length2sq || length2sq == length3sq || length3sq == length1sq)
		 {
		 	printf("isosceles\n");
		 }
		 else if(length1sq + length2sq == length3sq || length2sq +length3sq == length1sq || length3sq + length1sq == length2sq){
		 	printf("right\n");
		 }
		 else if(length1sq + length2sq < length3sq || length2sq +length3sq < length1sq || length3sq + length1sq < length2sq){
		 	printf("obtuse\n");
		 }
		 else{
		 	printf("acute\n");
		 }
	}

	//deallocate memory
	free(x1);
	free(x2);
	free(x3);
	free(y1);
	free(y2);
	free(y3);

	return 0;
}