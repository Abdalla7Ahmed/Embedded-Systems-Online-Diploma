


/* ############# << Ex_5 Search an element in Array >> #######################*/
#include <stdio.h>
int main()
{
    int Array[10];
    int number,element,i;
    printf("Enter no of element : ");
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
    printf("Enter the number to be search : ");
    scanf("%d",&element);
    for(i=0;i<number;i++)
    {
        if (Array[i]==element)
        {
            printf("Number found at the location = %d ",i+1);
            break;
        }
    }
    if (i==number)

    {
        printf("Sort !! Number not found");

    }
    return 0;
}
