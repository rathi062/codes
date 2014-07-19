#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n=0;
    cin>>n;
    while(n!=0)
    {
               int a[n][3],min[n],s1=0,s2=0,s3=0,c=1,sum=0;
               char ch='.';
               for(int i=0;i<n;i++)
               {
                       cin>>a[i][0]>>a[i][1]>>a[i][2];
                       s1=a[i][0];
                       s2=a[i][1];
                       s3=a[i][2];
                       if(s1<s2&&s1<s3)
                       min[i]=0;
                       if(s2<s1&&s2<s3)
                       min[i]=1;
                       if(s3<s2&&s3<s1)
                       min[i]=2;
               }
               sum=a[0][1];
               s2=1;
               for(int i=1;i<n-1;i++)
               {
                       
                    if(s2==1)
                    {
                             sum+=a[i][min[i]];
                             s2=min[i];
                             continue;
                    }
                    if(s2==0)
                    {
                             if(min[i]==0||min[i]==1)
                             {   
                                 sum+=a[i][min[i]];
                                 s2=min[i];
                                 continue;
                             }
                             else
                             {
                                 if(a[i][1]>(a[i-1][1]+a[i][2]))
                                 {
                                  sum+=a[i-1][1]+a[i][2];
                                  s2=2;
                                  continue;
                                 }
                                 else
                                 {
                                   sum+=a[i][1];
                                   s2=1;
                                   continue;
                                 }
                             }
                    }
                    if(s2==2)
                    {
                             if(min[i]==2||min[i]==1)
                             {   
                                 sum+=a[i][min[i]];
                                 s2=min[i];
                                 continue;
                             }
                             else
                             {
                                 /*if(a[i][1]>(a[i-1][1]+a[i][0]))
                                 {
                                  sum+=a[i-1][1]+a[i][0];
                                  s2=0;
                                  continue;
                                 }
                                 else
                                 {
                                   sum+=a[i][1];
                                   s2=1;
                                   continue;
                                 }*/
                                 sum+=a[i][1];
                                 s2=1;
                                 continue;
                             }
                    }
                    //cout<<"\ns2 = "<<s2;
               }
               cout<<c<<ch<<" "<<sum+a[n-1][1]<<endl;
               c++;
               cin>>n;
    }
    getch();
    return 0;
}
