


/* ############# << Ex_4 Inserting number in location  >> #######################*/
#include <stdio.h>
int main()
{
    int number,location,insert_number,i ;
    int Array [20];
    printf("Enter the number if elements : ");
    scanf("%d",&number);
    for(i=0;i<number;i++)
    {
        scanf("%d",&Array[i]);
    }
    for(i=0;i<number;i++)
    {
        printf("%d \t",Array[i]);
    }
    printf("\n");
    printf("Enter the element to be insert : ");
    scanf("%d",&insert_number);
    printf("Enter the location : ");
    scanf("%d",&location);
    for (i=number;i>=location;i--)
    {
        Array[i]=Array[i-1];
    }
    Array[i]=insert_number;
    for(i=0;i<number+1;i++)
    {
        printf("%d \t",Array[i]);
    }
    return 0;
}
