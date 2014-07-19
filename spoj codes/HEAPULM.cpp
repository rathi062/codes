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
struct Node{
    queue<pair<int,string> > q;
    int n;
}nod[MX*4];

int no[4*MX],prob[4*MX];
string nm[4*MX];
bool lazy[4*MX];

void insert(int idx, int st, int ed)
{
    if(st==ed)
    {
        //cout<<"\nst = "<<st; 
        nod[idx].q.push(pair<int ,string> (no[st],"op") );
        nod[idx].q.push(pair<int ,string> (no[st],"no") );
        nod[idx].q.push(pair<int ,string> (no[st],"cl") );
        nod[idx].n=1;
        return;
    }
    int lft=idx*2, rgt=lft+1;
    int mid=(st+ed)/2;
    insert(lft, st, mid);
    insert(rgt, mid+1, ed);
    int sl,sr,sz,l;
    sl=nod[lft].q.size();
    sr=nod[rgt].q.size();
    sz=sl+sr;
    nod[idx].n=nod[lft].n+nod[rgt].n;
    //cout<<"\nst = "<<st<<" ed = "<<ed;
    while(nod[rgt].q.front().first>nod[lft].q.front().first&&nod[rgt].q.front().second=="op")
    {
        nod[idx].q.push(nod[rgt].q.front());
        //cout<<"\nno = "<<nod[rgt].q.front().first<<" str = "<<nod[rgt].q.front().second;
        nod[rgt].q.pop();
        sz--;
    }
    l=nod[lft].q.front().first;
    while(1)
    {
        nod[idx].q.push(nod[lft].q.front());
        //cout<<"\nno = "<<nod[lft].q.front().first<<" str = "<<nod[lft].q.front().second;
        sz--;
        if(nod[lft].q.front().second=="no")
        nod[lft].n--;
        //cout<<"\nn = "<<nod[lft].n;
        nod[lft].q.pop();
        if(nod[lft].n<=0)
        break;
    }
    while(sz--)
    {
        //cout<<"\nlast";
        if(nod[rgt].q.front().first<nod[lft].q.front().first)
        {
             nod[idx].q.push(nod[rgt].q.front());
             //cout<<"\nno = "<<nod[rgt].q.front().first<<" str = "<<nod[rgt].q.front().second;
             nod[rgt].q.pop();
             if(nod[rgt].q.empty())
             {
                 while(!(nod[lft].q.empty()))
                 {
                    nod[idx].q.push(nod[lft].q.front());
                    //cout<<"\nno = "<<nod[lft].q.front().first<<" str = "<<nod[lft].q.front().second;
                    nod[lft].q.pop();
                 }
                 break;
             } 
        }
        else
        {
             nod[idx].q.push(nod[lft].q.front());
             //cout<<"\nno = "<<nod[lft].q.front().first<<" str = "<<nod[lft].q.front().second;
             nod[lft].q.pop();
             if(nod[lft].q.empty())
             {
                 while(!(nod[rgt].q.empty()))
                 {
                    nod[idx].q.push(nod[rgt].q.front());
                    //cout<<"\nno = "<<nod[rgt].q.front().first<<" str = "<<nod[rgt].q.front().second;
                    nod[rgt].q.pop();
                 }
                 break;
             }
        }
    }
    return;
}

int main()
{
    int  n, i, q, cnt=0, st, ed,val,w,t;
    inp(n);
    char *p,s[100];
    while(n)
    {
        for(i=0;i<n;i++)
        {
            cin>>s;
            p=strtok(s,"/");
            nm[i]=p;
            p=strtok(NULL,"/");
            int l=strlen(p),a=0,c=0;
            for(int j=0;j<l;j++)
            {
               a=p[j]-48;
               c=c*10+a;
            }
            no[i]=c;
            prob[c]=i;
            //cout<<"\nno = "<<no[i]<<" nm = "<<nm[i];
        }
        insert(1,0,n-1);
        i=0;
        while(!(nod[1].q.empty()))
        {
                    if(nod[1].q.front().second=="op")
                    printf("(");
                    else
                    if(nod[1].q.front().second=="cl")
                    printf(")");
                    else
                    cout<<nm[i++]<<"/"<<nod[1].q.front().first;
                    nod[1].q.pop();
        }
        cout<<endl;
        inp(n);
    }
    return 0;
}


