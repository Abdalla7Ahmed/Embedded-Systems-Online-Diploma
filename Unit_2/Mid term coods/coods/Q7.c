
/**************** Q 7 sum numbers from 1 to 100(without loop) ****************/
#include <stdio.h>
int sum(int F_number,int l_number);
int main()
{
    printf("the summition = %d",sum(1,100));
   return 0;
}
int sum(int F_number,int l_number)
{
    int sumition=l_number;
    if (l_number>F_number)
    {
        sumition+=sum(0,--l_number);
    }
    return sumition;
}
