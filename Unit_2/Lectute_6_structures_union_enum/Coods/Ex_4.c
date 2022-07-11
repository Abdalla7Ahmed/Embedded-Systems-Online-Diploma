/* ############# << Ex_4 Students Degrees>> #######################*/
#include<stdio.h>
struct Sstudent
{
    char m_name[50];
    float m_marks;

};

int main()
{
    struct Sstudent students[10];
    int counter,i;
    char c;
    printf("Enter information of students : \n");
    for(counter=1;counter<=10;counter++)
    {
        printf("For roll number %d \n",counter);
        printf("Enter name : ");
        fflush(stdout); fflush(stdin);
        scanf("%s",students[counter].m_name);
        printf("Enter marks : ");
        fflush(stdout);  fflush(stdin);
        scanf("%f",&students[counter].m_marks);
        printf("#############################\n");
        printf("Enter 'Y' to continue or 'N' to out : ");
        fflush(stdout); fflush(stdin);
        scanf("%s",&c);
        if (c=='N'||c=='n')break;
    }
    printf("Displaying information of students : \n");
    for (i=1;i<=counter;i++)
    {
        printf("Information for roll number %d \n",i);
        printf("Name : %s\n",students[i].m_name);
        printf("Marks : %.2f\n",students[i].m_marks);
    }
    return 0;
}
