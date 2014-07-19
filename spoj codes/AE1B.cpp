#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int a,b,c,max=0,i,j,k=1,sum=0;
    cin>>a>>b>>c;
    int p[a];
    for(i=0;i<a;i++)
    {     
          cin>>p[i];
          if(p[i]>max)
          {max=p[i];
           j=i;}
    }
    sum+=max;
    p[j]=0;
    
    while(sum<(b*c))
    {
                    max=0;
                    for(i=0;i<a;i++)
                    {
                                    if(p[i]>max)
                                    {
                                                max=p[i];
                                                j=i;
                                    }
                    }
                    k++;
                    sum+=max;
                    p[j]=0;
    }
    cout<<k;
    getch();
    return 0;
}
                                    
    
