
/**************** Q 6 return unique number in array with one loop ****************/
#include <stdio.h>
int unique_number(int arr[],int size);
int main()
{
    int arr[]={4,2,5,2,5,7,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("The uniqe number is : %d",unique_number(arr,size));
   return 0;
}
int unique_number(int arr[],int size)
{
    int i,result=0;
    for(i=0;i<size;i++)
    {
      result^=arr[i];
    }
    return result;
}
