#include <stdio.h>
#include <string.h>
#include "objects.h"
#include "file.h"
//function declaration
void user_login();
int contains_str();

void admin_search_flt(char mode)    //function for admins to search flights
{   
    char flight_list_file[] = "data/flight_list.txt",prompt;   //flight list called
	char choice[20]; //variable declared for admin choice
    Flight flights[100], filtered[100];  //array of structure for pre existing flights and for the filtered flight
    int i, flight_num, filter_num;  //variable declared for counter and number of elements in the flight list and filtered flight list

    flight_num = readFile(flight_list_file,&flights,sizeof(Flight),100);  //reading the list of flights

	choose:
	if (mode=='F'){   //admin searching using flight number
		printf("Enter the flight number: ");
		scanf("%s", choice);

		for (i=0;i<flight_num;i++){   //this loop runs till all the flights with the flight number is visible with the details
			if (contains_str(flights[i].flight_no,choice)==1){
				filtered[filter_num]=flights[i];
				filter_num++;
			}
		}
	}
	else if (mode=='S'){   //admin searching using flight source airport
		printf("Enter the Source airport: ");
		scanf("%s", choice);

		for (i=0;i<flight_num;i++){       //this loop runs till all the flights with the same source airport is visible with the details 
			if (contains_str(flights[i].source,choice)==1){
				filtered[filter_num]=flights[i];
				filter_num++;
			}
		}
	}
	else if (mode=='D'){   //admin searching using flight destination
		printf("Enter the Destination airport: ");
		scanf("%s", choice);


		for (i=0;i<flight_num;i++){   //this loop runs till all the flights with the same destination airport is visible with the details
			if (contains_str(flights[i].destination,choice)==1){
				filtered[filter_num]=flights[i];
				filter_num++;
			}
		}
	}

    if (filter_num==0){    //if the choice admin enters does not match with any flights this meassage is visible
        printf("\n\tSORRY.\nThe flight for your desired choice are unavailabe.\n");
        printf("If you want to retry with different input press R(otherwise press any other key): ");
        scanf("\n%c",&prompt);    //recording choice if admin wants to retry
        if (prompt=='R')
            goto choose;  //retuening to the initial choosing modes
    }
    else{
        printf("\n\nHere are the flights that match your search:\n\n");   //displaying the details of flights which matched in the search
        for ( i = 0; i < filter_num; i++)
        {
            printf("%d.\n",i+1);    //serial number
            printf("Flight no.: %s\n",filtered[i].flight_no);
            printf("Source: %s\n",filtered[i].source);             //details of the flight
            printf("Destination: %s\n",filtered[i].destination);
            printf("Airline Name: %s\n",filtered[i].airline_name);
            printf("Departure time: %s \t Arrival time: %s\n\n",filtered[i].depart_time, filtered[i].arrive_time);
        }
    }
}

void add_admin()  //function for admins to add a new admin
{
	char new_ad[4]; //variable declaration for admin choice
	Admin new_admin; //array of structure for new admins

	printf("\nYou have chosen to add a new admin.\n Type 'Yes' to continue or 'No' to abort.\n");
	scanf("%4s", new_ad);  //choice of admins to continue or abort
	
	if (strcmp(new_ad,"Yes")==0)
	{
		printf("\nChoose admin id \t: \t");
		scanf("%20s", new_admin.id);   //for new admin id

		printf("\nChoose password \t: \t");
		scanf("%20s", new_admin.password); //for new admin password


		appendFile("data/admin_list.txt",&new_admin,sizeof(Admin),1); //updating the list of admins
	}
	else
	{
		printf("Choice aborted!!!\n");   //message shown if admin types any other strings
	}
}

void view_admin()  //function to view admin details
{
	char view_ad[4];  //variable declaration for admin choice
	Admin view_admin[99];  //array of structure for pre existing admins in the system
	int i, admin_num;   //variable declared for counter and number of elements in the admin list

	printf("\nYou have chosen to view admin list.\n Type 'Yes' to continue or 'No' to abort.\n");
	scanf("%4s", view_ad);  //choice for admins to continue or abort
	
	if (strcmp(view_ad,"Yes")==0)   //admin chooses to view admin details
	{
		printf("\n The admin ids and passwords are visible now\n");
		admin_num = readFile("data/admin_list.txt",&view_admin,sizeof(Admin),99);  //reading the admin_list.txt file

		for ( i = 0; i < admin_num; i++) //as counter variable increases, one by one the admin details are diplayed. the loop continues for (admin_num - 1) times
		{
			printf("%d Admin Id: %s Admin Password: %s\n",i+1, view_admin[i].id, view_admin[i].password); //displaying admin information
		}

	}
	else
	{
		printf("Choice aborted!!!\n");  //message shown if admin types any other strings
	}

}

