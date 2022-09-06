

/* ############# << Ex_3  Reverse string with recursion>> #######################*/
#include<stdio.h>
#include<string.h>
void Revers();
int main()
{
    printf("Enter a sentence : ");
    Revers();
    return 0;

}
void Revers()
{
    char c;
    scanf("%c",&c);
    if (c!='\n')
    {
        Revers();
        printf("%c",c);
    }
}

