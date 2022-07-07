
/* ##################### << EXAMPLE 7 >> ############################*/
#include <stdio.h>
int main ()
{
    int integer,i,factorial=1;
    printf("Enter an integer number : ");
    scanf("%d",&integer);
    if (integer <0)
    {
        printf("Error!!Factorial of negative number doesnot exist");
    }
    else
    {
         for(i=integer;i>0;i--)
         {
             factorial*=i;
         }
         printf("Factorial = %d",factorial);
    }
}
