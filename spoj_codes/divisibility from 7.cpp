#include<stdio.h>
#include<conio.h>
int main()
{
int i,c,n; printf("Enter the number of terms you want which are divisible by 7");
scanf("%d",&n);
c=0;
for(i=7;;i+=7)
{
printf("\n %d ",i);
c++;
if(c==n)
break;
}
getch();
return 0;
}

//Read more: http://wiki.answers.com/Q/C_program_to_find_numbers_divisible_by_7#ixzz1gVOUlUjU
