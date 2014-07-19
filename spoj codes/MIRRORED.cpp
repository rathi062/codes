#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    string s;
    
    s[0]=' ';
    s[1]=' ';
    cout<<"Ready";
    while(1)
    {
            getline(cin,s);
            if(s[0]==' '&&s[1]==' ')
            break;
            if((s[0]=='p'&&s[1]=='q')||(s[0]=='q'&&s[1]=='p'))
            cout<<"\nMirrored pair";
            else
                if((s[0]=='b'&&s[1]=='d')||(s[0]=='d'&&s[1]=='b'))
                cout<<"\nMirrored pair";
                else
                cout<<"\nOrdinary pair";
    }
    getch();
    return 0;
}
