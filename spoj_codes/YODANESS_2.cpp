#include<iostream>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
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

using namespace std;

#define INF (1<<29)
#define SET(a) memset(a,-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define CLR(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define PB push_back
#define FOR(i,n) for(int i = 0;i<n;i++)
#define PI acos(-1.0)
#define EPS 1e-9
#define MP(a,b) make_pair(a,b)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)
#define LL long long
#define MX 100000
#define MOD 1000000007

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
int a[MX],mx,b[MX];
string yd[MX],cr[MX];
map<string,int> m;
void merge(int,int,int);
void merge_sort(int low,int high)
{
   int mid;
   if(low<high)
   {
       mid=(low+high)/2;
       merge_sort(low,mid);
       merge_sort(mid+1,high);
       merge(low,mid,high);
   }
}
void merge(int low,int mid,int high)
{
   int h,i,j,k;
   h=low;
   i=low;
   j=mid+1;
   while((h<=mid)&&(j<=high))
   {
       if(a[h]<=a[j])
           b[i++]=a[h++];
       else
       {
           b[i++]=a[j++];
           mx+=(mid-h+1);
       }
   }
   if(h>mid)
       for(k=j;k<=high;k++)
          b[i++]=a[k];
   else
       for(k=h;k<=mid;k++)
           b[i++]=a[k];
   //cout<<"\nlow = "<<low<<" mid = "<<mid<<" high = "<<high<<" mx = "<<mx;
   for(k=low;k<=high;k++) a[k]=b[k];
}
     
int main()
{
    int t,n,idx,p,val;
    inp(t);
    while(t--)
    {
       CLR(a);
       m.clear();
       mx=0;
       inp(n);
       for(int i=1;i<=n;i++)
       cin>>yd[i];
       for(int i=1;i<=n;i++)
       {
           cin>>cr[i];
           m.insert(pair<string,int> (cr[i],i) );
       }
       for(int i=1;i<=n;i++)
            a[i]=m[yd[i]];
       merge_sort(1,n);
       printf("%d\n",mx);
    }
    
    return 0;
}
