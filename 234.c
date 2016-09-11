#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int findRoot(int positive, int negative,const int a, const int b, const int c);
int main(){
	int a,b,c;
	int firRoot, secRoot, thrRoot;
	scanf("%d %d %d", &a, &b, &c);

	//use first derivative to find relative min/max
	int extrema1 = ( -2*a + sqrt(4*pow(a,2) - 12*b ) ) /6;
	int extrema2 = ( -2*a - sqrt(4*pow(a,2) - 12*b ) ) /6;
	if (extrema1 > 0)
	{
		firRoot = findRoot(extrema1, extrema2, a, b, c);	
	}
	else{
		firRoot = findRoot(extrema2, extrema1, a, b, c);
	}

	//find the remaining 2 roots
	int newB = a +firRoot;
	int newC = b + firRoot*(a + firRoot);
	secRoot =(-newB + sqrt( pow(newB,2) - 4*1*newC)) /2;
	thrRoot =(-newB - sqrt( pow(newB,2) - 4*1*newC)) /2;

	firRoot = -firRoot;
	secRoot = -secRoot;
	thrRoot = -thrRoot;


	if (firRoot > secRoot)
	{
		int temp = firRoot;
		firRoot = secRoot;
		secRoot =temp;
	}
	if (secRoot > thrRoot)
	{
		int temp = secRoot;
		secRoot = thrRoot;
		thrRoot = temp;
	}
	if (firRoot > secRoot)
	{
		int temp = firRoot;
		firRoot = secRoot;
		secRoot = temp;
	}
	printf("%d %d %d", firRoot, secRoot, thrRoot);
	return 0;
}


int findRoot(int positive, int negative, const int a, const int b, const int c){
	int m = ( positive + negative ) /2;
	int value = pow(m ,3) + a*m*m + b*m + c;
	if (value == 0)
	{
		return m;
	}
	else if(value > 0){
		findRoot( m, negative,a,b,c);
	}
	else{
		findRoot( positive, m, a, b, c);
	}
}
