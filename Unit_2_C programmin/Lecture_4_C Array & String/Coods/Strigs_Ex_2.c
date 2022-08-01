

/* ############# << Strings_Ex_2 Findimg the length of string  >> #######################*/
#include <stdio.h>
int main()
{
    char str[100];
    int i,counter=0;
    printf("Enter the string : ");
    gets(str);
    for(i=0;str[i]!=0;i++)
    {
        counter++;
    }
    printf("Length of string : %d",counter);

    return 0;
}
