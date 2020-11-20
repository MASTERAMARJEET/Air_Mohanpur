#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "objects.h"
#include "file.h"
//function for booking history
void showbookinghistory(char ticket_file[])
{
    int i=0, ticket_num;
    Ticket tickets[20]; //array of structure with size 20

    ticket_num = readFile(ticket_file,&tickets,sizeof(Ticket),20);
//ticket_num gives the maximum number of elements in the array of structure after reading the text file
    printf("The tickets booked by you (%d in total) are listed below:\n", ticket_num);
//printing the information of the tickets booked by reading the text file
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
//function for cancelling ticket
void cancelticket(char ticket_file[])
{
    int i=0, ticket_num, cticket_num;//for ticket number to be cancelled
    char sts[]="cancelled";
     
    Ticket tickets[20];//array of structure with size 20
//ticket_num gives the maximum number of elements in the array of structure after reading the text file
    ticket_num = readFile(ticket_file,&tickets,sizeof(Ticket),20);
    //ticket number asked that has to be cancelled
    printf("Enter the ticket number of the flight you want to cancel:");
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
            strcpy(tickets[i].status,sts);         //copying the status of the ticket to cancelled
            printf("Status: %s\n",tickets[i].status);
            writeFile(ticket_file,&tickets,sizeof(Ticket),ticket_num);
        	//updating the changes to the text file
    		
		}
	}
	}
	else
	{
		printf("The ticket doesn't exist");//shows this if the ticket doesn't exist
	}

}

// Driver Code
int main()
{
    char user_id[] = "demo_user";    //string declared "demo_user"     
    char user_file[50];              //blank string with size 51
    strcpy(user_file,"data/");       //copying the userfile to Data folder
    strcat(user_file,user_id);       //concatinating user_id to user_file
    strcat(user_file,"_tickets.txt");//concatinating "_tickets.txt" to user_file
    
    

    char x[5],y[]="yes";
    printf("Do you wish to view your Booking History(yes/no)\n");
    scanf("%s",x);
//asking the user if he wishes to view booking history
    if(strcmp(x,y)==0) //comparing the input string
    {
        showbookinghistory(user_file);//function called to show booking history
    }
    printf("Do you wish to cancel any file ticket that you are yet to tarvel(yes/no)\n");
    scanf("%s",x);
//asking the user if he wants to cancel any ticket    
    if(strcmp(x,y)==0) //comparing the input string 
    {
    	cancelticket(user_file);//function called for cancelling ticket
	}

   
    return 0;
}
