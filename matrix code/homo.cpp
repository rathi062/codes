#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;

int n=4,i,j,k;
const int nn=4;
float a[nn][2*nn],aa[nn][nn],b[nn][1],c[nn][nn],t[nn][nn],sum=0,l,m;

void inverse(void)
{
    for( i=0;i<n;i++)
    {
        float num=a[i][i];
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
          return ;
        }
    }
}
int main()
{
    for(i=0;i<n;i++) 
    {
      for(j=0;j<n;j++)   
      {
         cin>>a[i][j];
         t[j][i]=a[i][j];
         aa[i][j]=a[i][j];
      }
      for( j=0;j<n;j++)
      {
                    if(i==j)
                    a[i][n+j]=1;
                    else
                    a[i][n+j]=0;
      }
    }
    
    for(i=0;i<n;i++)  { cin>>b[i][0];}
    n=3;
    for(i=0;i<n;i++)
    {
       sum=0;
       for(j=0;j<n;j++)
       sum+=a[i][j]*a[i][j];
       if(sqrt(sum)!=1)
       {
          
          cout<<"ROW entered matrix is not orthogonal !!! \n";
          break;
       }
    }
    for(j=0;j<n;j++)
    {
       sum=0;
       for(i=0;i<n;i++)
       sum+=a[i][j]*a[i][j];
       if(sqrt(sum)!=1)
       {
          cout<<"COLUMN entered matrix is not orthogonal !!! \n";
          break;
       }
    }
    inverse();
    n=4;
    for(i=0;i<n;i++)
    {
                    sum=0;
                    for(j=0;j<n;j++)
                    {
                          sum+=aa[i][j]*b[j][0];
                    }
                    c[i][0]=sum;
    }
    for(j=0;j<n;j++)
    {
       cout<<c[j][0]<<" ";
    }
     getch();
     return 0;
}

