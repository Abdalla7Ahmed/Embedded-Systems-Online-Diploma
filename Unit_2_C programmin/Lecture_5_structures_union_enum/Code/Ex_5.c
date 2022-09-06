
/* ############# << Ex_5  Finding the area of the cirule>> #######################*/
#include<stdio.h>
#define pi 3.14
#define area(radius) (pi*(radius)*(radius))
int main()
{
    float radius,area;
    printf("Enter the radius : ");
    scanf("%f",&radius);
    area=area(radius);
    printf("Area %.2f",area);
    return 0;
}
