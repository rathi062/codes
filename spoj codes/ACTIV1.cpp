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
int main()
{
    int n,i;
    long long cnt,sum=0;
    inp(n);
    while(n!=-1)
    {
         int st[n],nd[n];
         multimap<int,pair<int,int> > m;
         multimap<int,pair<int,int> >::iterator it,ita,l,q;
         pair<int ,int> p;
         for( i=0;i<n;i++)
         {
            inp(st[i]);
            inp(nd[i]);
         }
         for( i=0;i<n;i++)
         {  
            p.first=nd[i];
            p.second=0;
            m.insert(pair<int ,pair<int,int> >(st[i],p) );
         }
         //cout<<"\ninput complete ";
         it=m.end();
         it--;
         q=it;
         l=m.begin();
         if(n==1)
         sum=1;
         else
         if(n==2)
         {
            if((*l).second.first<=(*q).first)
            sum=3;
            else
            sum=2;
         }
         else
         {
           sum=0;
           l--;
           for (; it!=l; it--)
           {
             //std::cout << it->first << " => " << it->second.first << '\n';
             cnt=0;
             for(ita=q;ita!=l;ita--)
             {
                  if((*it).second.first<=(*ita).first)
                       cnt+=(*ita).second.second;
                  else
                  break;
             }
             (*it).second.second=1+cnt;
             sum+=(cnt+1);
           }
         }
         //for (it=m.begin(); it!=m.end(); ++it)
         //std::cout << it->first << " => " << it->second.first <<" "<<it->second.second<<'\n';
         printf("%08lld\n",sum);
         inp(n);
    }
    return 0;
}





