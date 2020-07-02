#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<StudentHeaderFile.h>
#include<LoginHeaderFile.h>
void OS_main()
{
	while(1)
	{
		bool res=login(2);
		if(res==true)
		{
			break;
		}
	}
	
	bool res;
	int choice;
	printf("\nLogin as:");
    while(1)
	{
        printf("\n1. Add Student");
        printf("\n2. Print student profile");
        printf("\n3. Print all student record.");
        printf("\n4. See course wise statistics");
        printf("\n5. Print all available courses.");
        printf("\n6. Add new course.");
        printf("\n7. Delete all courses.");
        printf("\n8. Delete all students.");
		printf("\n9. Exit");
//        printf("\n5. Exit");
		printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
               	res=CreateStudentProfile();
                break;
            case 2:
            	showSigleStudentByAny();
                break;
            case 3:
                showAllStudents();
                break;
            case 4:
            	while(1)
				{
					char coursecode[10];
					fflush(stdin);
			        printf("\nEnter course code:");
			        scanf("%s",coursecode);
			        fflush(stdin);
			        int coursenumber=isCourseFound(coursecode);
			        if(coursenumber!=-1)
			        {
			        	Course_wise_statistics(coursecode);
			        	break;
					}
					else
					{
			        	printf("\nEntered course code is not found.");			
					}
				}
            	break;
            case 5:
            	res=showCourse();
            	break;
        	case 6:
        		fflush(stdin);
        		printf("\nIf you will add the course then all the student record will be deleted--->press 1 to proceed.");
        		int k;
        		scanf("%d",&k);
        		if(k==1)
        		{
        			res=createCourse();
        			if(res==true)
        			{
        				DeleteAllStudentsRecord();
					}
        		}
				break;
        	case 7:
        		printf("\nAre you sure? Press 1 if continue...");
//        		int k;
        		fflush(stdin);
        		scanf("%d",&k);
        		if(k==1)
        		{
               		DeleteAllCourses();
				}
        		break;
        	case 8:
        		printf("\nAre you sure? Press 1 if continue...");
//        		int k;
        		fflush(stdin);
        		scanf("%d",&k);
        		if(k==1)
        		{
        			DeleteAllStudentsRecord();
				}
        		break;
			case 9:
                return;
                break;
            default:
                break;
        }
    }
    return;
}
