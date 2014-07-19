#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#define MX 140000
#define MXT 280000
#define MOD 1000000007
#define inp(x) scanf("%d",&x)
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
    vector<int> v;
    int n;
}nod[MXT];
int a[MX];
void insert(int idx, int st, int ed)
{
    if(st==ed)
    {
        nod[idx].n=1;
        nod[idx].v.assign(nod[idx].n,0);
        nod[idx].v[0]=a[st];
        return;
    }
    int lft=idx<<1, rgt=lft+1,r=0,l=0;
    int mid=(st+ed)>>1,t[4];
    insert(lft, st, mid);
    insert(rgt, mid+1, ed);
    nod[idx].n=nod[lft].n+nod[rgt].n;
    nod[idx].v.assign(nod[lft].v.begin(),nod[lft].v.end());
    nod[idx].v.insert(nod[idx].v.end(),nod[rgt].v.begin(),nod[rgt].v.end());
    //cout<<"\nst = "<<st<<" ed = "<<ed<<" n = "<<nod[idx].n<<endl;
    //for(int i=0;i<nod[idx].n;i++)
    //cout<<nod[idx].v[i]<<" ";
    return;
}
Node query(int idx, int st , int ed, int s, int e)
{
    //cout<<"\nst = "<<st<<" ed = "<<ed;
    if(st>=s && ed<=e||st==ed) { return nod[idx]; }
    Node p,q,rtn;
    int lft=idx<<1,rgt=lft+1;
    int mid=(st+ed)>>1;
    if(mid>=e) return query(lft, st, mid, s, e);
    else if(s>mid) return query(rgt, mid+1, ed, s, e);
    else
    {
         //cout<<"\ndivide ";
         p=query(lft, st, mid, s, e);
         q=query(rgt, mid+1, ed, s, e);
         //cout<<"\np = "<<p.n<<" q = "<<q.n;
         int l=0,r=0;
         rtn.n=p.n+q.n;
         rtn.v.assign(p.v.begin(),p.v.end());
         rtn.v.insert(rtn.v.end(),q.v.begin(),q.v.end());
         //for(int i=0;i<rtn.n;i++)
         //cout<<rtn.v[i]<<" ";
         return rtn;
    }
    
}

int main()
{
    int  n, i, q, st, ed,val,k;
     inp(n);
     inp(q);
      for(i=0;i<n;i++)
            inp(a[i]);
      insert(1, 0, n-1);
       Node rt; 
       while(q--)
       {
          inp(st);
          inp(ed);
          inp(k);
          rt=query(1, 0, n-1, st-1, ed-1);
          sort(rt.v.begin(),rt.v.end());
          cout<<rt.v[k-1]<<endl;
       }
    //system("pause");
    return 0;
}



