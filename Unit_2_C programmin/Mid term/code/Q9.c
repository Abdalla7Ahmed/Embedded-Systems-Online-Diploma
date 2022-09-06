
/**************** Q9 reverse words in string ****************/
#include <stdio.h>
void reverse();
int main()
{
    printf("Enter the string : ");
    reverse();
}
void reverse()
{
    char c;
    scanf("%c",&c);
    if (c!='\n')
    {
        reverse();
        printf("%c",c);
    }

}
