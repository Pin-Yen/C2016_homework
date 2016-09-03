#include <stdio.h>
#include <math.h>

int HCF(int a, int b);
void convert(int numerator, int denominator, int* x, int* y, int* z);

int main(){
	int a, b, c, d, e, f, g, x, y, z;
	scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g);
	//convert to improper fractions
	if (a < 0)
	{
		b = -b + (a*c);
	}
	else{
		b = b + (a*c);
	}
	if (e < 0)
	{
		f = -f + (e*g);
	}
	else{
		f = f + (e*g);
	}

	switch(d){
		case 0:
			//addition
			y = b*g + f*c;
			z = c*g;
			break;
		case 1:
			//substraction
			y = b*g - f*c;
			z = c*g;
			break;
		case 2:
			//multiplication
			y = b*f;
			z = c*g;
			break;
		case 3:
			//division
			 y = b*g;
			 z = c*f;
			 break;
	}

	convert(y,z,&x,&y,&z);
	printf("%d\n%d\n%d\n", x, y, z);
	return 0;
}

// convert improper fractions to mixed fractions
// num/denom -> x + y/z 
void convert(int num, int denom, int* x, int* y, int* z ){
	*x = (int) (num/denom);
	*y -= ((*x) * (*z));
	int commonFactor = HCF(*y,*z);
	 
	*y /= commonFactor;
	if (*y < 0)
	{
		*y = -(*y);
	}
	*z /= commonFactor;
}

//returns the Highest Common Factor of a & b
// a > b
int HCF(int a, int b){
	// if |b| > |a|, swap
	if (abs(b) > abs(a))
	{
		int temp = b;
		b = a;
		a = temp;
	}

	// prevent arithmetic execption divide by 0
	if (b == 0 && a == 0 )
	{
		return 1;
	}


	if (b == 0)
	{
		return a;
	}
	a = a - ((int) (a/b)) *b;
	if (a == 0)
	{
		return b;
	}
	else
	{
		b = b - ((int)(b/a)) *a;
		if (b == 0)
		{
			return a;
		}
		else if (a>b)
		{
			HCF(a,b);
		}
		else{
			HCF(b,a);
		}
	}
}