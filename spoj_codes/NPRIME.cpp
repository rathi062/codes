#include<iostream>
#define MX 1300000
int c[MX],i,j,k;
int main()
{
	for(i=1,k=1;i<MX;)
	if(!c[++i]){
	c[k++]=i;
	for(j=i;j<MX;j+=i)
	c[j]=1;
	}
 	while(std::cin>>i)
	std::cout<<c[i]<<"\n";
}
