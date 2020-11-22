#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "objects.h"
#include "file.h"

//function for cancelling ticket which are yet to be travelled
void cancel_ticket(char ticket_file[])
{
    int i=0, ticket_num, cticket_num;//for ticket number to be cancelled
    char sts[]="cancelled";

    Ticket tickets[20];//array of structure with size 20

    // ticket_num gives the maximum number of elements in the array of structure after reading the text file
    ticket_num = readFile(ticket_file,&tickets,sizeof(Ticket),20);

    // If the ticket_num is zero, then no ticket to cancel. Function exits right away
    if (ticket_num==0){
        printf("No records are found of your previous bookings. They don't exists");
        return;
    }

    //ticket number asked that has to be cancelled
    printf("Enter the ticket number of the flight you want to cancel: ");
    scanf("%d",&cticket_num);
    if(cticket_num <=ticket_num)//checking whether the ticket exists or not
	{

    for (i=0;i<ticket_num;i++)
    {   //cancelling the particular ticket
    	if(i+1 == cticket_num)
    	{   //details of the cancelled ticket
    		printf("Ticket No.: %d\n",i+1);
        	printf("Passanger Name: %s\n",tickets[i].psngr_name);
        	printf("Flight Number: %s\n",tickets[i].flight_no);
    		printf("Airline name: %s\n",tickets[i].airline_name);
        	printf("Source: %s",tickets[i].source);
			printf("\t\tDestination: %s \n", tickets[i].destination);
        	printf("Seat number: %s\n",tickets[i].seat_no);
        	printf("Arrival Time: %s \n",tickets[i].arrive_time);
        	printf("Departure Time: %s \n",tickets[i].depart_time);
        	printf("Fare: %f\n\n",tickets[i].fare);
            strcpy(tickets[i].status,sts);         //making the status of the ticket cancelled
            printf("Status: %s\n",tickets[i].status);

        	//updating the changes to the text file
            writeFile(ticket_file,&tickets,sizeof(Ticket),ticket_num);

		}
	}
	}
	else
	{
		printf("The ticket doesn't exist");//shows this if the ticket doesn't exist
	}

}


//function for booking history which will show details of the flights booked earlier
void show_booking_history(char ticket_file[])
{
    int i=0, ticket_num;
    char x[5], y[] ="yes";
    Ticket tickets[20]; //array of structure with size 20

    //ticket_num gives the maximum number of elements in the array of structure after reading the text file
    ticket_num = readFile(ticket_file,&tickets,sizeof(Ticket),20);

    //printing the information of the tickets booked by reading the text file
    printf("The tickets booked by you (%d in total) are listed below:\n\n", ticket_num);
    for (i=0;i<ticket_num;i++){
        printf("Ticket No.: %d\n",i+1);
        printf("Passanger Name: %s\n",tickets[i].psngr_name);
        printf("Flight Number: %s\n",tickets[i].flight_no);
    	printf("Airline name: %s\n",tickets[i].airline_name);
        printf("Source: %s",tickets[i].source);
		printf("\t\tDestination: %s \n", tickets[i].destination);
        printf("Seat number: %s\n",tickets[i].seat_no);
        printf("Arrival Time: %s \n",tickets[i].arrive_time);
        printf("Departure Time: %s \n",tickets[i].depart_time);
        printf("Fare: %f\n",tickets[i].fare);
        printf("Status: %s\n\n",tickets[i].status);
    }

    //asking the user if he wants to cancel any ticket
    printf("Do you wish to cancel any tickets that you are yet to tarvel(yes/no)?\n");
    scanf("%s",x);
    if(strcmp(x,y)==0) //comparing the input string
    {
    	cancel_ticket(ticket_file); //function called for cancelling ticket
    }
}


