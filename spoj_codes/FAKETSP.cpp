#include<iostream>
#include<conio.h>
#include<string>
#include<math.h>
using namespace std;
int main()
{
    char s[50],c;
    int in =0;
    double sum=0,x=0,y=0;
    long double a=0,b=0;
    cin.getline(s,50,'(');
    cin>>x>>c>>y;
    while(!cin.getline(s, 50,'(').eof())
    {
              a=0,b=0;             
             cin>>a>>c>>b;
                 sum+=sqrt((x-a)*(x-a)+(y-b)*(y-b));
                 x=a;
                 y=b;
                 printf("The salesman has traveled a total of %.3f kilometers.\n",sum); 
    }
    getch();
    return 0;
}
