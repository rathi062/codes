#include<iostream>
#include<conio.h>
#include<sstream>
#include<string>
using namespace std;
int main()
{
    char n[102];
//    char m[102];
    //string n;
    //scanf("%s",&n);
    //cout<<n;
    
    while((scanf("%s",n)!=EOF))
    {
                               int len = strlen(n);
                               //cout<<endl<<len;
                               //char m[len];                             
                               //m[len]='\0';
                                int c=0,b=1;
                for(int i=len-1;i>=0;i--)
                 {
                //int i=len-1;
                         stringstream out,out1;
                         int a=0;
                         out<<n[i];
                         //cout<<out.c_str();
                         out>>a;
                         //cout<<a;
                  //       a=a*2;
                    //     a=a+c;
                         //cout<<a;
                         if(a==0&&b==1){
                         	a=9;
                         	b=1;
                         	}
                         	else
                         	{
                         		a=a-b;
                         		b=0;
                         	}
                         
                      //   c=a/10;
                         out1<<a%10;
                         out1>>n[i];
                         //cout<<endl<<n[i];
                 }
                 //cout<<n;
                 for(int i=len-1;i>=0;i--)
                 {
                //int i=len-1;
                         stringstream out,out1;
                         int a=0;
                         out<<n[i];
                         //cout<<out.c_str();
                         out>>a;
                         //cout<<a;
                         a=a*2;
                         a=a+c;
                         //cout<<a;
                         /*if(a==0&&b==1){
                         	a=9;
                         	b=1;
                         	}
                         	else
                         	{
                         		a=a-b;
                         		b=0;
                         	}
                         */
                         c=a/10;
                         out1<<a%10;
                         out1>>n[i];
                         //cout<<endl<<n[i];
                 }
                 if(c==1)
                 cout<<c<<n<<endl;
                 
                 else
                 cout<<n<<endl;
    }
    getch();
    return 0;
}
