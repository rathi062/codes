#include<stdio.h>
#include<algorithm>

#define MX 140000
#define MXT 280000
#define MOD 1000000007

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
struct Node{
    int mx1,mx2;
}nod[MXT];
int a[MX];
void insert(int idx, int st, int ed)
{
    if(st==ed)
    {
        nod[idx].mx1=a[st];
        nod[idx].mx2=0;
        return;
    }
    int lft=idx<<1, rgt=lft+1, mid=(st+ed)>>1,t[4];
        insert(lft, st, mid);
        insert(rgt, mid+1, ed);
    t[0]=nod[lft].mx1 , t[1]=nod[lft].mx2;
    t[2]=nod[rgt].mx1 , t[3]=nod[rgt].mx2;
    sort(t,t+4);
    nod[idx].mx1=t[3] , nod[idx].mx2=t[2];
        //cout<<"\nst = "<<st<<" ed = "<<ed<<" mx1 = "<<nod[idx].mx1<<" mx2 = "<<nod[idx].mx2;
    return;
}
void update(int idx, int st, int ed,int i,int val)
{
    if(st==i&&ed==i)
    {
        a[i]=val;
        nod[idx].mx1=val;
        nod[idx].mx2=0;
        return;
    }
    int lft=idx<<1, rgt=lft+1,mid=(st+ed)>>1,t[4];
    if(i<=mid) update(lft, st, mid,i,val);
    else update(rgt, mid+1, ed,i,val);
    t[0]=nod[lft].mx1, t[1]=nod[lft].mx2;
    t[2]=nod[rgt].mx1, t[3]=nod[rgt].mx2;
    sort(t,t+4);
    nod[idx].mx1=t[3],nod[idx].mx2=t[2];
    //cout<<"\nst = "<<st<<" ed = "<<ed<<" mx1 = "<<nod[idx].mx1<<" mx2 = "<<nod[idx].mx2;
    return;
}

void query(int idx, int st , int ed, int s, int e,int &mx1,int &mx2)
{
    if(st==s && ed==e||st==ed) { mx1=nod[idx].mx1 , mx2 = nod[idx].mx2;  return ; }

    //if(lazy[idx]) update_lazy(idx, st, ed);
    int lft=idx<<1,rgt=lft+1,t[4],mid=(st+ed)>>1;
    if(mid>=e)  query(lft, st, mid, s, e,mx1,mx2);
    else if(s>mid)  query(rgt, mid+1, ed, s, e,mx1,mx2);
    else
    {
         
         query(lft, st, mid, s, mid,mx1,mx2);
         t[0]=mx1, t[1]=mx2;
         query(rgt, mid+1, ed, mid+1, e,mx1,mx2);
         t[2]=mx1, t[3]=mx2;
         sort(t,t+4);
         mx1=t[3],mx2=t[2];
    }
}

int main()
{
    int  n, i, q, st, ed,val,mx1,mx2;
    //cin>>n;
      char cr[4];
      inp(n);
      for(i=0;i<n;i++)
            inp(a[i]);
      insert(1, 0, n-1);
       inp(q);
       while(q--)
       {
        scanf("%s",cr);
        inp(st);
        inp(ed);
        if(cr[0]=='Q')
        {
            query(1, 0, n-1, st-1, ed-1,mx1,mx2);
            printf("%d\n",(mx1+mx2));
        }
        else
             update(1,0,n-1,st-1,ed);
       }
    return 0;
}


