#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
struct node
{
       char info;
       node *a[26];
       int f,la;
       
}*ptr,*nwptr,*root,*temp;
node *create(char);
void search(char,int);
void display(node*,int[]);
int l=0,re=0;
int main()
{
    string s;
    
    int n=0;
    cin>>n>>l;
    while(n!=0||l!=0)
    {
    int p[n];
    nwptr=create('s');
    root=nwptr;
    for(int j=0;j<n;j++)
    {
     cin>>s;
     temp=root;
     for(int i=0;i<s.size();i++)
     {
            search(s[i],i);
     }
     p[j]=0;
    }
    display(root,p);
    for(int i=0;i<n;i++)
    cout<<p[i]<<endl;
    cin>>n>>l;
    }
    getch();
    return 0;
}
node *create(char c)
{
     ptr=new node;
     ptr->info=c;
     ptr->f=0;
     ptr->la=0;
     for(int i=0;i<26;i++)
     ptr->a[i]=NULL;
     return ptr;
}
void search(char ch,int k)
{
     int as=0;
     as=(int(ch)-65);   
            if(temp->a[as]==NULL)
            {
                  nwptr=create(ch);
                  temp->a[as]=nwptr;
                  temp=temp->a[as];
                  if(k==l-1)
                  temp->la=1;
            }
            else
            {
                temp=temp->a[as];
                if(k==l-1)
                {(temp->f)++;
                re++;}
            }
     
}
void display(node *root,int p[])
{
     if (root!=NULL)
     {
                    //cout<<root->info<<" ";
                    if(root->la==1)
                    {
                                   //cout<<root->f<<endl;
                                   p[(root->f)]++;
                    }
                    for(int i=0;i<26;i++)
                    display(root->a[i],p);
     }
}
