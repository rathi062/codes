#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            float n=0,c=0;
            string s;
            cin>>n>>s;
            if(s=="kg")
            {
                c=n*2.2046;       
            
                printf("%d %.4f lb",i+1,c);
            }
            if(s=="lb")
            {
              c=n*0.4536;
              printf("%d %.4f kg",i+1,c);
            
            }
            if(s=="l")
            {
                      c=n*0.2642;
                      printf("%d %.4f g",i+1,c);
            
            }
            if(s=="g")
            {
                      c=n*3.7854;
                      printf("%d %.4f l",i+1,c);
                     
            }
            cout<<endl;
    }
    getch();
    return 0;
}
