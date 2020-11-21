#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include "objects.h"
#include "file.h"


void create_user()
{	
char us_gender;		
	int i, rf;
	User new_user, user_username_check[999];

	rf = readFile("data\\User_list.txt",&user_username_check,sizeof(User),999);

	//user_length=sizeof(user)/sizeof(User);
	printf("\nEnter your name \t: \t");
	scanf("%50s", new_user.name);

	username_check_goto:
	printf("\nChoose username \t: \t");
	scanf("%20s", new_user.id);

	for (i=0; i<rf ; i=i+1)
		{
			if (strcmp(user_username_check[i].id, new_user.id)==0) 
	   		{
	   			goto username_check_goto;
	   		}
	   		else
	   		{
	   			break;
	   		}
	   	}

	printf("\nChoose password \t: \t");
	scanf("%20s", new_user.password);

	printf("\nEnter your age \t \t: \t");
	scanf("%d", &new_user.age);

	printf("\nEnter 'M' for Male, 'F' for female or 'O' for others.");
	printf("\nEnter your gender \t: \t");

	scanf("\n%c", &us_gender);
	switch (us_gender)
	{
		case 'M': new_user.gender = Male;
				  break;
		case 'F': new_user.gender = Female;
			      break;
		case 'O': new_user.gender = Others;
			      break;
		default:  printf("Input not in provided format. Choice not saved.");
			      break;
	}	

	printf("\nEnter your phone number \t: \t");
	scanf("%15s", new_user.phone_no);

	printf("\nEnter your email \t: \t");
	scanf("%50s", new_user.email);
				
	appendFile("data\\User_list.txt",&new_user,sizeof(User),1); //check length of user array.
}





void authenticate_user()
{	
	char us_user[7], us_pswd[7];
	int i, rf;
	User user_check[99];

	printf("\nEnter username : ");
	scanf("%6s", us_user);
	printf("\nEnter password : ");
	scanf("%6s", us_pswd);

	rf = readFile("data\\User_list.txt",&user_check,sizeof(User),99);
	
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





void user_login()
{
	char us_access[4], us_access_No[7];

	printf("\nDo you have an account?\n Enter 'Yes' if you do or 'No' if you don't. \n");
	scanf("%4s", us_access);

	if (strcmp(us_access,"No")==0)
	{
		printf("\nDo you want to make an account?\n If yes, please enter 'Yes'. If no, please enter 'No'.\n");
		scanf("%3s", us_access_No);
		if (strcmp(us_access_No,"Yes")==0)
		{
			create_user();
		}
		else 
		{
			printf("\nSorry, you can only proceed if you have an existing account or are making one.");
		}
	}

	else if (strcmp(us_access,"Yes")==0)
	{
		authenticate_user();
	}
}






