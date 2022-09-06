



/* ############# << Strings_Ex_3   >> #######################*/
#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    char Rev_str[100];
    int length,i;
    printf("Enter the string : ");
    gets(str);
    length=strlen(str);
    for (i=0;str[i]!='\0',length!=0;i++,length--)
    {
        Rev_str[i]=str[length-1];
    }
    printf("Reverse string is : %s ",Rev_str);
    return 0;
}
