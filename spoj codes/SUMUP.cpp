#include<stdio.h>
int main()
{
	double n;
	scanf("%f",&n);
	while(scanf("%lf",&n))
	{n=n*n+n+1;printf("%.5f\n",(n-1)/(n*2));}}
       
