/**************** Q 3 the prime numbers between two numbers ****************/
#include <stdio.h>
int CheckNumber(int number);
int main()
{
    int number_1,number_2,i,num;
    printf("Enter the first number : ");
    scanf("%d",&number_1);
    printf("Enter the second number : ");
    scanf("%d",&number_2);
    printf("The prime numbers between %d and %d are ",number_1,number_2);
    for(i=number_1;i<=number_2;i++)
    {
        num=CheckNumber(i);
        if (num==0)
        {
            printf("%d ",i);
        }

    }


   return 0;
}
int CheckNumber(int number)
{
    int check=0,i;
    for(i=2;i<=number/2;i++)
    {
        if ((number%i)==0)
        {
            check=1;
            break;
        }
    }
    return check;
}
