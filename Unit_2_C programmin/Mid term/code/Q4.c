
/**************** Q 4 reverse digits in number ****************/
#include <stdio.h>
void reverse(int number);
int main()
{
    int number;
    printf("Enter the number : ");
    scanf("%d",&number);
    reverse(number);

   return 0;
}
void reverse(int number)
{
       int remain;
       if (number >0)
       {
           remain=number%10;
           number/=10;
           printf("%d",remain);
           reverse(number);
       }


}
