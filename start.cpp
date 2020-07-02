#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<TeacherHeaderFile.h>
//#include<LoginHeaderFile.h>
int main()
{
	int choice;
//	printf("\nLogin as:");
    while(1)
	{
        printf("\n\n1. Admin");
        printf("\n2. Teacher");
        printf("\n3. O.S.");
        printf("\n4. Student");
        printf("\n5. Exit");
		printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
//            	printf("\nWe are ignoring admin module for this moment.");
                admin_main();
                break;
            case 2:
                Teacher_main();
                break;
            case 3:
                OS_main();
                break;
            case 4:
            	Student_function();//In teacher
                break;
            case 5:
                return 0;
                break;
            default:
                break;
        }

    }
}
