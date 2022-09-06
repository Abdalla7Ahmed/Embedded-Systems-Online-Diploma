
/* ############# << Ex_2 calculating the average by using rray >> #######################*/
#include<stdio.h>
int main()
{
    float data[20];
    float sum=0;
    int number ,i;
    printf("Enter the number of data : ");
    scanf("%d",&number);
    for (i=0;i<number;i++)
    {
        printf("%d. Enter number : ",i+1);
        scanf("%f",&data[i]);
    }
    for (i=0;i<number;i++)
    {
        sum+=data[i];
    }
    printf("Average = %.2f",sum/number);

    return 0;
}
