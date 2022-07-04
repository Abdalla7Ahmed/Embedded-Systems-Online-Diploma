

/* ############# << Ex_1 Prime >> #######################*/

#include<stdio.h>
int Check_number(int number);
int main()
{
    int number_1,number_2,i,num;
    printf("Enter two number(intervas) : " );
    scanf("%d %d",&number_1,&number_2);
    printf("Prime number between %d %d are : ",number_1,number_2);
    for (i=number_1;i<=number_2;i++)
    {
        num=Check_number(i);
        if (num ==0)
        {
            printf("%d  ",i);
        }
    }
    return 0;
}
int Check_number(int number)
{
    int i,num=0;
    for (i=2;i<=(number/2);i++)
    {
        if((number%i)==0)
        {
            num =1;
            break;
        }
    }
    return num;
}
