#include<iostream>
#include <stdlib.h>
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
#define mai3(a,b,c) mai(a,mai(b,c))
#define READ freopen("input.tit", "r", stdin)
#define WRITE freopen("output.tit", "w", stdout)
#define LL long long
#define MX 100005
#define MOD 1000000007

#define F first
#define S second
#define pii pair<int,int>
#define p(i) printf("%d",i)
#define inp(i) scanf("%d",&i)
#define inpll(i) scanf("%lld",&i)
#define getci getchar_unlocked
/*inline void inp( int &n )
 {
 n=0;
 int ch=getci();int sign=1;
 while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getci();}
 
 while(  ch >= '0' && ch <= '9' )
 n = (n<<3)+(n<<1) + ch-'0', ch=getci();
 n=n*sign;
 }*/

using namespace std;
char swp(char c){
    if(c=='1')
        return '0';
    else
        return '1';
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        int ans = 0;
        string s;
        cin>>n>>k>>s;
        long l = s.length();
        if(k==1){
            int cngs=0;
            for(int i=0;i<l;i++){
                if(int(s[i]-48) != i%2)
                    cngs++;
            }
            ans = cngs;
            cngs = 0;
            for(int i=0;i<l;i++){
                if(int(s[i]-48) == i%2)
                    cngs++;
            }
            if(cngs < ans){
                for(int i=0;i<l;i++)
                    if(i%2 == 0) s[i] = '1';
                    else s[i] = '0';
            }
            else{
                for(int i=0;i<l;i++)
                    if(i%2 == 0) s[i] = '0';
                    else s[i] = '1';
            }
            ans = min(ans,cngs);
        }
        else{
            int cnt = 1;
            char lst = s[0];
            for(int i=1;i<l;i++){
                if(s[i]==lst)
                    cnt++;
                else{
                    lst = s[i];
                    cnt = 1;
                }
                if(cnt > k){
                    if(i+1<l){
                        if(s[i+1]==lst){
                            s[i] = swp(lst);
                        }
                        else{
                            s[i-1] = swp(lst);
                        }
                        ans++;
                    }
                    else{
                        s[i] = swp(lst);
                        ans++;
                    }
                    cnt = 1;
                    lst = s[i];
                }
            }
        }
        cout<<ans<<endl<<s<<endl;
    }
    return 0;
}