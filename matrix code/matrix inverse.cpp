/*++++++++++++++++++++++++++++++++++ MATRIX INVERSE METHOD ++++++++++++++++++++++++++++
  
   --------------------BY Mohit Rathi (RIT2010062)-------------------------
   
     In this code , first we enterd the numbers of variables then 
        elements And after this we give the solution for
           this problem .                           
  */
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n=0,i=0,j=0,k=0;
    cout<<"enter the size of matrix : ";
    cin>>n;
    float a[n][2*n];
    cout<<"\nenter the elements of matrix ";
    for( i=0;i<n;i++)
    {
            for( j=0;j<n;j++)
            cin>>a[i][j];
            for( j=0;j<n;j++)
            {
                    if(i==j)
                    a[i][n+j]=1;
                    else
                    a[i][n+j]=0;
            }
    }
    for( i=0;i<n;i++)
    {
        int num=a[i][i];
        float m=0.0;
        if(num==0)
        {
            for(int l=i;l<n;l++)
            {
               if(a[l][i]!=0)
               {
                  for(int f=0;f<2*n;f++)
                  a[i][f]+=a[l][f];
                  break;
               }
            }
        }
        if(a[i][i]!=0)
        {
            num=a[i][i];
            for(j=0;j<(2*n);j++)
            {
              if(j==i)
              a[i][j]=1;
              else
              a[i][j]/=num;
            }
            for(j=0;j<n;j++)
            {
               if(j!=i)
               {
                     m=a[j][i];
                     for(k=0;k<2*n;k++)
                     {
                           a[j][k]=a[j][k]-a[i][k]*m;
                     }
               }
            }
            cout<<endl;
        }
        else
        {
          cout<<"inverse does not exist : ";
          getch();
          return 0;
        }
    }
    for(int i=0;i<n;i++)
    {
            for(int j=n;j<2*n;j++)
            printf("%.2f  ",a[i][j]);
            cout<<endl;
    }
    getch();
    return 0;
}
