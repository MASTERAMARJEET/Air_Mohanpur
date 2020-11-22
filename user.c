#include <stdio.h>
#include <string.h>
#include "objects.h"
#include "file.h"
//function declaration
void user_home(User user);

void show_booking_history(char ticket_file[]);

void search_flight(User user);

void authenticate_user();

void create_user()     //function for creating new user
{
	char us_gender;    //variable declared for gender
	int i, rf;         //variable declared for counter and number of elements in the user list
	User new_user, user_username_check[99]; //array of structure for pre existing users and new user

	rf = readFile("data/user_list.txt",&user_username_check,sizeof(User),99);

	//user_length=sizeof(user)/sizeof(User);
	printf("\nEnter your name \t: \t");
	scanf("%50s", new_user.name); //for new user name

	username_check_goto:
	printf("\nChoose username \t: \t");
	scanf("%20s", new_user.id); //for new  username
	//for checking whether entered  username already exists or not
	for (i=0; i<rf ; i=i+1)
		{
			if (strcmp(user_username_check[i].id, new_user.id)==0)  //comparing new username with any previous one
	   		{
				printf("Username already exists. Try a different one");//if username already exists shows this message
	   			goto username_check_goto;
	   		}
	   		else
	   		{
	   			break; //goes out of the loop
	   		}
	   	}

	printf("\nChoose password \t: \t");
	scanf("%20s", new_user.password); //for new password

	printf("\nEnter your age \t \t: \t");
	scanf("%d", &new_user.age); //for age

	printf("\nEnter 'M' for Male, 'F' for female or 'O' for others.");
	printf("\nEnter your gender \t: \t"); //for the gender

	scanf("\n%c", &us_gender);
	switch (us_gender)                    //assigns gender as chosen accordingly like M=male,F+ femaleand O = others
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
	scanf("%15s", new_user.phone_no); //for phone number

	printf("\nEnter your email \t: \t");
	scanf("%50s", new_user.email); //for email 

	appendFile("data/user_list.txt",&new_user,sizeof(User),1); //appending the new user to pre existing list of users 
	//check length of user array.

	printf("Account Creation successful! Now, you can login.\n"); //shows this message once the new account is created

	authenticate_user(); //calling the authenticate_user function to validate the successful account formation
}





void authenticate_user() //function for authenticating the user accounts with user name and passwords
{
	char us_user[20], us_pswd[20]; //variables declared for the input of the username and the password
	int x=0, i, rf; //variable declared for counter and number of elements in the user list and also x is initialized to 0
	User user_check[99]; //array of structure with size cap 99

	printf("\nEnter username : ");
	scanf("%20s", us_user); //for entering username

	label_password_check:
	printf("\nEnter password : ");
	scanf("%20s", us_pswd); //for entering password

	rf = readFile("data/user_list.txt",&user_check,sizeof(User),99);
	//matching/comparing the information of the username and password to declare login successful or inavlid login attempt
	for (i=0; i<rf ; i=i+1)
		{
		if (strcmp(user_check[i].id, us_user)==0)
	   		{
        	if(strcmp(user_check[i].password, us_pswd)==0)
        		{
        			printf("Login Successful!\n"); //if the input username and password matches this message shows up 
        			x = 1; //x is changing here to 1
					user_home(user_check[i]);
        			break;
        		}
        	else                //if the password doesn't match it asks to re enter password
        		{
        			printf("Enter correct password!");
    				goto label_password_check;
				}
			break;
    		}
		}

	if (x==0) //if the x does not change that means niether the username match nor the password
	{
		printf("Invalid login attempt!!!"); //message shown for invalid login attempt
	}

}





void user_login() //function at the begining asking user basic questions 
{
	char us_access[4], us_access_No[7]; //char variables declared
	//aking whether the user has a previous account or not 
	printf("\nDo you have an account?\n Enter 'Yes' if you do or 'No' if you don't. \n");
	scanf("%4s", us_access);
	//if the user doesn't have an account it proceeds with if the user is interested in making an account
	if (strcmp(us_access,"No")==0)
	{
		printf("\nDo you want to make an account?\n If yes, please enter 'Yes'. If no, please enter 'No'.\n");
		scanf("%3s", us_access_No);
		if (strcmp(us_access_No,"Yes")==0)
		{
			create_user(); //calls the function where an account is made with all the details asking from the user
		}
		else //shows this message if the user doesn't make an account or if the user already doesn't have an account
		{
			printf("\nSorry, you can only proceed if you have an existing account or are making one.");
		}
	}

	else if (strcmp(us_access,"Yes")==0) /*if the user already has an account it goes for authenticating his/her account 
										basically login in to his/her account*/
	{
		authenticate_user(); //calling the function to validate the already existing account 
	}
}




void user_home(User user){

    char user_file[50];              //blank string with size 50
    char choice;
	strcpy(user_file,"data/");       //adding 'data' folder path to the file name
    strcat(user_file,user.id);       //concatinating user_id to user_file
    strcat(user_file,"_tickets.txt");//concatinating "_tickets.txt" to user_file

	printf("Welcome %s\n",user.name); //welcoming the user
    start:
    	//options are given to the user whether the user wants to see previous booking or to search new flights 
	printf("\nEnter\n - A - to review your previous booking history and cancel a ticket that you are yet to travel\n");
	printf(" - B - to search and book a new flight\n");
	printf(" - and press any other key to logout\n: ");
	scanf("\n%c",&choice);

	switch (choice)
	{
		case 'A': show_booking_history(user_file); //calls the booking history function which shows the previous bookings
                goto start;
				break;
		case 'B': search_flight(user); //calls the search flight function which searches new flight for the user to book
                goto start;
				break;
		default:  printf("Thank You. Visit again!"); //shows this output when the user doesn't choose anything
					break;
	}

}


