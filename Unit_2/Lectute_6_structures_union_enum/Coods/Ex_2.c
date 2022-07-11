

/* ############# << Ex_2 summation of feet and inch >> #######################*/
#include<stdio.h>
struct Sdistance
{
    int m_feet;
    float m_inch;

};
int main()
{
    //reading the information
    struct Sdistance d1,d2,sum;
    // the first distance
    printf("Enter information of 1st distance \n");
    printf("Enter feet : ");
    scanf("%d",&d1.m_feet);
    printf("Enter inch : ");
    scanf("%f",&d1.m_inch);
    // the second distance
    printf("Enter information of 2st distance \n");
    printf("Enter feet : ");
    scanf("%d",&d2.m_feet);
    printf("Enter inch : ");
    scanf("%f",&d2.m_inch);

    sum.m_feet=d1.m_feet+d2.m_feet;
    sum.m_inch=d1.m_inch+d2.m_inch;
    if (sum.m_inch>=12)
    {
        sum.m_inch-=12;
        ++sum.m_feet;
    }
    printf("Sum of distance = %d\'-%.1f\"",sum.m_feet,sum.m_inch);
    return 0;
}
