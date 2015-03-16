//
//  CHEFCH.cpp
//  
//
//  Created by mohit rathi on 10/02/15.
//
//
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
#define MX 100003
#define MOD 100000000

#define p(x) printf("%d",x)
#define inp(x) scanf("%d",&x)
#define inpd(x) scanf("%lf",&x)
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
long long a[MX];
void init(){
    for(int i=1;i<MX;i++){
        a[i]=a[i-1]+i;
    }
}
int search(int i,int j, long long remaining){
    
    if(i==j)
        return i;
    int mid = (i+j)/2;
    if(remaining == a[mid])
        return mid;
    if(a[mid]>remaining)
        return search(i,mid,remaining);
    else
        return search(mid+1,j,remaining);
    
}
int main()
{
    int t=0;
    long long s=0,maxSum=0,n;
    a[0]=0;
    init();
    inp(t);
    while (t--) {
        cin>>n>>s;
        int result = search(0,n,s-n);
        if(a[result] > (s-n))
            result--;
        int ans = n-result-1;
        cout<<ans<<endl;
    }
    return 0;
}
