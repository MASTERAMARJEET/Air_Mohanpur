#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include "objects.h"
#include "file.h"

void user_login();
int contains_str();

void admin_search_flt(char mode){

    char flight_list_file[] = "data/flight_list.txt",prompt;
	char choice[20];
    Flight flights[100], filtered[100];
    int i, flight_num, filter_num;

    flight_num = readFile(flight_list_file,&flights,sizeof(Flight),100);

	choose:
	if (mode=='F'){
		printf("Enter the flight number: ");
		scanf("%s", choice);

		for (i=0;i<flight_num;i++){
			if (contains_str(flights[i].flight_no,choice)==1){
				filtered[filter_num]=flights[i];
				filter_num++;
			}
		}
	}
	else if (mode=='S'){
		printf("Enter the Source airport: ");
		scanf("%s", choice);

		for (i=0;i<flight_num;i++){
			if (contains_str(flights[i].source,choice)==1){
				filtered[filter_num]=flights[i];
				filter_num++;
			}
		}
	}
	else if (mode=='D'){
		printf("Enter the Destination airport: ");
		scanf("%s", choice);


		for (i=0;i<flight_num;i++){
			if (contains_str(flights[i].destination,choice)==1){
				filtered[filter_num]=flights[i];
				filter_num++;
			}
		}
	}

    if (filter_num==0){
        printf("\n\tSORRY.\nThe flight for your desired choice are unavailabe.\n");
        printf("If you want to retry with different input press R(otherwise press any other key): ");
        scanf("\n%c",&prompt);
        if (prompt=='R')
            goto choose;
    }
    else{
        printf("\n\nHere are the flights that match your search:\n\n");
        for ( i = 0; i < filter_num; i++)
        {
            printf("%d.\n",i+1);
            printf("Flight no.: %s\n",filtered[i].flight_no);
            printf("Source: %s\n",filtered[i].source);
            printf("Destination: %s\n",filtered[i].destination);
            printf("Airline Name: %s\n",filtered[i].airline_name);
            printf("Departure time: %s \t Arrival time: %s\n\n",filtered[i].depart_time, filtered[i].arrive_time);
        }
    }
}

void add_admin()
{
	char new_ad[4];
	Admin new_admin;

	printf("\nYou have chosen to add a new admin.\n Type 'Yes' to continue or 'No' to abort.\n");
	scanf("%4s", new_ad);
	if (strcmp(new_ad,"Yes")==0)
	{
		printf("\nChoose admin id \t: \t");
		scanf("%20s", new_admin.id);

		printf("\nChoose password \t: \t");
		scanf("%20s", new_admin.password);


		appendFile("data/admin_list.txt",&new_admin,sizeof(Admin),1);
	}
	else
	{
		printf("Choice aborted!!!\n");
	}
}

void view_admin()
{
	char view_ad[4];
	Admin view_admin[99];
	int i, admin_num;

	printf("\nYou have chosen to view admin list.\n Type 'Yes' to continue or 'No' to abort.\n");
	scanf("%4s", view_ad);
	if (strcmp(view_ad,"Yes")==0)
	{
		printf("\n The admin ids and passwords are visible now\n");
		admin_num = readFile("data/admin_list.txt",&view_admin,sizeof(Admin),99);

		for ( i = 0; i < admin_num; i++){
			printf("%d Admin Id: %s Admin Password: %s\n",i+1, view_admin[i].id, view_admin[i].password);
		}

	}
	else
	{
		printf("Choice aborted!!!\n");
	}

}

void view_user()
{
	char view_usr[4];
	User view_user[99];
	int i, usr_num;

	printf("\nYou have chosen to view user list.\n Type 'Yes' to continue or 'No' to abort.\n");
	scanf("%4s", view_usr);
	if (strcmp(view_usr,"Yes")==0)
	{
		printf("\n The user details are visible now\n");
		usr_num = readFile("data/user_list.txt",&view_user,sizeof(User),99);

		for ( i = 0; i < usr_num; i++){
			printf("%d.\n",i+1);
			printf("Name: %s\n",view_user[i].name);
			printf("User Id: %s User Password: %s\n", view_user[i].id, view_user[i].password);
			printf("Age: %d\n", view_user[i].age);
			switch (view_user[i].gender)
			{
				case Male: printf("Gender: Male\n");
						break;
				case Female: printf("Gender: Female\n");
						break;
				case Others: printf("Gender: Others\n");
						break;
			}

			printf("Phone No.: %s\n", view_user[i].phone_no);
			printf("Email: %s\n", view_user[i].email);
		}

	}
	else
	{
		printf("Choice aborted!!!\n");
	}

}

