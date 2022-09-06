
/* ##################### << EXAMPLE 8 >> ############################*/
#include <stdio.h>
int main ()
{
    float number_1,number_2;
    char character;
    printf("Enter the operation (+ , - , * or /): ");
    scanf("%c",&character);
    printf("Enter two perands :");
    scanf("%f %f",&number_1,&number_2);
    switch(character)
    {
        case '+':
            {
                printf("%%.1f % c %.1f = %.1f",number_1,character,number_2,number_1+number_2);
                break;
            }
        case '-':
            {
                printf("%.1f % c %.1f = %.1f",number_1,character,number_2,number_1-number_2);
                break;
            }
        case '*':
            {
                printf("%.1f % c %.1f = %.1f",number_1,character,number_2,number_1*number_2);
                break;
            }
       case '/':
            {
                printf("%.1f % c %.1f = %.1f",number_1,character,number_2,number_1/number_2);
                break;
            }
       default :
        {
            printf("Error !!!!!");
            break;
        }
    }

    }









