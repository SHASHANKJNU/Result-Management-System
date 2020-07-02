#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include<MarksHeaderFile.h>
//#include<LoginHeaderFile.h>
int totalcourse=0;
struct course
{
	char courseName[50];
	char courseCode[50];
	char courseDescription[20];
	char password[20];
	struct exams exam[3];//Assuming there are three exams in a session. 
};
bool createCourse()
{
	FILE *fp; 
    struct course cc;  
    fp = fopen ("course.dat", "a+"); 
    if (fp == NULL) 
    { 
        printf("\nError in open file course.dat at createCourse in Course.p");  
//        return false;
    }
	totalcourse=0;
//	printf("\nCourses before writing:%d",totalcourse);
   	while (fread (&cc, sizeof(struct course), 1, fp))
    {
    	totalcourse++;
  	}
//  	printf("\nCourses after writing:%d",totalcourse);
	if(totalcourse>=5)
	{
		printf("\nCourse can't be added beacause 5 courses are already added.");
		fclose (fp);
		return false; 
	}
	
//	FILE *fp;
	struct course c;
	fp= fopen ("course.dat", "a+"); 
	if (fp == NULL) 
    { 
        printf("\nError in open file course.dat at createCourse in Course.p"); 
//        return false; 
    }
    fflush(stdin);
    printf("Enter course code:");
    scanf("%s%*c",c.courseCode);
    fflush(stdin);
	printf("Enter course name:");
    scanf("%[^\n]",c.courseName);
    fflush(stdin);
	printf("Enter course Description:");
    scanf("%[^\n]",c.courseDescription);
	fflush(stdin);
	printf("Enter course password:");
    scanf("%[^\n]",c.password);
	fflush(stdin);
//	struct course c;
//	strcpy(c.courseCode,courseCode);
//	strcpy(c.courseName,courseName);
//	strcpy(c.courseDescription,courseDescription); 	
	fwrite (&c, sizeof(struct course), 1, fp);
	if(fwrite != 0) 
	{ 
        printf("\ncontents to file written successfully !"); 
        fclose (fp); 
//        return true;
    }
    else
	{ 
        printf("\nerror writing file !"); 
       	fclose (fp); 
//        return false;
	}
}
void DeleteAllCourses()
{
	FILE *fp,*fp1;
	fp= fopen ("course.dat", "w");
	fp1= fopen ("course2.dat", "w");  
	if (fp == NULL) 
    { 
        printf("\nError in open file course.dat at DeleteAllCourses in Course.p"); 
//        return false; 
    }
    fclose(fp);
    fclose(fp1);
    remove("course.dat");
  	rename("course2.dat","course.dat");
  	printf("\nAll courses are deleted.");
//    return true;
}
int isCourseFound(char c[])
{
	int counter=-1;
	FILE *fp; 
	int flag=0;
    struct course cc;  
    fp = fopen ("course.dat", "r"); 
    if (fp == NULL) 
    { 
        printf("\nError in open file course.dat at isCourseFound in Course.p"); 
                	fclose (fp); 
        return false;
    } 
   	while (fread (&cc, sizeof(struct course), 1, fp))
    {
		counter++;		 
  		if(strcmp(cc.courseCode,c)==0)
		{
			printf("\nYour course is:  %s",cc.courseName);
			flag=1;
			break;	  	
		}	
	}
    fclose (fp);
	if(flag==1)
	{
		return counter;
	} 
    return -1; 	
}
bool showCourse()
{
	FILE *fp; 
    struct course cc;  
    fp = fopen ("course.dat", "r"); 
    if (fp == NULL) 
    { 
        printf("\nError in open file course.dat at showCourse in Course.p"); 
                	fclose (fp); 
        return false;
    } 
	printf("\nCorse code          Course Name            Course Description       Course Password"); 
	printf("\n---------------------------------------------------------------------"); 

   	while (fread (&cc, sizeof(struct course), 1, fp))
    {
//    	printf("\nhello");
        printf ("\n%s          %s           %s      %s",cc.courseCode,cc.courseName,cc.courseDescription,cc.password); 
  	}
    fclose (fp); 
    return true; 
}
int Initialize()
{
	bool result;
	struct course c;
	strcpy(c.courseCode,"102");
	strcpy(c.courseName,"CLanguage");
	strcpy(c.courseDescription,"MyFavourite");
//	printf("hello");
//	printf ("\n%s    %s    %s",c.courseCode,c.courseName,c.courseDescription); 
	createCourse();
	result=showCourse();
//	result=createCourse("102","SecondCLanguage","MySecondFavourite");
//	result=showCourse();
	return 0;
}
