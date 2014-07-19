#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
   char *s;
   while(scanf("%s",s)!=EOF)
   { 
    int l=5;//s.size();
    int in=-1,k=0,j=l-1;
    char a[l];
    for(int i=0;i<l;i++)
    {
            if(s[i]!=s[j])
            {
                 in=k;
                 a[k++]=s[i];
                 j=l-1;
            }
            else
            {
                if(i>=j)
                break;
                else
                {
                    a[k++]=s[i];
                    j--;
                }
            }
    }
    cout<<s;
    for(int i=in;i>=0;i--)
    {
            cout<<a[i];
    }
    cout<<endl;
   }
   getch();
   return 0;
}
    
