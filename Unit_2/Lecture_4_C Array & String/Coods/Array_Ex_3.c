/* ############# << Ex_3 transpose of matrix  >> #######################*/
#include <stdio.h>
int main()
{
    int rows,column,i,j;
    printf("Enter Rows and column : ");
    scanf("%d %d",&rows,&column);
    int matrix[rows][column];
    int Trans_Matrix[column][rows];
    printf("Enter elements of matrix \n");
    for (i=0;i<rows;i++)
    {
        for(j=0;j<column;j++)
        {
            printf("Enter elements matrix %d %d : ",i+1,j+1);
            scanf("%d",&matrix[i][j]);
        }
    }
    printf("Entered matrix is : \n");
    for (i=0;i<rows;i++)
    {
        for(j=0;j<column;j++)
        {
            printf("%d \t",matrix[i][j]);
        }
        printf("\n");
    }
    for (i=0;i<column;i++)
    {
        for(j=0;j<rows;j++)
        {
            Trans_Matrix[i][j]=matrix[j][i];
        }
    }
    printf("Transpose of matrix is : \n");
    for (i=0;i<column;i++)
    {
        for(j=0;j<rows;j++)
        {
            printf("%d \t",Trans_Matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
/*
/* ############# << the same idea  >> #######################*/

#include <stdio.h>
int main()
{
    float x[3][3];
    int i,j;
    float t[3][3];
    for (i=0;i<3;i++)
    {
        for (j=0;j<3;j++)
        {
            printf("Enter the item [%d][%d] : ",i,j);
            scanf("%f",&x[i][j]);
        }
    }
    printf("Before Transposing \n");
    for (i=0;i<3;i++)
    {
        for (j=0;j<3;j++)
        {
            printf("%.2f\t",x[i][j]);
        }
        printf("\n");
    }
    for (i=0;i<3;i++)
    {
        for (j=0;j<3;j++)
        {
            t[i][j]=x[j][i];
        }

    }
    printf("After Transposing \n");
    for (i=0;i<3;i++)
    {
        for (j=0;j<3;j++)
        {
            printf("%.2f \t",t[i][j]);
        }
        printf("\n");
    }


    return 0;
}


*/
