#include <stdio.h>
#include <stdlib.h>

int isLeapYear(int year);

int main(){
	const int monthSize[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int n, year;
	int *m, *d, *ans;

	int firstDay;
	scanf("%d", &year);
	scanf("%d", &firstDay);
	scanf("%d", &n);
	m =(int*)malloc(sizeof(int)*n);
	d =(int*)malloc(sizeof(int)*n);
	ans =(int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &(m[i]), &(d[i]));
		//check if input is valid
		if (m[i]<1 || m[i]>12)
		{
			ans[i] = -1;
			continue;
		}
		if (d[i] < 1 || d[i] > monthSize[m[i]-1])
		{
			if (isLeapYear(year) != 1 || m[i] != 2 || d[i] != 29 )
			{
				ans[i] = -2;
				continue;
			}
		}

		int dayOfyear =0;
		if( isLeapYear(year) == 1 && m[i]>2){
			for(int k=0; k < m[i]-1; k++){
				dayOfyear += monthSize[k];
			}
			dayOfyear += 1; // plus Feb 29
		}
		else{
			for(int k=0; k < m[i]-1; k++){
				dayOfyear += monthSize[k];
			}
		}
		dayOfyear += (d[i]-1);
		ans[i] = (firstDay + dayOfyear) % 7;
	}

	for(int i=0; i<n; i++){
		printf("%d\n",ans[i] );
	}

	free (m);
	free (d);
	free (ans);
	return 0;
}



int isLeapYear(int y){
	if (y % 400 == 0)
		return 1;
	if (y % 100 ==0)
		return 0;
	if (y % 4 == 0)
		return 1;
	return 0;
}