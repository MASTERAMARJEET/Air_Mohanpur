#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include "objects.h"
#include "file.h"

void user_login();

void add_admin()
{
	char new_ad[4];
	Admin new_admin;
	
	printf("\nYou have chosen to ad a new admin.\n Type 'Yes' to continue or 'No' to abort.\n");
	scanf("%4s", new_ad);
	if (strcmp(new_ad,"Yes")==0)
	{
		printf("\nChoose admin id \t: \t");
		scanf("%20s", new_admin.id);

		printf("\nChoose password \t: \t");
		scanf("%20s", new_admin.password);

						
		appendFile("data/Admin_list.txt",&new_admin,sizeof(Admin),1); 
	}
	else
	{
		printf("Choice aborted!!!\n");
		//admin_page();
	}
}

void view_admin()
{
	char view_ad[4];
	Admin view_admin;
	
	printf("\nYou have chosen to view admin list.\n Type 'Yes' to continue or 'No' to abort.\n");
	scanf("%4s", view_ad);
	if (strcmp(view_ad,"Yes")==0)
	{
		printf("\n The admin ids and passwords are visible now\n");
		readFile("data/Admin_list.txt",&view_admin,sizeof(Admin),99);
	}
	else
	{
		printf("Choice aborted!!!\n");
		//admin_page();
	}
	
}

void add_flight()
{
	char new_fl[4];
	Flight new_flight;
	
	printf("\nYou have chosen to add a new flight.\n Type 'Yes' to continue or 'No' to abort.\n");
	scanf("%4s", new_fl);
	if (strcmp(new_fl,"Yes")==0)
	{
		printf("\nEnter source of flight \t: \t");
		scanf("%20s", new_flight.source);

		printf("\nEnter destination of flight \t: \t");
		scanf("%20s", new_flight.destination);

		printf("\nEnter flight number \t: \t");
		scanf("%16s", new_flight.flight_no);

		printf("\nEnter name of the airline \t: \t");
		scanf("%16s", new_flight.airline_name);

		printf("\nEnter time of arrival \t: \t");
		scanf("%16s", new_flight.arrive_time);
		
		printf("\nEnter time of departure \t: \t");
		scanf("%16s", new_flight.depart_time);
		
		printf("\nEnter capacity ie. total number of seats \t: \t");
		scanf("%d", new_flight.total_seats);
		
		printf("\nEnter the number of seats available \t: \t");
		scanf("%d", new_flight.seats_available);
		
		appendFile("data/flight_list.txt",&new_flight,sizeof(Flight),1);

	}
	else
	{
		printf("Choice aborted!!!\n");
		//admin_page();
		
	}
}

void view_flight()
{
	char view_fl[4];
	Flight view_flights;
	
	printf("\nYou have chosen to view the flights.\n Type 'Yes' to continue or 'No' to abort.\n");
	scanf("%4s", view_fl);
	if (strcmp(view_fl,"Yes")==0)
	{
		printf("The flight list is visible now.\n");
		readFile("data/flight_list.txt",&view_flights,sizeof(Flight),99);
	}
	else
	{
		printf("Function Aborted!!!\n");
		//admin_page();
	}
}



void admin_page()
{
	char ad_choice[10];
	
	printf("\nWelcome Admin. Choose what do you want to do.\n");

	label_admin_choice:
	printf("If you wish to add new admins, type 'add_ad'.\n If you wish to view the admins, type 'view_ad'\n If you wish to add flights, type 'add_fl'\n If you wish to view the flights, type 'view_fl'\n");
	scanf("%9s", ad_choice);
	if (strcmp(ad_choice,"add_ad")==0)
	{
		add_admin();
	}
	else if (strcmp(ad_choice,"view_ad")==0)
	{
		view_admin();
	}
	else if (strcmp(ad_choice,"add_fl")==0)
	{
		add_flight();
	}
	else if (strcmp(ad_choice,"view_fl")==0)
	{
		view_flight();
	}
	else 
	{
		 printf("Input not in provided format. Choice not saved.");
	}

	goto label;
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

	rf = readFile("data\\Admin_list.txt",&admin_check,sizeof(Admin),99);
	
	for (i=0; i<rf ; i=i+1)
		{
			if (strcmp(admin_check[i].id, ad_user)==0) 
	   		{
        		if(strcmp(admin_check[i].password, ad_pswd)==0) 
        		{
        			printf("Your Id is \t: %s and Password is \t: %s\n",admin_check[i].id,admin_check[i].password);
        			printf("Your login is sucessful!");
        			admin_page();
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