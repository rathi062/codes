#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int tre[8001][8001];
char a[5001][5001];
void update(int xlo,int xho,int ylo,int yho,int xn,int yn,int x1,int x2,int y1,int y2,int di)
{
	if ( xlo > x2 || xho < x1 )
	{
		return;
	}
	else if ( xlo >= x1 && xho <= x2 )
	{
		if ( ylo > y2 || yho < y1 )
		{
			return;
		}
		else if ( ylo >= y1 && yho <= y2 )
		{
			tre[xn][yn]+=di;
		}
		else
		{
			int midi = (ylo + yho)/2;
			update(xlo,xho,ylo,midi,xn,2*yn,x1,x2,y1,y2,di);
			update(xlo,xho,midi+1,yho,xn,2*yn+1,x1,x2,y1,y2,di);
		}
	}
	else
	{
		int mid = (xlo + xho)/2;
		update(xlo,mid,ylo,yho,2*xn,yn,x1,x2,y1,y2,di);
		update(mid+1,xho,ylo,yho,2*xn+1,yn,x1,x2,y1,y2,di);
	}
}
int query(int xlo,int xho,int ylo,int yho,int xn,int yn,int x1,int x2,int y1, int y2,int s)
{
	s+=tre[xn][yn];
	if ( xlo > x2 || xho < x1 )
	{
		return 0;
	}
	else if ( xlo >= x1 && xho <= x2 )
	{
		if ( ylo > y2 || yho < y1 )
		{
			return 0;
		}
		else if ( ylo >= y1 && yho <= y2 )
		{
			return s;
		}
		else
		{
			int midi = (ylo + yho)/2;
			return query(xlo,xho,ylo,midi,xn,2*yn,x1,x2,y1,y2,s)+query(xlo,xho,midi+1,yho,xn,2*yn+1,x1,x2,y1,y2,s);
		}
	}
	else
	{
		int mid = (xlo + xho)/2;
		return query(xlo,mid,ylo,yho,2*xn,yn,x1,x2,y1,y2,s)+query(mid+1,xho,ylo,yho,2*xn+1,yn,x1,x2,y1,y2,s);
	}
}
int main()
{
	int m, n, i, j;
	scanf("%d%d",&m,&n);
	for ( i = 0; i < m; i++ )
	{
		scanf("%s",a[i]);
	}
	int c;
	char d[6];
	char str[] = "NESW";
	int g[200];
	g['N']=0;
	g['E']=1;
	g['S']=2;
	g['W']=3;
	scanf("%d",&c);
	memset(tre,0,sizeof(tre));
	while ( c-- )
	{
		scanf("%s",d);
		if ( !strcmp(d,"C") )
		{
			int x1,x2,y1,y2,di;
			scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&di);
			if ( x2 > m)
			x2=m;
			if ( y2 > n)
			y2 = n;
			if ( di == 0 )
			update(1,m,1,n,1,1,x1,x2,y1,y2,1);
			else
			update(1,m,1,n,1,1,x1,x2,y1,y2,-1);
		}
		else if ( !strcmp(d,"D") )
		{
			int x,y;
			scanf("%d%d",&x,&y);
			int k = query(1,m,1,n,1,1,x,x,y,y,0);
			k%=4;
			k=(k+g[a[x-1][y-1]])%4;
			k+=4;
			k%=4;
			printf("%c\n",str[k]);
		}
	}
	return 0;
}
