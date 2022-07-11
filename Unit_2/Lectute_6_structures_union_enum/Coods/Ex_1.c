

/* ############# << Ex_1 store information by struct >> #######################*/

#include<stdio.h>
struct Sinformation
{
    char m_name[50];
    int m_roll_number;
    float m_marks;
};
int main()
{
    //reading the information
    struct Sinformation students;
    printf("Enter information of student : \n");
    printf("Enter name : ");
    scanf("%s",students.m_name);
    printf("Enter roll number : ");
    scanf("%d",&students.m_roll_number);
    printf("Enter marks : ");
    scanf("%f",&students.m_marks);
    // printing the information
    printf("Displaying information : \n");
    printf("name : %s \n",students.m_name);
    printf("Roll : %d \n",students.m_roll_number);
    printf("Marks : %.2f ",students.m_marks);
    return 0;
}
