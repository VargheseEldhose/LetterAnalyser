#include<stdio.h>
#include<string.h>
typedef struct Student
{
	int id;
	char name[50];
	double GPA;
} student;
void print(student var2);

int main(int argc,char** argv )
{   int test[10];
  test=3;
	char sample[10]={"afgh"};
	printf("%s",sample);
	student var1;
	student var2={12,"Kevin",3.56};
	
			printf("Student name:");
	
	scanf("%49[^\n]",var1.name);
		printf("Student ID: ");
	scanf("%d",&var1.id);
	
	
	
		
		printf("Student GPA: ");
	scanf("%lf",&var1.GPA);

	
	printf("\ncheck values\n");
	printf("Student 1 ID:%d\n", var1.id);
	
		
				
				printf("Student 1 Name:%s",var1.name);
				printf("Student 1 GPA:%lf",var1.GPA);
				
				print(var2);
			
				
} 
void print(student var2)
{

	printf("var 2\n");
					printf("Stdent 2 id: %d\n", var2.id);
	
		printf("Var 2 GPA:%lf",var2.GPA);
				
				printf("student 2 name: %s",var2.name);
			}
