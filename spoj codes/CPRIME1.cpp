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
map<int,bool> v;
map<int,int> m;
int main()
{
    int i,t,n,strt,max=0,lim,cnt=0;
    double r,res;
    queue<int> q;
    inp(n);
    while(n!=0)
    {
        m[n]=-1;
        q.push(n);
        if(max<n)
        max=n;
        inp(n);
    }
    v[1]=true;
    v[0]=true;
    lim=sqrt(max);
    for( i=2;i<=lim;i++)
    {
          if(v[i]==false)
          {
            strt=i*i;
            for(int j=strt;j<=max;j+=i)
                  v[j]=true;
          }
    }
    //cout<<"\nprime generated ";
    for(int i=1;i<=max;i++)
    {
      if(v[i]==false)
          cnt++;
      if(m[i]==-1)
       m[i]=cnt;
      //cout<<"i = "<<i<<" a[i] = "<<a[i]<<endl;
    }
    while(!q.empty())
    {
        n=q.front();
        res=(n/log(n));
        r=abs(m[n]-res);
        r=r/m[n];
        r*=100;
        printf("%.1f\n",r);
        q.pop();
    }
    inp(n);
    return 0;
}
