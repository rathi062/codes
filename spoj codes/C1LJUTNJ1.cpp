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
#define inpll(x) scanf("%lld",&x)
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
  /*inline void inpll( long long &n ) 
 {
    n=0;
    int ch=getcx();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
 
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
  }*/
int main()
{
    long long m,sum=0,avg,rem,p=0;
    int n,i,no;
    inpll(m);
    inp(n);
    vector<int> q;
    vector<int>::iterator it;
    q.assign(n,0);
    for( i=0;i<n;i++)
    {
        inp(no);
        sum+=no;
        q[i]=no;
    }
    sort(q.begin(),q.end());
    rem=sum-m;
    //cout<<"\nsum = "<<sum<<" rem = "<<rem;
    i=0;
    for(it=q.begin();it!=q.end();it++)
    {
       avg=rem/(n-i);
       //cout<<"\navg = "<<avg;
       if((*it)>=avg)
       {
          //cout<<" enough ";
          p+=(avg*avg);
          rem-=avg;
       }
       else
       {
           //cout<<" less ";
           avg=(*it);
           p+=avg*avg;
           rem-=avg;
       }
       i++;
       //cout<<"\nrem = "<<rem;
    }      
    printf("%lld\n",p);
    system("pause");
    return 0;
}
