#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
	{
		char name[20];
		char roll[20];
		int age;
		float CGPA;
	};
int main()
{
	struct student csed;
	FILE *f,*t;
	int c,m,temps=1;
	char s;
	printf("Enter your choice from the following :\n");
	printf("1) To add a student detail.\n2) To Update a student detail.\n3) To seek a student using the rollno.\n4) To count the number of students entered in file.\n5) To delete a specific student from a file\n");
	printf("Enter your choics ----> ");
	scanf("%d",&c);
	
	switch(c)
	{
		case 1:
				f=fopen("C:\\Users\\vadde\\OneDrive\\Desktop\\textq4.txt","a");
				if(f==NULL)
				{
					printf("File not specified\n");
					exit(0);
				}
				printf("Enter the student name\n");
				scanf("%s",csed.name);
				printf("Enter the student roll\n");
				scanf("%s",csed.roll);
				printf("Enter the student age\n");
				scanf("%d",&csed.age);
				printf("Enter the student CGPA\n");
				scanf("%f",&csed.CGPA);
				fprintf(f,"%s %s %d %f\n",csed.name,csed.roll,csed.age,csed.CGPA);
				fclose(f);
				break;
		case 2:
				f=fopen("C:\\Users\\vadde\\OneDrive\\Desktop\\textq4.txt","r");
				if(f==NULL)
				{
					printf("File not specified\n");
					exit(0);
				}
				printf("\nList of Students in File :\n\n");
				s = getc(f);
				while (s != EOF)
				{
					printf("%c", s);
					s = getc(f);
				}
				printf("\nEnter the line number of student to be modified\n");
				scanf("%d",&m);
				fclose(f);
				f=fopen("C:\\Users\\vadde\\OneDrive\\Desktop\\textq4.txt","r");
				t=fopen("C:\\Users\\vadde\\OneDrive\\Desktop\\temp.txt","w");
				s = getc(f);
				while (s != EOF)
				{
					if (s == '\n')
					{
						temps++;
					}
					if (temps != m)
					{
						putc(s,t);
					}
					else
					{
						while ((s = getc(f)) != '\n')
						{
						}
						printf("Enter New student Details\n");
						fflush(stdin);
						putc('\n',t);
                        while ((s = getchar()) != '\n')
						putc(s,t);
                        fputs("\n",t);
						temps++;
					}
					s = getc(f);
				}
				fclose(f);
				fclose(t);
				remove("C:\\Users\\vadde\\OneDrive\\Desktop\\textq4.txt");
				rename("C:\\Users\\vadde\\OneDrive\\Desktop\\temp.txt","C:\\Users\\vadde\\OneDrive\\Desktop\\textq4.txt");
				f=fopen("C:\\Users\\vadde\\OneDrive\\Desktop\\textq4.txt","r");
				printf("\nList of Students in File :\n");
				s = getc(f);
				while (s != EOF)
				{
					printf("%c", s);
					s = getc(f);
				}
				fclose(f);
				break;
		case 3:
				f=fopen("C:\\Users\\vadde\\OneDrive\\Desktop\\textq4.txt","r");
				if(f==NULL)
				{
					printf("File not specified\n");
					exit(0);
				}
				char temp[512];
				char str[20]=" ",rol[20];
				int num=1;
				int find=0;
				printf("\nEnter the roll no to search :");
				scanf("%s",rol);
				strcat(str,rol);
				str[strlen(str)]=' ';
				while(fgets(temp, 512, f) != NULL)
				{
					if((strstr(temp, str)) != NULL)
					{
					printf("A match found on line: %d\n", num);
					printf("\n%s\n", temp);
					find++;
					}
					num++;
				}
				if(find==0)
				printf("Student not found");
				break;
		case 4:
				f=fopen("C:\\Users\\vadde\\OneDrive\\Desktop\\textq4.txt","r");
				if(f==NULL)
				{
					printf("File not specified\n");
					exit(0);
				}
				int word=0,characters=0;
				while(fgetc(f)!=EOF)
				{
					characters+=1;
				}
				fclose(f);
				f=fopen("C:\\Users\\vadde\\OneDrive\\Desktop\\textq4.txt","r");
				for(int c=characters;c>0;c--)
				{
					if(fgetc(f)=='\n')
					word+=1;
				}
				fclose(f);
				printf("Number of Students : %d\n",word);
				break;
		case 5:
				f=fopen("C:\\Users\\vadde\\OneDrive\\Desktop\\textq4.txt","r");
				if(f==NULL)
				{
					printf("File not specified\n");
					exit(0);
				}
				printf("\nList of Students in File :\n\n");
				s = getc(f);
				while (s != EOF)
				{
					printf("%c", s);
					s = getc(f);
				}
				printf("\nEnter the line number of student to be deleted\n");
				scanf("%d",&m);
				fclose(f);
				f=fopen("C:\\Users\\vadde\\OneDrive\\Desktop\\textq4.txt","r");
				t=fopen("C:\\Users\\vadde\\OneDrive\\Desktop\\textq4.txt","w");
				s = getc(f);
				while (s != EOF)
				{
					if (s == '\n')
					{
						temps++;
					}
					if (temps != m)
					{
						putc(s,t);
					}
					else
					{
						while ((s = getc(f)) != '\n')
						{
						}
						fputs("\n",t);
						temps++;
					}
					s = getc(f);
				}
				fclose(f);
				fclose(t);
				remove("C:\\Users\\vadde\\OneDrive\\Desktop\\textq4.txt");
				rename("C:\\Users\\vadde\\OneDrive\\Desktop\\temp.txt","C:\\Users\\vadde\\OneDrive\\Desktop\\textq4.txt");
				f=fopen("C:\\Users\\vadde\\OneDrive\\Desktop\\textq4.txt","r");
				printf("\nList of Students in File :\n");
				s = getc(f);
				while (s != EOF)
				{
					printf("%c", s);
					s = getc(f);
				}
				fclose(f);
				break;
			}
			
	return 0;
}
