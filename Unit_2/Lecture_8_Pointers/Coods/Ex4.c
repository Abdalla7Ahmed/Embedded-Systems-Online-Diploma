


/* ############# << Ex_4 reverse array  >> #######################*/
#include<stdio.h>
int main()
{
    int arr[15],Rarr[15],size,i,j=0;
    int *p_arr=arr;
    int *p_Rarr=Rarr;
    printf("Enter the size : ");
    scanf("%d",&size);
    printf("Enter the element of array : \n");
    for(i=0;i<size;i++)
    {
        printf("Element %d :",i+1);
        scanf("%d",p_arr++);
    }
    p_arr=arr;
    for(i=size-1;i>=0;i--,j++)
    {
        *(p_Rarr+i)=*(p_arr+j);
    }
    p_Rarr=Rarr;
    printf("The reverse array : \n");
    for(i=size;i>0;i--)
    {
        printf("Element %d : %d\n",i,*p_Rarr++);
    }
    printf("\n#######################################");
    return 0;

}
