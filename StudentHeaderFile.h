#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<CourseHeaderFile.h>
struct students
{
	char name[50];
	char enroll[20];
	char dob[20];
	char programName[20];
	char mobileNo[13];
	char email[20];
	char password[20];
	struct course c[5];
};
char* CalculateGrade(int obtainedmarks,int totalmarks)
{
	int per;
//	printf("\nObtained:%d,Total:%d",obtainedmarks,totalmarks);
//	printf("\nPercentagebefore:%d",per);
	per=(int)(obtainedmarks*100)/totalmarks;
//	printf("\nPercentage:%d",per);
	if(per>=90)
	{
		return "A+";
	}
	else if(per>=80)
	{
		return "A";
	}
	else if(per>=70)
	{
		return "B+";
	}
	else if(per>=60)
	{
		return "B";
	}
	else if(per>=50)
	{
		return "C+";
	}
	else if(per>=40)
	{
		return "C";
	}
	else
	{
		return "F";
	}
}
bool CreateStudentProfile()
{
	printf("\nFirst create all the available courses then only add the students record.");
	struct students st;
	FILE *fp,*fp2;
	char crsecode;
	fp= fopen ("student.dat", "a+");
	 
	fp2 = fopen ("course.dat", "r"); 
	struct course c;
	fflush(stdin);
	printf("\nEnter student name:");
    scanf("%[^\n]",st.name);
    fflush(stdin);

	printf("\nEnter student enroll:");
    scanf("%[^\n]",st.enroll);
    fflush(stdin);
	printf("\nEnter student dob:");
    scanf("%[^\n]",st.dob);
    fflush(stdin);
	printf("\nEnter student program name:");
    scanf("%[^\n]",st.programName);
    fflush(stdin);
	printf("\nEnter student mobile no:");
    scanf("%[^\n]",st.mobileNo);
    fflush(stdin);
	printf("\nEnter student email:");
    scanf("%[^\n]",st.email);
    fflush(stdin);
	printf("\nEnter student password:");
    scanf("%[^\n]",st.password);
//    printf("\nEnter course code for 5 courses:")
    for(int i=0;i<5;i++)
    {
    	st.c[i].exam[0].totalMarks=20;
    	st.c[i].exam[1].totalMarks=30;
    	st.c[i].exam[2].totalMarks=50;
    	
    	st.c[i].exam[0].obtainedMarks=0;
    	st.c[i].exam[1].obtainedMarks=0;
    	st.c[i].exam[2].obtainedMarks=0;
    	
    	fread (&c, sizeof(struct course), 1, fp2);
    	strcpy(st.c[i].courseCode,c.courseCode);
    	strcpy(st.c[i].courseName,c.courseName);
    	strcpy(st.c[i].courseDescription,c.courseDescription);
	}
//	for(int i=0;i<5;i++)
//    {
//    	printf("\n%d",st.c[i].exam[0].totalMarks);
//    }
	fclose(fp2);
	
	//Check whether student is exist or not
	struct students st1;
	while (fread (&st1, sizeof(struct students), 1, fp))
    { 
    	if(strcmp(st.enroll,st1.enroll)==0)
    	{
    		printf("\nStudent enrollment number is already exist...FAILED");
    		return false;
		}
	}
	
	
	fwrite (&st, sizeof(struct students), 1, fp);
	if(fwrite != 0) 
	{ 
        printf("\ncontents to file written successfully !"); 
        fclose (fp); 
        return true;
    }
    else
	{ 
        printf("\nerror writing file In createstudent at Student Header file !"); 
        fclose (fp); 
        return false;
	}
	fclose (fp); 
}
void showAllStudents()
{

		struct students st;
		FILE *fp;
		char crsecode;
		fp= fopen ("student.dat", "r");
		fread (&st, sizeof(struct students), 1, fp);
		
		printf("\nName              Enroll        Mobile        Email                          Password   %s           %s              %s            %s            %s     Final Grade",st.c[0].courseCode,st.c[1].courseCode,st.c[2].courseCode,st.c[3].courseCode,st.c[4].courseCode);
//		printf("                                                                                                                                                        %s            %s               %s             %s         %s",st.c[0].courseCode,st.c[1].courseCode,st.c[2].courseCode,st.c[3].courseCode,st.c[4].courseCode);
		printf("\n                                                                                        M1 M2 M3 T     M1 M2 M3 T      M1 M2 M3 T     M1 M2 M3 T     M1 M2 M3 T");
		fclose(fp);		
		printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
		fp= fopen ("student.dat", "r");
		while (fread (&st, sizeof(struct students), 1, fp))
	    { 
		    printf("\n%s",st.name);
		    printf("           %s",st.enroll);
//		    printf("      %s",st.dob);
//		    printf("    %s",st.programName);
		    printf("    %s",st.mobileNo);
		    printf("    %s",st.email);
		    printf("      %s  ",st.password);
		    int totalmarks,obtainedmarks;
		    totalmarks=0;
		    obtainedmarks=0;
		    for(int i=0;i<5;i++)
		    {
		    	int a,b,c,d;
		    	a=st.c[i].exam[0].obtainedMarks;
				b=st.c[i].exam[1].obtainedMarks;
				c=st.c[i].exam[2].obtainedMarks;
				d=a+b+c;
				totalmarks+=st.c[i].exam[0].totalMarks;
				totalmarks+=st.c[i].exam[1].totalMarks;
				totalmarks+=st.c[i].exam[2].totalMarks;
				obtainedmarks+=d;
		    	printf("    %d %d %d=%d",a,b,c,d);
			}
//			printf("\nObtained:%d,Total:%d",obtainedmarks,totalmarks);
			printf("  %s ",CalculateGrade(obtainedmarks,totalmarks));
	    	printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");

		}
		fclose(fp);
	
}
void showSigleStudentByAny()
{
	struct students st;
		FILE *fp;
		char enroll[20],password[20];
		while(1)
		{
			fp= fopen ("student.dat", "r");
			fflush(stdin);
			int flag=0;
			printf("\nEnter enrollment number:");
			scanf("%[^\n]",enroll);
			fflush(stdin);
			while (fread (&st, sizeof(struct students), 1, fp))
			{
				if(strcmp(st.enroll,enroll)==0)
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
			{
				fclose(fp);
				break;
			}
			else
			{
				printf("\nEnter a valid enrollment no.");
			}
			fclose(fp);
		}
		
		printf("\n----------------------------------------------------------------------------------------------");
			printf("\nStudent name:");
		    printf("       %s",st.name);
			printf("\nStudent enroll:");
		    printf("   %s",st.enroll);
		    printf("\nStudent's dob:");
		    printf("      %s",st.dob);
		    printf("\nProgram name:");
		    printf("      %s",st.programName);
		    printf("\nMobile no:");
		    printf("          %s",st.mobileNo);
		    printf("\nStudent's email:");
		    printf("    %s",st.email);
		    printf("\nCourses            Marks M1 M2 M3 T");
		    int totalmarks,obtainedmarks;
		    totalmarks=0;
		    obtainedmarks=0;
		    for(int i=0;i<5;i++)
		    {
		    	int a,b,c,d;
		    	a=st.c[i].exam[0].obtainedMarks;
				b=st.c[i].exam[1].obtainedMarks;
				c=st.c[i].exam[2].obtainedMarks;
				d=a+b+c;
				totalmarks+=st.c[i].exam[0].totalMarks;
				totalmarks+=st.c[i].exam[1].totalMarks;
				totalmarks+=st.c[i].exam[2].totalMarks;
				obtainedmarks+=d;
		    	printf("\n%s                      %d %d %d %d",st.c[i].courseCode,a,b,c,d);
			}
			printf("\nGrade:              %s ",CalculateGrade(obtainedmarks,totalmarks));
			printf("\n----------------------------------------------------------------------------------------------");

		
		fclose(fp);	
}
void showSigleStudentByStudent()
{
	struct students st;
		FILE *fp;
		char enroll[20],password[20];
		while(1)
		{
			fflush(stdin);
			int flag=0;
			fp= fopen ("student.dat", "r");
			printf("\nEnter enrollment number:");
			scanf("%[^\n]",enroll);
			fflush(stdin);
			while (fread (&st, sizeof(struct students), 1, fp))
			{
				if(strcmp(st.enroll,enroll)==0)
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
			{
				fclose(fp);
				break;
			}
			else
			{
				printf("\nEnter a valid enrollment no.");
			}
				fclose(fp);
		}
		while(1)
			{
				fflush(stdin);
				printf("\nEnter password:");
				scanf("%[^\n]",password);
				if(strcmp(st.password,password)==0)
				{
					break;
				}
				else 
				{
					printf("\nPlease enter correct password.");
				}
			}
			printf("\n----------------------------------------------------------------------------------------------");
			printf("\nStudent name:");
		    printf("       %s",st.name);
			printf("\nStudent enroll:");
		    printf("   %s",st.enroll);
		    printf("\nStudent's dob:");
		    printf("      %s",st.dob);
		    printf("\nProgram name:");
		    printf("      %s",st.programName);
		    printf("\nMobile no:");
		    printf("         %s",st.mobileNo);
		    printf("\nStudent's email:");
		    printf("    %s",st.email);
		    printf("\nCourses            Marks M1 M2 M3 T");
		    int totalmarks,obtainedmarks;
		    totalmarks=0;
		    obtainedmarks=0;
		    for(int i=0;i<5;i++)
		    {
		    	int a,b,c,d;
		    	a=st.c[i].exam[0].obtainedMarks;
				b=st.c[i].exam[1].obtainedMarks;
				c=st.c[i].exam[2].obtainedMarks;
				d=a+b+c;
				totalmarks+=st.c[i].exam[0].totalMarks;
				totalmarks+=st.c[i].exam[1].totalMarks;
				totalmarks+=st.c[i].exam[2].totalMarks;
				obtainedmarks+=d;
		    	printf("\n%s                     %d %d %d %d",st.c[i].courseCode,a,b,c,d);
			}
			printf("\nGrade:             %s ",CalculateGrade(obtainedmarks,totalmarks));
			printf("\n----------------------------------------------------------------------------------------------");

}
void DeleteAllStudentsRecord()
{
	FILE *fp;
	fp=fopen("student.dat", "w");
	fclose(fp);
	printf("Deleted.");
}

void Course_wise_statistics(char coursecode[])
{
	int coursenumber=isCourseFound(coursecode);
	FILE *fp;
	fp= fopen ("student.dat", "r");
	int totalmarks=0,obtainedmarks=0;
	int totalStudent=0,passed=0,eachmarks=0,a=0,aplus=0,b=0,bplus=0,c=0,cplus=0,fail=0;
	if (fp == NULL) 
    { 
        printf("\nError in open file Student.dat at Adding MarksCourse in Teacher.p");  
 		return;
    }
    printf("\nName              Enroll        Mobile        Email              %s     M1 M2 M3 T     Grade",coursecode);
	printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------");	
	struct students st;
	while (fread (&st, sizeof(struct students), 1, fp))
    {
    	totalmarks=0;
    	printf("\n%s",st.name);
    	printf("        %s",st.enroll);
    	printf("   %s",st.mobileNo);
    	printf("    %s",st.email);
    	totalStudent++;
    	eachmarks=0;
		    	int a,b,c,d;
		    	a=st.c[coursenumber].exam[0].obtainedMarks;
				b=st.c[coursenumber].exam[1].obtainedMarks;
				c=st.c[coursenumber].exam[2].obtainedMarks;
				obtainedmarks=a+b+c;
				totalmarks+=st.c[coursenumber].exam[0].totalMarks;
				totalmarks+=st.c[coursenumber].exam[1].totalMarks;
				totalmarks+=st.c[coursenumber].exam[2].totalMarks;
//		    	printf("\n%s                     %d %d %d %d",st.c[i].courseCode,a,b,c,d);
//  			eachmarks=d;
  			
  			if(obtainedmarks>=40)
  			{
  				passed++;
			  }
  			printf("      %d %d %d %d",a,b,c,obtainedmarks);
  			printf("      %s",CalculateGrade(obtainedmarks,totalmarks));
  			printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------");	

	  }
	    printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------");	
	   	printf("\nTotal student enrolled:%d",totalStudent);
  		printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------");	
	   	printf("\nTotal student passed:%d",passed);
  		printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------");	
		printf("\nTotal student failed:%d",totalStudent-passed);
  		printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------");	
	   	printf("\nResult:%d%%",(int)(passed*100)/totalStudent);
  		printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------");	

	fclose(fp);
}

void PrintStudentProfile(char enrl[50])
{
	printf("\nStudent profile-----------------------------------------------");
}


