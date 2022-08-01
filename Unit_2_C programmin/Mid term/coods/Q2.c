
/**************** Q 2 root of number ****************/
#include <stdio.h>
#include <math.h>
float squar_n(float number);
int main()
{
   int number ;
   float result;
   printf("Enter the number : ");
   scanf("%d",&number);
   result=squar_n(number);
   printf("The squar of %d = %f ",number,result);
   return 0;
}
float squar_n(float number)
{
    return sqrt(number);
}
