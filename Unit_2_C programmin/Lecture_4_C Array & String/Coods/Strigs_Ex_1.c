

/* ############# << Ex_1  Finding the frequency of character >> #######################*/
#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    char ch_search;
    int counter=0,i;
    printf("Enter the string : ");
    gets(str);
    printf("Enter the character to find the frequency : ");
    scanf("%c",&ch_search);
    for(i=0;str[i]!=0;i++)
    {
        if (str[i]==ch_search)
        {
            counter++;
        }
    }
    printf("Frequency of %c = %d " ,ch_search,counter );
    return 0;
}
