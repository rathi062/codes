#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int s[22]={0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946};
    long k,r,t,x,y,b,f;
    scanf("%ld",r);
    while(r!=0)
    {
               x=1;
               scanf("%ld,%ld",k,t);
               while(1)
               {
                  b=t-x*s[r];
                  if(b%(s[r+1]-1)==0)
                  {
                     y=b/(s[r+1]-1);
                     break;
                  }
                  x++;
               }
               f=y*s[r-1]+x*s[r-2];
               printf("%ld %ld %ld\n",x,y,k*f);
               scanf("%ld",r);
    }
    getch();
    return 0;
}

               
                  
