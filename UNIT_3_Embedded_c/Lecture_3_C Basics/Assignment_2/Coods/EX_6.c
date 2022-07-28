

/* ##################### << EXAMPLE 6 >> ############################*/
#include <stdio.h>
int main ()
{
    int integer,i,sum=0;
    printf("Enter an integer : ");
    scanf("%d",&integer);
    for(i=0;i<=integer;i++)
    {
        sum+=i;
    }
    printf("sum = %d",sum);
}

