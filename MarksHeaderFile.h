#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct exams
{
	int totalMarks;
	int obtainedMarks;
};
//bool InsertMarks(struct exams m)
//{
//	FILE *fp;
//	struct course c;
//	fp= fopen ("course.dat", "a+"); 
//	if (fp == NULL) 
//    { 
//        printf("\nError in open file course.dat at createCourse in Course.p"); 
//        return false; 
//    }
//    printf("Enter course code:");
//    scanf("%s%*c",c.courseCode);
//    printf("Enter course name:");
//    scanf("%[^\n]",c.courseName);
//    printf("Enter course Description:");
//    scanf("%[^\n]",c.courseDescription);
////	struct course c;
////	strcpy(c.courseCode,courseCode);
////	strcpy(c.courseName,courseName);
////	strcpy(c.courseDescription,courseDescription); 	
//	fwrite (&c, sizeof(struct course), 1, fp);
//	if(fwrite != 0) 
//	{ 
//        printf("\ncontents to file written successfully !"); 
//        	fclose (fp); 
//        return true;
//    }
//    else
//	{ 
//        printf("\nerror writing file !"); 
//        	fclose (fp); 
//        return false;
//	}
//}
//bool showCourse()
//{
//	FILE *fp; 
//    struct course cc;  
//    fp = fopen ("course.dat", "r"); 
//    if (fp == NULL) 
//    { 
//        printf("\nError in open file course.dat at showCourse in Course.p"); 
//        return false;
//    } 
//	printf("\nCorse code          Course Name            Course Description"); 
//	printf("\n---------------------------------------------------------------------"); 
//
//   	while (fread (&cc, sizeof(struct course), 1, fp))
//    {
////    	printf("\nhello");
//        printf ("\n%s          %s           %s",cc.courseCode,cc.courseName,cc.courseDescription); 
//  	}
//    fclose (fp); 
//    return true; 
//}
//int Initialize()
//{
//	bool result;
//	struct course c;
//	strcpy(c.courseCode,"102");
//	strcpy(c.courseName,"CLanguage");
//	strcpy(c.courseDescription,"MyFavourite");
////	printf("hello");
////	printf ("\n%s    %s    %s",c.courseCode,c.courseName,c.courseDescription); 
//	result=createCourse();
//	result=showCourse();
////	result=createCourse("102","SecondCLanguage","MySecondFavourite");
////	result=showCourse();
//	return 0;
//}
