#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n,ga,ma;
    cout<<"enter no of cases : ";
    cin>>n;
    for(int j=0;j<n;j++)
    {
            cout<<"\nenter no of monsters in godzilla's army : ";
            cin>>ga;
            cout<<"\nenter no of monsters in mechagodzilla's army : ";
            cin>>ma;
            int a[ga],b[ma],max1=0,max2=0;
            cout<<"\nenter godzilla's army stringth ";
            for(int i=0;i<ga;i++)
            {
                    cin>>a[i];
                    if(max1<a[i])
                    max1=a[i];
            }
            cout<<"\nenter mechagodzilla's army stringth ";
            for(int i=0;i<ma;i++)
            {
                    cin>>b[i];
                    if(max2<b[i])
                    max2=b[i];
            }
            if(max1>=max2)
            {
                         cout<<"\nGodzilla";
            }
            else
            {   
                cout<<"\nMechagodzilla";
            }
    }
    getch();
    return 0;
}
