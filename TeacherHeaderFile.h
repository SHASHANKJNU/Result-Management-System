#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<StudentHeaderFile.h>
#include<OSHeaderFile.h>
int coursenumber;
void AddingMarks()
{
	int examno,m;
	FILE *fp;
	FILE *ptr2 = fopen ("student2.dat", "w");
	fp= fopen ("student.dat", "a+");
	if (fp == NULL)
	{ 
        printf("\nError in open file Student.dat at Adding MarksCourse in Teacher.p");  
 		return;
    }
	struct students st;
	printf("\nWhich exam marks you are going to add (0->Minor 1, 1->Mid, 2->EOSE):");
	scanf("%d",&examno);
	if(examno>2)
	{
		printf("\nCan not be greater than 2.");
		return;
	}
	while (fread (&st, sizeof(struct students), 1, fp))
    {
    	while(1)
    	{
	    	fflush(stdin);
			printf("\nEnter %s's marks:",st.name);
			scanf("%d",&st.c[coursenumber].exam[examno].obtainedMarks);
			if(st.c[coursenumber].exam[examno].obtainedMarks>st.c[coursenumber].exam[examno].totalMarks)
			{
				printf("\nObtained marks can not be grater than %d total marks for this exam.",st.c[coursenumber].exam[examno].totalMarks);
				continue;
			}
			break;
		}
		fwrite(&st,sizeof(struct students),1,ptr2);
  	}
  	fclose(fp);
  	fclose(ptr2);
  	remove("student.dat");
  	rename("student2.dat","student.dat");
//  	remove("student2.dat");
}
void UpdateMarks()
{
//	printf("Coursenumber:%d",coursenumber);
	char enrl[10];
	int examno,m,flag=0;
	FILE *fp;
	FILE *ptr2 = fopen ("student2.dat", "w");
	fp= fopen ("student.dat", "a+");
	if (fp == NULL) 
    { 
    	fclose(fp);
  		fclose(ptr2);
        printf("\nError in open file Student.dat at Adding MarksCourse in Teacher.p");  
 		return;
    }
	struct students st;
	fflush(stdin);
	printf("\nEnter student enrollment no:");
	scanf("%[^\n]",enrl);
	fflush(stdin);
	printf("\nWhich exam marks you are going to add (0->Minor 1, 1->Mid, 2->EOSE):");
	scanf("%d",&examno);
	if(examno>2)
	{
		fclose(fp);
  		fclose(ptr2);
		printf("\nCan not be greater than 2.");
		return;
	}
//	fflush(stdin);
	flag=0;
	while (fread (&st, sizeof(struct students), 1, fp))
    {
		if(strcmp(st.enroll,enrl)==0)
		{
			fflush(stdin);
			while(1)
			{
				fflush(stdin);
				printf("\nEnter %s 's marks:",st.name);
				scanf("%d",&st.c[coursenumber].exam[examno].obtainedMarks);
				if(st.c[coursenumber].exam[examno].obtainedMarks>st.c[coursenumber].exam[examno].totalMarks)
				{
					printf("\nObtained marks can not be grater than %d total marks for this exam.",st.c[coursenumber].exam[examno].totalMarks);
					continue;
				}
				flag=1;
				break;
			}
		}
		fwrite(&st,sizeof(struct students),1,ptr2);
  	}
  	if(flag==1)
  	{
  		printf("\nRecord updated.");
	}
	else
	{
		printf("\nRecord does not found.");
	}
	fclose(fp);
  	fclose(ptr2);
  	remove("student.dat");
  	rename("student2.dat","student.dat");
//  	remove("student2.dat");
}

int Teacher_main()
{
	char coursecode[10];
	while(1)
	{
		fflush(stdin);
        printf("\nEnter course code:");
        scanf("%s",coursecode);
        fflush(stdin);
        coursenumber=isCourseFound(coursecode);
//        printf("%d",coursenumber)
        if(coursenumber!=-1)
        {
        	break;
		}
		else
		{
        	printf("\nEntered course code is not found.");			
		}
	}
	while(1)
	{
		bool resslt;
		fflush(stdin);
		char passwd[20];
        printf("\nEnter course code password:");
        scanf("%[^\n]",passwd);
        fflush(stdin);
        
        FILE *fp; 
	    struct course cc;  
	    fp = fopen ("course.dat", "r"); 
	    if (fp == NULL) 
	    { 
	        printf("\nError in open file course.dat at TeacherHeader file in checking password in teacherheader file.p"); 
						resslt=false; 
						return 0;
	    } 
	   	while (fread (&cc, sizeof(struct course), 1, fp))
	    {		 
	  		if(strcmp(cc.password,passwd)==0)
			{
				resslt=true;
				break;	  	
			}	
		}
	    fclose (fp);
        
        if(resslt==true)
        {
        	break;
		}
		else
		{
        	printf("\nPlease enter correct password.");			
		}
	}
	int choice;
//	printf("\nLogin as:");
    while(1)
	{
        printf("\n1. Add marks");
        printf("\n2. Update marks.");
        printf("\n3. See course wise statistics");
//        printf("\n4. See students.");
        printf("\n4. Exit");
		printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                AddingMarks();
                break;
            case 2:
                UpdateMarks();
                break;
            case 3:
                Course_wise_statistics(coursecode);
                break;
//            case 4:
//                showAllStudents();
//                break;
            case 4:
                return 0;
                break;
            default:
                break;
        }
    }
    return 0;
}
void Student_function()
{
	showSigleStudentByStudent();//For student module
}


