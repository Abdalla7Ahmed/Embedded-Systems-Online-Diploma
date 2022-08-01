

/* ############# << Ex_2 Factorial of number using recursion  >> #######################*/
#include<stdio.h>
int fact(int x); // prototype    Declaration
int main()
{
    int number;
    printf("Enter a positive Entiger ");
    scanf("%d",&number);
    printf("Factorial of  %d  is  %d ",number,fact(number));
    return 0;
}
// Definiation of the function
int fact(int x)
{
    if (x!=1)
    {
        return x*fact(x-1);
    }
}
