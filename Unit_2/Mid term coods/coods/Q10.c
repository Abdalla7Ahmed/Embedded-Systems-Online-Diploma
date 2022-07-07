
/**************** Q10  count the max number of ones between two zeros ****************/
// there is a problem !!!!!!!!!!!!
#include <stdio.h>
int max_number_of_ones(int number);
int main()
{
    int number;
    printf("Enter the number : ");
    scanf("%d",&number);
    printf("The the maximum number of ones between two zeros  in %d is %d ", number,max_number_of_ones(number));
   return 0;
}
int max_number_of_ones(int number)
{
    int counter=0,max=0;
    for(;number>0;number>>=1)
    {
        if (number&1)
        {
            counter++;
        }
        else
        {
            if (counter>max)
            {
                max=counter;
                counter=0;
            }
        }
    }
    return max;
}

