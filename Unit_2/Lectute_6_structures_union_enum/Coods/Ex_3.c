

/* ############# << Ex_3 Adding two complex numbers>> #######################*/

#include<stdio.h>
struct Scomplex
{
    float m_Real;
    float m_Imag;

};
struct Scomplex Add(struct Scomplex A,struct Scomplex B)
{
    struct Scomplex c;
    c.m_Real=A.m_Real+B.m_Real;
    c.m_Imag=A.m_Imag+B.m_Imag;
    return c;
}
int main()
{
    struct Scomplex number_1,number_2,sum;
    // the first Number
    printf("For 1st complex number \n");
    printf("Enter real and imaginary recpectively  : ");
    scanf("%f %f",&number_1.m_Real,&number_1.m_Imag);
    // the second number
    printf("For 2st complex number \n");
    printf("Enter real and imaginary recpectively  : ");
    scanf("%f %f",&number_2.m_Real,&number_2.m_Imag);
    sum=Add(number_1,number_2);
    printf("sum= %.1f+%.1fi ",sum.m_Real,sum.m_Imag);

    return 0;
}
