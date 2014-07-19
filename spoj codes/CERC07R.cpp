#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
int main()
{
    string l1,l2,n1,n2,c1,c2;
    cin>>l1>>n1>>l2>>n2;
    do
    {
                 int s1=0,s2=0,t1=0, t2=0,lc1=0,lc2=0;
                 if(l1=="cs")
                 
                 cin>>c1>>c2;
                 
                 while(1)
                 {
                         /*switch(l1)
                         {
                         case 'cs':
                              if(c1==Kamen)
                              t1=1;
                              else
                              if(c1==Nuzky)
                              t1=2;
                              else
                              t1=3;
                              break;
                              
                         case 'en':
                              if(c1==Rock)
                              t1=1;
                              else
                              if(c1==Scissors)
                              t1=2;
                              else
                              t1=3;
                              break;
                       case 'fr':
                              if(c1==Pierre)
                              t1=1;
                              else
                              if(c1==Ciseaux)
                              t1=2;
                              else
                              t1=3;
                              break;
                       case 'de':
                              if(c1==Stein)
                              t1=1;
                              else
                              if(c1==Schere)
                              t1=2;
                              else
                              t1=3;
                              break;
                       case 'hu':
                              if(c1==Ko||c1==Koe)
                              t1=1;
                              else
                              if(c1==Ollo||c1==Olloo)
                              t1=2;
                              else
                              t1=3;
                              break;
                       }*/
                       cout<<"\nc1 : "<<c1;
                       cin>>c1;
                       if(c1=="-"||c1==".")
                       break;
                       else
                       cin>>c2;
                 }
    }
    while(c1!=".");
    getch();
    return 0;
}
    
