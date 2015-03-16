#include<iostream>
#include<list>
#include<string>
#include<cstring>
//#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<queue>
#define LL long long
using namespace std;
LL no,m,l;
LL mulmod(LL a,LL b, LL c)
{
	LL x=0,y=a%c;
	while(b>0)
	{
		if(b%2==1)
		x=(x+y)%c;
		y=(y*2)%c;
		b/=2;
	}
	return x%c;
}
LL modulo(LL a,LL b,LL c)
{
	LL x=1,y=a;
	while(b>0)
	{
		if(b%2==1)
			//x=(x*y)%c; 
			x = mulmod(x,y,c);
		//y=(y*y)%c; 
		 y =mulmod(y,y,c);
		b/=2;
	}
	return x%c;
}

bool miller(LL p,int iteration)
{
	if(p<2)
	return false;
	if( p!=2 && !(p&1))
	return false;
	LL s=p-1;
	while(!s&2)
		s=s>>1;
	for(int i=0;i<iteration;i++)
	{
		LL a=rand()%(p-1)+1,tmp=s;
		LL mod=modulo(a,tmp,p);
		while( tmp!=p-1 && mod!=1 && mod!=p-1 )
		{
			mod=mulmod(mod,mod,p);
			tmp=tmp<<1;
		}
		if(mod!=p-1 && tmp%2==0)
		return false;
	}
	return true;
}

int main()
{
	l=(1<<30);
	m=0x7FFFFFFF;
	no=(1234567891)&m;
	printf("0");
	int cnt=0;
	for(LL i=2;i<1000000;i++)
	{
		if(i==1477566)
		printf("1");
		else
		printf("%d",miller(no,20));
		no=(no+1234567890)&m;
	}
	cout<<"\ncnt = "<<cnt;
	return 0;
}
