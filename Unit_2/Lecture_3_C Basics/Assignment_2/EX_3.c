

/* ##################### << EXAMPLE 3 >> ############################*/
#include <stdio.h>
int main ()
{
    float x,y,z;
    printf("Enter three numbers : ");
    scanf("%f %f %f",&x,&y,&z);
    if ((x>y)&&(x>z))
        {
            printf ("Largest number = %.2f",x);
        }
    else if ((z>x)&&(z>y))
    {
            printf ("Largest number = %.2f",z);
    }
    else
    {
            printf ("Largest number = %.2f",y);
    }
}




