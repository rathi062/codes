#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            string a[50];
            cin>>a[0];
            int l;
            l=a[0].size();
            for(int j=1;j<l;j++)
            cin>>a[j];
            int c=0,max=0,in=0;
            for(int j=0;j<l;j++)
            {
                    c=0;
                    for(int k=0;k<l;k++)
                    {
                            if(j!=k)
                            {
                                 if(a[j][k]=='N')
                                 {
                                     for(int q=0;q<l;q++)
                                     {
                                             if(a[k][q]=='Y'&&a[j][q]=='Y')
                                             {
                                                 c++;
                                                 break;
                                             }
                                     }
                                 }
                            }
                    }
                    if(max<c)
                    {
                        in=j;
                        max=c;
                    }
            }
            cout<<in<<" "<<max;
    }
    getch();
    return 0;
}
            