void view_user()
{
	char view_usr[4];  //variable declaration for admin choice 
	User view_user[99];  //array of structure for pre existing users 
	int i, usr_num;   //variable declared for counter and number of elements in the user list

	printf("\nYou have chosen to view user list.\n Type 'Yes' to continue or 'No' to abort.\n");
	scanf("%4s", view_usr);   //recording admin choice
	
	if (strcmp(view_usr,"Yes")==0)   //admin chooses to view the user details
	{
		printf("\n The user details are visible now\n");
		usr_num = readFile("data/user_list.txt",&view_user,sizeof(User),99);   //reading the user details from the user_list.txt

		for ( i = 0; i < usr_num; i++) //as counter variable increases, one by one the users are diplayed. the loop continues for (user_num - 1) times
		{
			printf("%d.\n",i+1);    //for displaying the serial numbr of users
			printf("Name: %s\n",view_user[i].name);   //for displaying username 
			printf("User Id: %s User Password: %s\n", view_user[i].id, view_user[i].password);  //for displaying user password
			printf("Age: %d\n", view_user[i].age);    //for displaying age of user
			switch (view_user[i].gender)
			{
				case Male: printf("Gender: Male\n");
						break;
				case Female: printf("Gender: Female\n");    //for displaying the gender of user
						break;
				case Others: printf("Gender: Others\n");
						break;
			}

			printf("Phone No.: %s\n", view_user[i].phone_no);  //for displaying user phone number
			printf("Email: %s\n", view_user[i].email);   //for displaying the email id of user
		}

	}
	else
	{
		printf("Choice aborted!!!\n");    //message shown if admin types any other strings
	}

}

void add_flight()   //function to add a new flight
{
	char new_fl[4], arrive[20], depart[20];  //variable declaration for admin choice and for recording the arrival and departure time
	Flight new_flight;    //array of structure for entering a new flight

	printf("\nYou have chosen to add a new flight.\n Type 'Yes' to continue or 'No' to abort.\n");
	scanf("%4s", new_fl);   //admin choice recorded
	
	if (strcmp(new_fl,"Yes")==0)   //admin chooses to add a flight
	{
		printf("\nEnter source of flight \t: \t");  //entering source of flight
		scanf("%20s", new_flight.source);

		printf("\nEnter destination of flight \t: \t");   //entering fligh destination
		scanf("%20s", new_flight.destination);

		printf("\nEnter flight number \t: \t");  //entering flight number
		scanf("%16s", new_flight.flight_no);

		printf("\nEnter name of the airline \t: \t");   //entering airline name
		scanf("%16s", new_flight.airline_name);

		printf("\nEnter time of arrival (enter 14:30 for 14:30 hrs) \t: \t");   //entering arrival time
		scanf("%16s", arrive);
		sprintf(new_flight.arrive_time,"%s hrs",arrive);

		printf("\nEnter time of departure (enter 14:30 for 14:30 hrs) \t: \t");  //entering departure time
		scanf("%16s", depart);
		sprintf(new_flight.depart_time,"%s hrs",depart);

		printf("\nEnter the distance between two places \t: \t");   //entering distance between two places
		scanf("%d", &new_flight.distance);

		printf("\nEnter capacity ie. total number of seats \t: \t");  //entering capacity of flight
		scanf("%d", &new_flight.total_seats);

		printf("\nEnter the number of seats available \t: \t");  //entering the number of seats which are available
		scanf("%d", &new_flight.seats_available); 

		appendFile("data/flight_list.txt",&new_flight,sizeof(Flight),1);  //adding the new flight in the flight list
		
		printf("Flight added. Here are the detail summary\n");  //diplaying the detailed summery of the new flight added
		
		/* here the elements of the array are called are arranged to view the flight details added */
		printf("Flight no.: %s\n",new_flight.flight_no);  
		printf("Source: %s\t",new_flight.source);    
		printf("Destination: %s\n",new_flight.destination);
		printf("Airline Name: %s\n",new_flight.airline_name);
		printf("Departure time: %s \t Arrival time: %s\n",new_flight.depart_time, new_flight.arrive_time);
		printf("Total seats: %d\t Seats available: %d",new_flight.total_seats, new_flight.seats_available);

	}
	else
	{
		printf("Choice aborted!!!\n");    //message displayed if admin aborts the process
	}
}

void view_flight()   //function for viewing a flight
{
	char view_fl[4], choice, flt_file[] = "data/flight_list.txt", prompt;  //variable declaration for admin choice of viewing the files 

	printf("\nYou have chosen to view the flights.\n Type 'Yes' to continue or 'No' to abort.\n");
	scanf("%4s", view_fl);  //for recording admin choice
	
	if (strcmp(view_fl,"Yes")==0)  //admin wants to continue and view a flight
	{

		printf("You can view flight using Flight No. or Source or Destination.\n");
		printf("\nEnter\n - F - to search flights using flight no.\n");
		printf(" - S - to search flights using Source\n");                    //here the admin chooses to filter which flight to view
		printf(" - D - to search flights using Destination\n");
		printf(" - and press any other key to logout\n: ");
		scanf("\n%c",&choice);  //for recording admin choice

		admin_search_flt(choice);   //function for viewing a single flight
	}
	else
	{
		printf("Choice Aborted!!!\n");   //message displayed if admin aborts the process
	}
}



