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
#define MAX(a,b) return a>b?a:b
#define MIN(a,b) return a<b?a:b
#define getcx getchar_unlocked
using namespace std;
long long mx,cnt,mid,last=0,beg=0,sum=0;
int n,k; 
 /*inline void inp( int &n ) 
 {
    n=0;
    int ch=getcx();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
 
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
  }*/
char s[100];
char* fun(void)
{
	int l=strlen(s),mid=0,i,j,c=0,cr=0;
       //cout<<l;
       if(l%2==1)
       {
           mid=l/2;
           i=mid-1;
           j=mid+1;
           while(i>=0)
           {
                if(s[i]>s[j])
                {
                    c=1;
                    break;
                }
                else
                if(s[i]==s[j])
                {
                     i--;
                     j++;
                }
                else
                break;
           }
           //cout<<"\ncase : "<<c;
           if(c==0)
           {
                cr=1;
                for(int k=mid;k>=0;k--)
                {
                        if(cr==1)
                        {
                             if(s[k]=='9')
                                 s[k]='0';
                             else
                             {
                                 s[k]++;
                                 cr=0;
                                 break;
                             }
                        }
                }
           }
           for(i=1;i<=mid;i++)
                s[mid+i]=s[mid-i];
           if(cr==1)
           {
                 s[0]='1';
                 s[l]='1';
				 //cout<<s<<"1\n";
           }
           return s;         
       }
       else
       {
           mid=l/2-1;
           i=mid;
           j=mid+1;
           while(i>=0)
           {
                if(s[i]>s[j])
                {
                    c=1;
                    break;
                }
                else
                if(s[i]==s[j])
                {
                     i--;
                     j++;
                }
                else
                break;
           }
           //cout<<"\ncase : "<<c;
           if(c==0)
           {
                cr=1;
                for(int k=mid;k>=0;k--)
                {
                        if(cr==1)
                        {
                             if(s[k]=='9')
                                 s[k]='0';
                             else
                             {
                                 s[k]++;
                                 cr=0;
                                 break;
                             }
                        }
                }
           }
           for(i=0;i<=mid;i++)
                s[mid+i+1]=s[mid-i];
           if(cr==1)
           {
                 s[0]='1';
                 s[l]='1';
                 //cout<<s<<"1\n";
           }
           return s;         
       }
	
}
int main()
{
    int t=0;
    scanf("%d",&t);
    while(t--)
    {
       cin>>s;
	   cout<<fun()<<endl;         
    }
    //system("pause");
    return 0;
}














