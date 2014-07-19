#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int  t,a,b,max=0,i,j,k=1,sum=0;
    cin>>t;
    for(int l=0;l<t;l++)
    {
            k=1;
            cin>>a>>b;
            int p[b];
            for(i=0;i<b;i++)
            {            
                         cin>>p[i];
                         if(p[i]>max)
                         {max=p[i];
                         j=i;}
            }
            sum+=max;
            p[j]=0;
    
            for(int q=0;q<b;q++)
            {
                    max=0;
                    for(i=0;i<b;i++)
                    {
                                    if(p[i]>max)
                                    {
                                                max=p[i];
                                                j=i;
                                    }
                    }
                    k++;
                    sum+=max;
                    if(sum>=a)
                    {
                              j=-1;
                              break;
                    }
                    p[j]=0;
            }
            
            cout<<"Scenario #"<<(l+1)<<":"<<endl;
            if(j!=-1)
            {
                    cout<<"impossible"<<"\n\n";
            }
            else
            {
                    cout<<k<<endl<<endl;
            }
    }
    getch();
    return 0;
}
                                    
    
