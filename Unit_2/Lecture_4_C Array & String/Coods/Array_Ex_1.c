

/* ############# << Ex_1 Summing in matrix  >> #######################*/
#include<stdio.h>
int main()
{
    float matrix_1[2][2];
    float matrix_2[2][2];
    float sum[2][2];
    int i,j;
    printf("***** scan of matrix_1 ******** \n");
    for (i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("Enter matrix_1[%d][%d] : ",i+1,j+1);
            scanf("%f",&matrix_1[i][j]);
        }
    }
    printf("***** scan of matrix_2 ******** \n");
    for (i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("Enter matrix_2[%d][%d] : ",i+1,j+1);
            scanf("%f",&matrix_2[i][j]);
        }
    }
    for (i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            sum[i][j]=matrix_1[i][j]+matrix_2[i][j];
        }
    }
    printf("***** summing of matrix_1 and matrix_2 ******** \n");
    for (i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("%.2f \t",sum[i][j]);
        }
        printf("\n");
    }
    return 0;}
