#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct log
{
	char username[20];
	int id;//1 for admin  2 for OS
	char password[20];
};
bool createlogin(int i)
{
	int flag=0;
	char username[20];
	char password[20];
	FILE *fp;
	struct log l;	
	while(1)
	{
		flag=0;
		fflush(stdin);
		printf("\nEnter username:");
		scanf("%[^\n]",username);
		fp=fopen("loginperson.dat","r");
		struct log l2;
		while (fread (&l2, sizeof(struct log), 1, fp))
	    { 
	    	if(l2.id==i)
	    	{
	    		if(strcmp(l2.username,username)==0)
	    		{
	    			printf("\nUsername already exist.");
	    			flag=1;
				}
			}
		}
		fclose(fp);
		if(flag!=1)
		{
			break;
		}
	}
	fflush(stdin);
	strcpy(l.username,username);
	printf("\nEnter password:");
	scanf("%[^\n]",l.password);
	
	fp=fopen("loginperson.dat","a+");
	if(i==1 || i==2)
	{
		l.id=i;
		fwrite (&l, sizeof(struct log), 1, fp);
		printf("\nSuccessful.");
		fclose(fp);
		return true;
	}
	else
	{
		fclose(fp);
		printf("\n id is not 1 or 2   at createlogin in LoginHeaderFile.");
		return false;
	}
		return false;
}
void showlogin(int i)
{
	struct log l;
	FILE *fp;
	fp= fopen ("loginperson.dat", "r");
	printf("\nUsername         Password");
	printf("\n------------------------------------------------------------------------------------------");
	while (fread (&l, sizeof(struct log), 1, fp))
	{
		if(l.id==i)
		{
			printf("\n%s             %s",l.username,l.password);
		}
	}
	printf("\n");
	fclose(fp);
}
bool DeleteLogin(int i)
{
	char username[20];
	int flag=0;
	struct log l;
	FILE *fp,*fp1;
	fp= fopen ("loginperson.dat", "a+");
	fp1= fopen ("loginperson2.dat", "w");
	fflush(stdin);
	printf("\nEnter username:");
	scanf("%[^\n]",username);
	while (fread (&l, sizeof(struct log), 1, fp))
	{
		if(l.id==i)
		{
			if(strcmp(l.username,username)==0)
			{
				flag=1;
				continue;
			}
			fwrite (&l, sizeof(struct log), 1, fp1);
		}
		else
		{
			fwrite (&l, sizeof(struct log), 1, fp1);
		}
	}
	fclose(fp);
  	fclose(fp1);
	remove("loginperson.dat");
  	rename("loginperson2.dat","loginperson.dat");
  	if(flag==1)
  	{
  		printf("\nRecord deleted.");
  		return true;
	  }
	  else
	  {
	  	printf("\nRecord does not found.");
  		return false;
	  }
}
bool login(int i)
{
	char username[20];
	char password[20];
	FILE *fp;
	fp=fopen("loginperson.dat","r");
	struct log l;
	fflush(stdin);
	printf("\nEnter username:");
	scanf("%[^\n]",username);
	fflush(stdin);
	printf("\nEnter password:");
	scanf("%[^\n]",password);
	while (fread (&l, sizeof(struct log), 1, fp))
	{
		if(l.id==i)
		{
			if(strcmp(l.username,username)==0)
			{
				if(strcmp(l.password,password)==0)
				{
					printf("\nLogged in successful.");
					fclose(fp);
					return true;
				}
			}
		}
	}
	printf("Login Failed!");
	fclose(fp);
	return false;	
}
void admin_main()
{
//	createlogin(1);
//	return;	
	while(1)
	{
		bool res=login(1);
		if(res==true)
		{
			break;
		}
	}
	int choice;
    while(1)
	{
        printf("\n1. Create Admin");
        printf("\n2. Create OS.");
        printf("\n3. Delete Admin");
        printf("\n4. Delete OS.");
        printf("\n5. See Admin.");
        printf("\n6. See OS");
        printf("\n7. Back");
		printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                createlogin(1);
                break;
            case 2:
                createlogin(2);
                break;
            case 3:
                DeleteLogin(1);
                break;
            case 4:
                DeleteLogin(2);
                break;
            case 5:
                showlogin(1);
                break;
            case 6:
                showlogin(2);
                break; 
			case 7:
                return;
                break; 	   
            default:
                break;
        }
    }
}
