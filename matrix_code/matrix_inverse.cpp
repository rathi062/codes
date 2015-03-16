# include <iostream>
# include <conio.h>
using namespace std;
int main()
{
     int n;
     float l,m;
    cout<<"entr the size of the sqr matrix:";
    cin>>n;
    float a[n][2*n];
    cout<<"entr the elements of matrix"<<endl;
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<n;j++)
            {
                    cin>>a[i][j];
            }
    }
    for(int i=0;i<n;i++)
    {
            for(int j=n;j<2*n;j++)
            {
                    if(i==j-n)
                    a[i][j]=1;
                    else 
                    a[i][j]=0;
            }
    }
   for(int i=0;i<n;i++)
    {
            if(a[i][i]==0)
            {
                          for(int j=0;j<n;j++)
                          {
                                  if(a[j][i]!=0)
                                  {
                                                for(int k=0;k<2*n;k++)
                                                {
                                                        a[i][k]=a[i][k]+a[j][k];
                                                }
                                                i--;
                                                break;
                                  }
                                  if(j==n-1);
                                  {
                                             cout<<endl<<"****inverse does not exist****"<<endl;
                                             return 0;
                                             getch();
                                  }
                          }
            }
            else
            {
                          l=a[i][i];
                          for(int j=0;j<n;j++)
                          {
                                  if(i!=j)
                                  {
                                         m=a[j][i];
                                         for(int k=0;k<2*n;k++)
                                         {
                                             a[j][k]=(l*a[j][k])-(m*a[i][k]);
                                         }
                                  }
                          }
            }
    }
    cout<<endl<<"****inverse of matrix****"<<endl;
    for(int i=0;i<n;i++)
    {
            for(int j=n;j<2*n;j++)
            {
                    a[i][j]=a[i][j]/a[i][i];
                    cout<<a[i][j]<<"  ";
            }
            cout<<endl;
    }
    getch();
}
