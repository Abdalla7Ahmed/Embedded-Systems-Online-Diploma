


/* ############# << Ex_1 >> #######################*/
#include<stdio.h>
int main()
{
    int m=29;
    printf("Address of m = %p \n",&m);
    printf("Value of m = %d\n",m);
    printf("################################\n\n\n");
    int *ab=&m;
    printf("Address of pointer ab = %p \n",ab);
    printf("Content of pointer ab = %d\n",*ab);
    m=34;
    printf("################################\n\n\n");
    printf("Address of pointer ab = %p \n",ab);
    printf("Content of pointer ab = %d\n",*ab);
    printf("################################\n\n\n");
    *ab=7;
    printf("Address of m = %p \n",&m);
    printf("Content of m = %d\n",m);
    printf("################################");


}
