
/**************** Q 5 count number of ones in binary ****************/
#include <stdio.h>
int number_of_ones(int number);
int main()
{
    int number;
    printf("Enter the number : ");
    scanf("%d",&number);
    printf("The number of ones in %d is %d ", number,number_of_ones(number));
   return 0;
}
int number_of_ones(int number)
{
    int counter=0;
    for(;number>0;number>>=1)
    {
        if (number&1)
        {
            counter++;
        }
    }
    return counter;
}
