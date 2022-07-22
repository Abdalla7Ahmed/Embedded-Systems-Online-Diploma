


/* ############# << Ex_3 reverse string by pointer  >> #######################*/
#include<stdio.h>
int main()
{
    char str[15],Rstr[15],i;
    char *p_str=str;
    char *p_Rstr=Rstr;
    printf("Input a string : ");
    gets(str);
    int j=strlen(str)-1;
    for(i=0;i<strlen(str);i++,j--)
    {
        *(p_Rstr+j)=*(p_str+i);
    }
    p_Rstr=Rstr;
    printf("Rwvwrse of the string : ");
    for(i=0;i<strlen(Rstr);i++)
    {
        printf("%c",*p_Rstr++);
    }
    printf("\n#######################################");
    return 0;

}
