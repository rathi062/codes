#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
#define p(x) printf("%d",x)
#define inp(x) scanf("%d",&x)
using namespace std;
struct item{
	int p,q;
}node[7][101];
bool ch[101][101];
int dp[101][101];
int n,t;
int fun(int i,int j)
{
	if(i>6)
	return 100000;
	if(j<1)
	return 0;
	if(ch[i][j]==1)
	return dp[i][j];
	ch[i][j]=1;
	int mx=0,val=0,qua=0;
	for(int x=1;x<=node[i][0].p;x++)
	{
		if(node[i][x].p<=j)
		{
			qua=fun(i+1,j-node[i][x].p);
			mx=min(node[i][x].q,qua);
			if(mx>val)
			val=mx;
		}
	}
	dp[i][j]=val;
	return dp[i][j];
}
int main()
{
	int type,p,q;
	inp(n);
	inp(t);
	while(n--)
	{
		inp(type);
		inp(p);
		inp(q);
		if(type>6||type<1)
		continue;
		node[type][0].p++;
		node[type][node[type][0].p].p=p;
		node[type][node[type][0].p].q=q;
	}
	
	/*for(int i=1;i<=6;i++)
	{
		cout<<"\ntype = "<<i<<" item is = "<<node[i][0].p;
		for(int j=1;j<=node[i][0].p;j++)
		cout<<"\n p = "<<node[i][j].p<<" q = "<<node[i][j].q;
	}*/
	printf("%d\n",fun(1,t));
	return 0;
}
