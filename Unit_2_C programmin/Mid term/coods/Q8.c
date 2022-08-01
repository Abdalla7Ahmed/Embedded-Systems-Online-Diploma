
/**************** Q 8 take an array and revers its elements ****************/
#include <stdio.h>
void reverse(int arr[],int size);
int main()
{
    int size,i;
    int arr[20];
    printf("Enter the size of array : ");
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        printf("Enter the element ( %d  ) ==> ",i);
        scanf("%d",&arr[i]);
    }
    reverse (arr,size);
    return 0;
}
void reverse(int arr[],int size)
{
    int rev[size];
    int i,j;
    for(i=0,j=size-1;i<size;i++,j--)
    {
        rev[j]=arr[i];
    }
    for(i=0;i<size;i++)
    {
        printf("%d ",rev[i]);
    }
}
