#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
int main()
{
    int r=0,b=0;
    cin>>r>>b;
    int l=0,w=0;
    l=((r/2)+2+sqrt(((r/2)+2)*((r/2)+2)-4*(r+b)))/2;
    w=(r/2)-l+2;
    cout<<l<<" "<<w;
    getch();
    return 0;
}
