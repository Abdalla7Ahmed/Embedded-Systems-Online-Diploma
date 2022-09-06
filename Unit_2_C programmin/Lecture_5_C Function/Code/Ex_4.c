

/* ############# << Ex_4 calculating the power by using the recursion  >> #######################*/
#include<stdio.h>
int power_R(int x,int y);
int main()
{
    int base,power;
    printf("Enter base number : ");
    scanf("%d",&base);
    printf("Enter power number (positive integer) : ");
    scanf("%d",&power);
    printf("%d ^ %d = %d",base,power,power_R(base,power));

    return 0;
}
int power_R(int x,int y)
{
    if (y!=0)
    {
        return (x*power_R(x,y-1));
    }
    else
        return 1;
}