void add_flight()
{
	char new_fl[4], arrive[20], depart[20];
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

		printf("\nEnter time of arrival (enter 14:30 for 14:30 hrs) \t: \t");
		scanf("%16s", arrive);
		sprintf(new_flight.arrive_time,"%s hrs",arrive);

		printf("\nEnter time of departure (enter 14:30 for 14:30 hrs) \t: \t");
		scanf("%16s", depart);
		sprintf(new_flight.depart_time,"%s hrs",depart);

		printf("\nEnter the distance between two places \t: \t");
		scanf("%d", &new_flight.distance);

		printf("\nEnter capacity ie. total number of seats \t: \t");
		scanf("%d", &new_flight.total_seats);

		printf("\nEnter the number of seats available \t: \t");
		scanf("%d", &new_flight.seats_available);

		appendFile("data/flight_list.txt",&new_flight,sizeof(Flight),1);
		printf("Flight added. Here are the detail summary\n");

		printf("Flight no.: %s\n",new_flight.flight_no);
		printf("Source: %s\t",new_flight.source);
		printf("Destination: %s\n",new_flight.destination);
		printf("Airline Name: %s\n",new_flight.airline_name);
		printf("Departure time: %s \t Arrival time: %s\n",new_flight.depart_time, new_flight.arrive_time);
		printf("Total seats: %d\t Seats available: %d",new_flight.total_seats, new_flight.seats_available);

	}
	else
	{
		printf("Choice aborted!!!\n");
	}
}

void view_flight()
{
	char view_fl[4], choice, flt_file[] = "data/flight_list.txt", prompt;

	printf("\nYou have chosen to view the flights.\n Type 'Yes' to continue or 'No' to abort.\n");
	scanf("%4s", view_fl);
	if (strcmp(view_fl,"Yes")==0)
	{

		printf("You can view flight using Flight No. or Source or Destination.\n");
		printf("\nEnter\n - F - to search flights using flight no.\n");
		printf(" - S - to search flights using Source\n");
		printf(" - D - to search flights using Destination\n");
		printf(" - and press any other key to logout\n: ");
		scanf("\n%c",&choice);

		admin_search_flt(choice);
	}
	else
	{
		printf("Choice Aborted!!!\n");
	}
}



void admin_page()
{
	char ad_choice[10];

	printf("\nWelcome Admin. Choose what do you want to do.\n");

	label_admin_choice:
	printf("If you wish to add new admins, type 'add_ad'.\n");
	printf("If you wish to view the admins, type 'view_ad'\n");
	printf("If you wish to view the users, type 'view_usr'\n");
	printf("If you wish to add flights, type 'add_fl'\n");
	printf("If you wish to view the flights, type 'view_fl'\n");
	scanf("%9s", ad_choice);
	if (strcmp(ad_choice,"add_ad")==0)
	{
		add_admin();
	}
	else if (strcmp(ad_choice,"view_ad")==0)
	{
		view_admin();
	}
	else if (strcmp(ad_choice,"view_usr")==0)
	{
		view_user();
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
		 printf("Input not in provided format. Choice not saved.\n");
	}

	char next_ad_choice[10];
	label_ad_choice:
	printf("\nWhat do you want to do now?\n");
	printf("Enter 'Admin' to access more admin functions\n");
	printf("Enter 'User' to go to user interface\n");
	printf("Enter anything else to exit.\n");
	scanf("%10s", next_ad_choice);
	if (strcmp(next_ad_choice,"Admin")==0)
	{
		goto label_admin_choice;
	}
	else if (strcmp(next_ad_choice,"User")==0)
	{
		user_login();
	}
	else
	{
		printf("Thank You. Visit again!");}

}



void admin_login()
{
	char ad_access[4], ad_access_No[7], ad_user[20], ad_pswd[20];
	int i, rf, key=0;
	Admin admin_check[99];
	printf("\nDo you have an account?\n Enter 'Yes' if you do or 'No' if you don't. \n");
	scanf("%4s", ad_access);
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
		
		rf = readFile("data/admin_list.txt",&admin_check,sizeof(Admin),99);
		
		printf("\nEnter admin username : ");
		scanf("%20s", ad_user);
		
		printf("\nEnter admin password : ");
		scanf("%20s", ad_pswd);
		//have to search if these two exist and match.



		for (i=0; i<rf ; i=i+1)
		{
			if (strcmp(admin_check[i].id, ad_user)==0) 
			{
				pass_check:
				if(strcmp(admin_check[i].password, ad_pswd)==0) 
				{
						printf("Your login is sucessful!");
						key=1;
						admin_page();
				}
				else
				{
					printf("Enter correct password!");
					goto pass_check;
				}
			}
		}
		if (key==0){
			printf("Admin username does not exist. Admin rights not defined.");
		}
	}

	else
	{
		printf("\n Please enter one of the two choices listed above.:");
	}
}
