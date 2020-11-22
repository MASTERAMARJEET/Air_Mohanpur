#include <stdio.h>
#include <string.h>
#include "objects.h"
#include "file.h"

void user_home(User user);

void show_booking_history(char ticket_file[]);

void search_flight(User user);


void create_user()
{
	char us_gender;
	int i, rf;
	User new_user, user_username_check[99];

	rf = readFile("data/User_list.txt",&user_username_check,sizeof(User),99);

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
				printf("Username already exists. Try a different one");
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
	char us_user[20], us_pswd[20];
	int x=0, i, rf;
	User user_check[99];

	printf("\nEnter username : ");
	scanf("%20s", us_user);

	label_password_check:
	printf("\nEnter password : ");
	scanf("%20s", us_pswd);

	rf = readFile("data/User_list.txt",&user_check,sizeof(User),99);
	printf("%d \n", rf);
	for (i=0; i<rf ; i=i+1)
		{
		if (strcmp(user_check[i].id, us_user)==0)
	   		{
        	if(strcmp(user_check[i].password, us_pswd)==0)
        		{
        			printf("Login Successful!\n");
        			x = 1;
					user_home(user_check[i]);
        			break;
        		}
        	else
        		{
        			printf("Enter correct password!");
    				goto label_password_check;
				}
			break;
    		}
		}

	if (x==0)
	{
		printf("Invalid login attempt!!!");
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




void user_home(User user){

    char user_file[50];              //blank string with size 50
    char choice;
	strcpy(user_file,"data/");       //adding 'data' folder path to the file name
    strcat(user_file,user.id);       //concatinating user_id to user_file
    strcat(user_file,"_tickets.txt");//concatinating "_tickets.txt" to user_file

	printf("Welcome %s\n",user.name);
    start:
	printf("\nEnter\n - A - to review your previous booking history and cancel a ticket that you are yet to tarvel\n");
	printf(" - B - to search and book a new flight\n");
	printf(" - and press any other key to logout\n: ");
	scanf("\n%c",&choice);

	switch (choice)
	{
		case 'A': show_booking_history(user_file);
                goto start;
				break;
		case 'B': search_flight(user);
                goto start;
				break;
		default:  printf("Thank You. Visit again:");
					break;
	}

}


