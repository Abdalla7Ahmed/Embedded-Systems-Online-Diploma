

/* ##################### << EXAMPLE 6 >> ############################*/
#include <stdio.h>
int main ()
{
    float a,b,t;
    printf("Enter value of a : ");
    scanf("%f",&a);
    printf("Enter value of b : ");
    scanf("%f",&b);
    t=a;
    a=b;
    b=t;
    printf("After swapping, value of a = %.2f \n " , a);
    printf("After swapping, value of b =  %.2f" , b);
}

