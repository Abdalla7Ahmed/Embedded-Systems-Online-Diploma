

/* ##################### << EXAMPLE 4 >> ############################*/
#include <stdio.h>
int main ()
{
    float number;
    printf("Enter a number : ");
    scanf("%f",&number);
    if (number >0)
    {
        printf("%.2f is positive ", number);
    }
    else if (number <0)
    {
        printf("%.2f is negative ", number);
    }
    else
    {
        printf("You entered zero");
    }
}









