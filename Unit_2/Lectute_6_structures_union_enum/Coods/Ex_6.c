
/* ############# << Ex_6  Size of struct and union>> #######################*/

#include <stdio.h>
union jop{
    char name [32];
    float salary;
    int worker_no;
}u;
struct jop1{
    char name [32];
    float salary;
    int worker_no;
}s;
int main()
{
    printf("Size of Union = %d \n",sizeof(u));
    printf("Size of struct = %d ",sizeof(s));
    return 0;
}
