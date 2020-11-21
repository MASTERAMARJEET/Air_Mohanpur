#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include "objects.h"
#include "file.h"

void admin_page()
{
	// char 
	
	
	printf("\nWelcome Admins. Choose what do you want to do.\n");
	label;
	printf("If you wish to add new admins, type 'add_ad'.\n If you wish to view the admins, type 'view_ad'\n If you wish to add flights, type 'add_fl'\n If you wish to view the flights, type 'view_fl'\n");
	// scanf("");
	add_admin();
	goto label;
}

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
		printf("Function Aborted\n");
		admin_page();
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
		printf("Function aborted.\n");
		admin_page();
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
		printf("Function Aborted\n");
		admin_page();
		
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
		printf("Function Aborted\n");
		admin_page();
	}
}

