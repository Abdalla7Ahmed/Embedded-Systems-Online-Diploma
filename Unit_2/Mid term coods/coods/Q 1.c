

/**************** Q 1 Summing digits****************/
#include <stdio.h>
int main()
{
    int number,sum=0,remain;
    printf("Enter the nmber : ");
    scanf("%d",&number);
    while(number>0)
    {
        remain=number%10;
        sum+=remain;
        number/=10;
    }
  printf("The summition =  %d",sum);
  return 0;

}
