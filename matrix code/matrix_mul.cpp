#include<iostream>
#include<conio.h>
using namespace std;

const int n=4;
float a[n][n],b[n][1],c[n][n],sum=0;

int main()
{
    int i,j,k;
    for(i=0;i<n;i++) for(j=0;j<n;j++) { cin>>a[i][j];}
    for(i=0;i<n;i++)  { cin>>b[0][i];}
    for(i=0;i<n;i++)
    {
       sum=0;
       for(j=0;j<n;j++)
       sum+=a[i][j];
       if(sum!=0)
       {
          cout<<"entered matrix is not orthogonal !!! \n";
          break;
       }
    }
    for(j=0;j<n;j++)
    {
       sum=0;
       for(i=0;i<n;i++)
       sum+=a[i][j];
       if(sum!=0)
       {
          cout<<"entered matrix is not orthogonal !!! \n";
          break;
       }
    }
    for(j=0;j<n;j++)
    {
       for(i=0;i<n;i++)
       if(a[i][j]!=a[j][i])
       {
          cout<<"entered matrix is not orthogonal !!! \n";
          break;
       }
    }
    for(i=0;i<n;i++)
    {
                    for(j=0;j<n;j++)
                    {
                                    for(k=0;k<n;k++)
                                    {
                                                    c[i][j]+=a[i][k]*b[k][j];
                                                    }
                                                    }
                                                    }
                                                    for(i=0;i<n;i++)
                                                    {
                                                                    for(j=0;j<n;j++)
                                                                    {
                                                                                    cout<<c[i][j]<<" ";
                                                                                    }
                                                                                    cout<<endl;
                                                                                    }
     getch();
     return 0;
}

