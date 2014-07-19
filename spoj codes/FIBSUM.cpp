#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
int main()
{
    int  s=0,n,i,now=1,next=1,temp=0;
    cout<<"\nenter number : ";
    cin>>n;
    now=((pow(((1+sqrt(5))/2),n)-pow(((1-sqrt(5))/2),n))/sqrt(5));
    next=((pow(((1+sqrt(5))/2),n+1)-pow(((1-sqrt(5))/2),n+1))/sqrt(5));
    cout<<"\nnow = "<<now<<"\nnext = "<<next;
    for(i=n;i<=n+9;i++)
    {     
                      cout<<" "<<now;
                      s+= now;
                      temp=now;
                      now =next;
                      next=next+temp;
                        
    }
    
    cout<<"\ns = "<<s<<"\nn = "<<n;
    cout<<"\nsum is = "<<(s+n);
    getch();
    return 0;
}
