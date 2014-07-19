#include<iostream>
#include<conio.h>
using namespace std;
void num(int a[],int &i,int r)
{
     switch(r)
           {
                     case 1 : 
                            a[i]=2;
                               break;
                     case 2 :
                          a[i]=3;
                               break;
                     case 3 : 
                          a[i]=5;
                              break;
                     case 4 : 
                          a[i]=7;
           }
}           

int main()
{
    int r,a[10],p;
    long long n,o=5;
    cin>>p;
    if(p<2000)
    {
    for(int j=0;j<p;j++)
    {
            int i=0;
            cin>>n;
       while(1)
       {
               if(n==0)
               {
                       break;
                       }  
           if(n<=4&&n>0)
           {
                  i=i+1;
                  num(a,i,n);
                  break;
           }
              i++;
           o=n/4;
           r=n%4;                                                              
           if(r==0)
           {
                   r=4;
                   o=o-1;    
           }
           n=o;
           num(a,i,r);   
       }
       
       for(;i>0;i--)
       {
                  cout<<a[i];
       }
       cout<<endl;
    }
    }
    getch();
    return 0;
} 
           
