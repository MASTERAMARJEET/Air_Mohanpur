#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "objects.h"
#include "file.h"

void showbookinghistory(char ticket_file[])
{
    int i=0, ticket_num;
    Ticket tickets[20];

    ticket_num = readFile(ticket_file,&tickets,sizeof(Ticket),20);

    printf("The tickets booked by you (%d in total) are listed below:\n", ticket_num);

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
}

void cancelticket(char ticket_file[])
{
    int i=0, ticket_num, cticket_num;
    char sts[]="cancelled";
     
    Ticket tickets[20];

    ticket_num = readFile(ticket_file,&tickets,sizeof(Ticket),20);
    printf("Enter the ticket number of the flight you want to cancel:");
    scanf("%d",&cticket_num);
    for (i=0;i<ticket_num;i++)
    {
    	if(i+1 == cticket_num)
    	{
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
            strcpy(tickets[i].status,sts);
            printf("Status: %s\n",tickets[i].status);
        	
    		
		}
	}

}

// Driver Code
int main()
{
    char user_id[] = "demo_user";
    char user_file[50];
    strcpy(user_file,user_id);
    strcat(user_file,"_ticket.txt");

    char x[5],y[]="yes";
    printf("Do you wish to view your Booking History(yes/no)\n");
    scanf("%s",x);

    if(strcmp(x,y)==0) //listing booking history
    {
        showbookinghistory(user_file);
    }
    printf("Do you wish to cancel any file ticket that you are yet to tarvel(yes/no)\n");
    scanf("%s",x);
    
    if(strcmp(x,y)==0) //cancelling ticket
    {
    	cancelticket(user_file);
	}

   
    return 0;
}
