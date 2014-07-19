#include<stdio.h>

using namespace std;

#define LL long long
#define MAX 31622777
#define LMT 15317300

#define chk(n) (c[n>>6]&(1<<((n>>1)&31)))
#define set(n) (c[n>>6]|=(1<<((n>>1)&31)))
#define sq(x) ((x)*(x))

#define p(x) printf("%d",x)
#define inp(x) scanf("%d",&x)
#define inpll(x) scanf("%lld",&x)
#define getcx getchar_unlocked
/*inline void inp( int &n ) 
 {
    n=0;
    int ch=getcx();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
 
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
  }*/


using namespace std;
unsigned c[MAX];
unsigned v[LMT],len;

void sieve()
{
unsigned i, j, k;
for(i=3; i<5624; i+=2)
if(!chk(i))
for(j=i*i,k=i<<1; j<MAX; j+=k)
set(j);
j=0;
v[j++]=2;
for(i=3; i<MAX; i+=2)
if(!chk(i))
v[j++]=i;
len=j;
}
void dn(LL n)
{
	int cnt=0;
	for(int i=0; i<len && sq(v[i])<=n ; i++)
	{
		if(n%v[i]==0)
		{
			cnt=0;
			while(n%v[i]==0)
			{
				cnt++;
				n/=v[i];
			}
			printf("%u^%u ",v[i],cnt);
		}
	}
	if(n>1)
	printf("%lld^1\n",n);
	else
	printf("\n");
}
int main()
{
	sieve();
	LL n;
	inpll(n);
	while(n)
	{
		dn(n);
		inpll(n);
	}
	return 0;
}
