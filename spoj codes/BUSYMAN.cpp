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
int a[100001],e[100001];
int main()
{
    int t,n,st,nd,i,max,sum,str;
    inp(t);
    while(t--)
    {
         multimap<int,int >  m;
         multimap<int,int >::iterator it,ita,l;
         inp(n);
         for(i=0;i<n;i++)
         {
            inp(st);
            inp(nd);
            m.insert(std::pair<int,int >(st,nd) );
         }
         max=0;
          //for(it=m.begin();it!=m.end();it++)
          //   cout<<(*it).first<<" "<<(*it).second.first<<" "<<(*it).second.second<<endl;
         it=m.end();
         it--;
         l=m.begin();
         l--;
         str=100000000;
         for(;it!=l;it--)
         {
              st=(*it).first;
              nd=(*it).second;
              if(nd<=str)
              {
                 str=st;
                 max++;
              }
         }
         printf("%d\n",max);
         /*cout<<"after calcualtion : \n";
         for(it=m.begin();it!=m.end();it++)
              cout<<(*it).first<<" "<<(*it).second.first<<" "<<(*it).second.second<<endl;
         */
    }
    return 0;
}
