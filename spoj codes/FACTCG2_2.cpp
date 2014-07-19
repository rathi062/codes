#include<stdio.h>
using namespace std;
#define MAX 10000000
int prime[MAX+1];
 
void sieve(){
	prime[1]=1;
	for(long long int i=2;i<=MAX;i+=2)
	prime[i]=2;
	for(long long int i=3;i<=MAX;i+=2){
		if(!prime[i]){
            prime[i]=i;
			for(long long int j=i*i,d=i<<1;j<=MAX;j+=d){
				if(!prime[j])prime[j]=i;
			}
		}
	}
}
void dn(int n)
{
	while(n>1)
	{
		printf(" x %d",prime[n]);
		n/=prime[n];
	}
	printf("\n");
}
int main()
{
	int n,cnt=0;
	sieve();
	while(scanf("%d",&n))
	{
		printf("1");
		dn(n);
	}
	return 0;
}
