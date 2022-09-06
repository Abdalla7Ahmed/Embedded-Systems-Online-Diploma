


/* ##################### << EXAMPLE 2  >> ############################*/
#include <stdio.h>
int main ()
{
    char alphabet;
    printf("Enter an alphabet : ");
    scanf("%c",&alphabet);
    if ((alphabet=='a')||(alphabet=='e')||(alphabet== 'i')||(alphabet== 'o')
      ||(alphabet=='A')||(alphabet=='E')||(alphabet== 'I')||(alphabet== 'O'))
    {
        printf("%c is a vowel",alphabet);
    }
    else
    {
        printf("%c is a constant",alphabet);
    }
}











