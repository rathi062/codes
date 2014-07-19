#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n=0,m=0,i=0,j=0,k=0;
    cin>>n;
    while(n!=0)
    {
               int a[n];
               long long sum=0;
               for(i=0;i<n;i++)
               cin>>a[i];
               //cout<<"\nenter m : ";
               cin>>m;
               int b[m],s=0;
               for(i=0;i<m;i++)
               cin>>b[i];
               if(n>m)
               s=m;
               else
               s=n;
               //cout<<"\ns = "<<s;
               int c[s+1],s1[s+1],s2[s+1],l=0;
               for(i=0;i<=s;i++)
               {
                    c[i]=0;
                    s1[i]=0;
                    s2[i]=0;
               }
               k=0;
               for(i=0;i<n;i++)
               {
                               s2[k]=0;
                    for(j=l;j<m;j++)
                    {
                          if(b[j]==a[i])
                          {
                               l=j+1;
                               //cout<<"\nintersection : "<<a[i];
                               c[k++]=a[i];
                               s1[k]-=a[i];
                               break;
                          }
                          if(b[j]>a[i])
                          break;
                          s2[k]+=b[j];
                    }
                    s1[k]+=a[i];
               }
               s2[k]=0;
               for(i=l;i<m;i++)
               s2[k]+=b[i];
               for(i=0;i<k+1;i++)
               {      
                      cout<<"\nc="<<c[i]<<"   s1 = "<<s1[i]<<"    s2 = "<<s2[i];
                      sum+=c[i];
                      if(s1[i]>s2[i])
                      sum+=s1[i];
                      else
                      sum+=s2[i];
               }
               cout<<sum<<endl;       
               cin>>n;
    }
    getch();
    return 0;
}
