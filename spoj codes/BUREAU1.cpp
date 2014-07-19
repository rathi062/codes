#include<iostream>
  #include<stack>
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
    int t,n,i;
    inp(t);
    stack<int> st;
    while(t--)
    {
         inp(n);
         int a[n+1],cnt=0;
         char s[100];
         bool b[n+1];
         for(i=1;i<=n;i++)
         {
            scanf("%s",s);
            if(s[0]=='c')
            inp(a[i]);
            else
            a[i]=0;
            b[i]=false;
         }
         for(i=n;i>0;i--)
         {
                 if(b[i]==false)
                 {
                     if(a[i]!=0)
                          b[a[i]]=true;
                     if(a[i]!=(i))
                     {
                        st.push(i);
                        cnt++;
                     }
                 }
         }
         printf("%d\n",cnt);
         while(!st.empty())
         {
                 printf("%d ",st.top());
                 st.pop();
         }
         printf("\n");
    }
    return 0;
}                    
