#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n=1;
    cin>>n;
    while(n!=0)
    {
               float a[n][2];
               int c=0;
               for(int i=0;i<n;i++)
               {
                       cin>>a[i][0]>>a[i][1];
               }
               float s[n*(n+1)/2],sl=0,p=0;
               for(int i=0;i<n-1;i++)
               {
                       for(int j=i+1;j<n;j++)
                       {
                               p=0;
                              sl=float(a[i][1]-a[j][1])/(a[i][0]-a[j][0]);
                              
                              for(int k=0;k<c;k++)
                              {
                                      if(sl==s[k])
                                      {
                                                 p=1;
                                                 
                                                 break;
                                      }
                              }
                              if(p!=1)
                              {
                                     s[c]=sl;
                                     
                                     c++;
                              }
                       }
               }
               cout<<endl<<c<<endl;
               cin>>n;
    }
    getch();
    return 0;
}
                                         
