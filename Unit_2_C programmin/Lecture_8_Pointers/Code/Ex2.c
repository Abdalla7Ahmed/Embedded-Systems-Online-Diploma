


/* ############# << Ex_2 printing the alphabets >> #######################*/
#include<stdio.h>
int main()
{
    char alpha[26];
    char* p=alpha;
    int i;
    char start='A';
    for(i=0;i<sizeof(alpha);i++,start++)
    {
        *(p+i)=start;
    }
    for(i=0;i<sizeof(alpha);i++)
    {
        printf("%c  ",*p++);
    }
    printf("\n#######################################");
    return 0;

}
