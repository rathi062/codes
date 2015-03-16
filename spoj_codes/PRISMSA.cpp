#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
            float area=0.0,v=0.0;
            string s="10.39230";
            cin>>v;
            area=pow(((v*v)/4),1.0/3.0)*(10.392304845);
            printf("%f",area);
            cout<<endl;
    }
    getch();
    return 0;
}
            
            
            