void admin_page()  //main admin interface for selection of admin functions
{
	char ad_choice[10];  //variable declaration for admin choice

	printf("\nWelcome Admin. Choose what do you want to do.\n");

	label_admin_choice:
	printf("If you wish to add new admins, type 'add_ad'.\n");
	printf("If you wish to view the admins, type 'view_ad'\n");    //here, admin chooses what he or she wants to do
	printf("If you wish to view the users, type 'view_usr'\n");
	printf("If you wish to add flights, type 'add_fl'\n");
	printf("If you wish to view the flights, type 'view_fl'\n");
	scanf("%9s", ad_choice);     //for recording admin choice
	
	if (strcmp(ad_choice,"add_ad")==0)
	{
		add_admin();  //if admin chooses to add a new admin, he is directed to this function
	}
	else if (strcmp(ad_choice,"view_ad")==0)
	{
		view_admin();  //if admin chooses to view admin list, he is directed to this function
	}
	else if (strcmp(ad_choice,"view_usr")==0)
	{
		view_user();  //if the admin chooses to view the user list, he is directed to this function
	}
	else if (strcmp(ad_choice,"add_fl")==0)
	{
		add_flight();  //if the admin wishes to add flights, he is directed to this function
	}
	else if (strcmp(ad_choice,"view_fl")==0)
	{
		view_flight();  //if admin chooses to view a flight or the flight list, he is directed to this function
	}
	else
	{
		 printf("Input not in provided format. Choice not saved.\n");   //message displayed if admin doen not give a suitable input
	}

	char next_ad_choice[10];  //variable declaration for admin choice
	label_ad_choice:
	printf("\nWhat do you want to do now?\n");                 //this section is for the admins to choose what to do next 
	printf("Enter 'Admin' to access more admin functions\n");
	printf("Enter 'User' to go to user interface\n");
	printf("Enter anything else to exit.\n");
	scanf("%10s", next_ad_choice);
	if (strcmp(next_ad_choice,"Admin")==0)
	{
		goto label_admin_choice;   //admin returns to the admin interface to continue
	}
	else if (strcmp(next_ad_choice,"User")==0)
	{
		user_login();  //return to user login page
	}
	else
	{
		printf("Thank You. Visit again!");} //admin completes his job

}



void admin_login()  //function for admin login
{
	char ad_access[4], ad_access_No[7], ad_user[20], ad_pswd[20];  //variable declaration for admin choice
	int i, rf, key=0;     //variable declared for counter and number of elements in the admin list and a toggle switch is chosen
	Admin admin_check[99];  //array of structure for pre existing admins
	
	printf("\nDo you have an account?\n Enter 'Yes' if you do or 'No' if you don't. \n");
	scanf("%4s", ad_access);  //entering choice of the person
	
	if (strcmp(ad_access,"No")==0)   //if someone does not have an account
	{
		printf("\nDo you want to switch to user login?\n If yes, please enter 'ULogin'");
		scanf("%6s", ad_access_No);  //choice if the person wants to go to the user interface
		
		if (strcmp(ad_access_No,"ULogin")==0)  //the person chooses to go to user page
		{
			user_login();   //directed to user login page
			}
		else 
		{
			printf("\nSorry, only existing admins can add admin accounts.");   
			/* if the person does not want to return to user interface,
			this message is diplayed */
		}
	}

	else if (strcmp(ad_access,"Yes")==0) //the person has an admin account
	{
		
		rf = readFile("data/admin_list.txt",&admin_check,sizeof(Admin),99); 
		//matching/comparing the information of the admin id and password to declare login successful or inavlid login attempt
		
		printf("\nEnter admin username : ");  //for entering admin user name
		scanf("%20s", ad_user);  //
		
		printf("\nEnter admin password : ");  //for entering admin password
		scanf("%20s", ad_pswd);
		//have to search if these two exist and match.



		for (i=0; i<rf ; i=i+1)
		{
			if (strcmp(admin_check[i].id, ad_user)==0)  //checking if input admin id matches with the list
			{
				pass_check:
				if(strcmp(admin_check[i].password, ad_pswd)==0)  //checking is input admin password matches with the list
				{
						printf("Your login is sucessful!");  //if the input admin id and password matches this message shows up 
						key=1;    //her the key changes to 1
						admin_page();  //directs the admin to admin interface
				}
				else    //if the password doesn't match it asks to re enter password
				{
					printf("Enter correct password!");
					goto pass_check;
				}
			}
		}
		if (key==0)     //if the x does not change that means niether the admin id match nor the password
		{
			printf("Admin username does not exist. Admin rights not defined.");   //message shown for invalid login attempt
		}
	}

	else
	{
		printf("\n Please enter one of the two choices listed above.:");  //message shown if admin types any other strings
	}
}
