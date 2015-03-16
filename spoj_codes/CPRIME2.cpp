#include<iostream>
  #include<vector>
  #include<set>
  #include<map>
  #include<queue>
  #include<stack>
  #include<string>
  #include<algorithm>
  #include<functional>
  #include<iomanip>
  #include<cstdio>
  #include<cmath>
  #include<cstring>
  #include<cstdlib>
  #include<cassert>
#define R return
#define FR(i,a,b) for(int i=a;i<b;i++)
#define IN(i,j) a[i][j]
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define inp(x) scanf("%d",&x)
#define getcx getchar_unlocked
using namespace std;
 /*inline void inp( int &n ) 
 {
    n=0;
    int ch=getcx();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
 
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
  }*/
vector<int> a;
map<int,bool> v;
int main()
{
    int i,t,n,strt,max=0,lim;
    double r,res;
    a.assign(100000001,0);
    //cout<<"\nassingment complete !!";
    v[1]=true;
    v[0]=true;
    for( i=2;i<=10000;i++)
    {
          if(v[i]==false)
          {
            strt=i*i;
            for(int j=strt;j<=100000000;j+=i)
                  v[j]=true;
          }
    }
    //cout<<"\nprime generated ";
    for(int i=2;i<=max;i++)
    {
      if(v[i]==false)
          a[i]=a[i-1]+1;
      else
          a[i]=a[i-1];
      //cout<<"i = "<<i<<" a[i] = "<<a[i]<<endl;
    }
    inp(n);
    while(n!=0)
    {
        res=(n/log(n));
        r=abs(a[n]-res);
        r=r/a[n];
        r*=100;
        printf("%.1f\n",r);
        inp(n);
    }
    return 0;
}
