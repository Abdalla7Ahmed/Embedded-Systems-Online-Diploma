

/* ##################### << EXAMPLE 5 >> ############################*/
#include <stdio.h>
int main ()
{
    char character ;
    int i,j;
    printf("Enter a character : ");
    scanf("%c",&character);
    if (((character>=65)&&(character<=90))||((character>=97)&&(character<=122)))
        {
            printf("%c is an alphapet",character);

        }
    else
        {
            printf("%c is not an alphapet",character);

        }



   /* for(i=65,j=97;i<=90,j<=122;i++,j++)
    {
        if ((character==i)||(character==j))
        {
            printf("%c is an alphapet",character);
            break;
        }
        else
        {
            printf("%c is not an alphapet",character);
            break;
        }
    }*/
}





