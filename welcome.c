#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include "objects.h"
#include "file.h"

void user_login()
{
	char us_access[4], us_access_No[7], us_user[7], us_pswd[7], us_gender;
	int i, rf;
	User user;

	printf("\nDo you have an account?\n Enter 'Yes' if you do or 'No' if you don't. \n");
	scanf("%4s", us_access);
	if (strcmp(us_access,"No")==0)
	{
		printf("\nDo you want to make an account?\n If yes, please enter 'Yes'. If no, please enter 'No'.\n");
		scanf("%3s", us_access_No);
		if (strcmp(us_access_No,"Yes")==0)
		{
			//user_length=sizeof(user)/sizeof(User);
			printf("\nEnter your name \t: \t");
			scanf("%50s", user.name);

			printf("\nChoose username \t: \t");
			scanf("%20s", user.id);

			printf("\nChoose password \t: \t");
			scanf("%20s", user.password);

			printf("\nEnter your age \t \t: \t");
			scanf("%d", &user.age);

			printf("\nEnter 'M' for Male, 'F' for female or 'O' for others.");
			printf("\nEnter your gender \t: \t");

			scanf("\n%c", &us_gender);
			switch (us_gender)
			{
				case 'M': user.gender = Male;
						  break;
				case 'F': user.gender = Female;
					      break;
				case 'O': user.gender = Others;
					      break;
				default:  printf("Input not in provided format. Choice not saved.");
					      break;
			}	

			printf("\nEnter your phone number \t: \t");
			scanf("%15s", user.phone_no);

			printf("\nEnter your email \t: \t");
			scanf("%50s", user.email);
				
			appendFile("data/User_list.txt",&user,sizeof(User),1); //check length of user array.
		}
		else 
		{
			printf("\nSorry, you can only proceed if you have an existing account or are making one.");
		}
	}

	else if (strcmp(us_access,"Yes")==0)
	{	
		User user_check[99];
		printf("\nEnter username : ");
		scanf("%6s", us_user);
		printf("\nEnter password : ");
		scanf("%6s", us_pswd);
		//have to search if these two exist and match.

	rf = readFile("data/User_list.txt",&user_check,sizeof(User),99);
	
	for (i=0; i<rf ; i=i+1)
		{
			if (strcmp(user_check[i].id, us_user)==0) 
	   		{
        		if(strcmp(user_check[i].password, us_pswd)==0) 
        		{
        			printf("Your Id is \t: %s and Password is \t: %s\n",user_check[i].id,user_check[i].password);
        		}
        	else {printf("Enter correct password!");}
    		}
   		else {printf("Username does not exist.");}
		}
	}
}


void admin_login()
{
	char ad_access[4], ad_access_No[7], ad_user[7], ad_pswd[7];
	int i, rf;

	printf("\nDo you have an account?\n Enter 'Yes' if you do or 'No' if you don't. \n");
	scanf("%3s", ad_access);
	if (strcmp(ad_access,"No")==0)
	{
		printf("\nDo you want to switch to user login?\n If yes, please enter 'ULogin'");
		scanf("%6s", ad_access_No);
		if (strcmp(ad_access_No,"ULogin")==0)
		{
			user_login();
			}
		else 
		{
			printf("\nSorry, only existing admins can add admin accounts.");
		}
	}

	else if (strcmp(ad_access,"Yes")==0)
	{
		Admin admin_check[99];
		printf("\nEnter admin username : ");
		scanf("%6s", ad_user);
		printf("\nEnter admin password : ");
		scanf("%6s", ad_pswd);
		//have to search if these two exist and match.

	rf = readFile("data/Admin_list.txt",&admin_check,sizeof(Admin),99);
	
	for (i=0; i<rf ; i=i+1)
		{
			if (strcmp(admin_check[i].id, ad_user)==0) 
	   		{
        		if(strcmp(admin_check[i].password, ad_pswd)==0) 
        		{
        			printf("Your Id is \t: %s and Password is \t: %s\n",admin_check[i].id,admin_check[i].password);
        		}
        	else {printf("Enter correct password!");}
    		}
   		else {printf("Admin username does not exist. Admin rights not defined.");}
		}
	}

	else
	{
		print:("\n Please enter one of the two choices listed above.:");
	}
}



void main()
{
printf("\n\t\t*****************************************************************\t\t\n");
printf("\n\t\t*********************WELCOME TO AIR MOHANPUR*********************\t\t\n");
printf("\n\t\t*****************************************************************\t\t\n");
printf("\n");

char access[3];
printf("\nWhat do you want to log in as? \n Enter 'Ad' for admin access or 'Us' for user access. \n PRESS 'ENTER' AFTER EVERY INPUT YOU GIVE. \n");
scanf("%2s", access);

if (strcmp(access,"Ad")==0)
{
	admin_login();
}

else if (strcmp(access,"Us")==0)
{
	user_login();	
}

else 
{
	printf("\nPlease enter a valid choice from the two listed above.");
}
}