#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    float i,w;
    cin>>i>>w;    
    while(i>=0&&w>=0)
    {
              if((i*37)==(w*1000))
              cout<<"Y\n";
              else
              cout<<"N\n";
              cin>>i>>w;
    }
    cout<<"N\n";
    getch();
    return 0;
}       
                       
