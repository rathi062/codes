#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            int n=0;
            cin>>n;
            string s[n];
            int r[n],c[n+1],p[n],e=0;
            for(int j=0;j<n;j++)
            {
                    cin>>s[j]>>r[j];
                    if(c[r[j]]!=1)
                    {
                       c[r[j]]=1;
                       p[j]=1;
                    }
                    else
                    p[j]=0;
            }
            /*for(int j=0;j<=n;j++)
            if(p[j]==1)
            cout<<j;*/
            for(int j=0;j<n;j++)
            {
                    if(p[j]!=1)
                    {
                               //cout<<"\ncase : "<<j<<" rank : "<<r[j];
                               for(int k=1;k<=n;k++)
                               {
                                       e++;
                                       if((r[j]+k)<(n+1))
                                       {
                                                 if(c[r[j]+k]!=1)
                                                 {c[r[j]+k]=1;
                                                 //cout<<" nw rank is : "<<r[j]+k;    
                                                 break;}
                                                 else
                                                 {
                                                     if((r[j]-k)>0)
                                                     {
                                                            if(c[r[j]-k]!=1)
                                                            {c[r[j]-k]=1;
                                                            //cout<<" nw rank is : "<<r[j]-k;
                                                            break;}
                                                     }
                                                 }
                                       }
                                       else
                                       {
                                                     if((r[j]-k)>0)
                                                     {
                                                            if(c[r[j]-k]!=1)
                                                            {c[r[j]-k]=1;
                                                            //cout<<" nw rank is : "<<r[j]-k;
                                                            break;}
                                                     }
                                       }    
                               }
                               //cout<<" e = "<<e;
                    }
            }
            cout<<e<<endl;                       
    }
    getch();
    return 0;
}
            
