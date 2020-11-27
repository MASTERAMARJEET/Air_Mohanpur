#include<stdio.h>
#include<string.h>
#include<math.h>
#include "objects.h"
#include "file.h"



//This function is to calculate the fare for the flight based on the age group of the passener and the distance to be travelled.
float kitna_paisa(int Age_grp, int dist)
{
    int price;

    //This part decides the price based on the distance travelled.
    if(dist<=500)
        price = 4*dist;  //The price is 4.0 INR for the first 500 kms
    else if(500<dist  &&  dist<=1000)
        price = 4*500 + 3*(dist-500);   //The price is 3.0 INR for the next 500 kms.
    else if(1000<dist  &&  dist<=2000)
        price = 4*500 + 3*500 + 2.5*(dist-1000);   //For the next 1000 kms the rate is 2.5 INR
    else if(2000<=dist  &&  dist<=4000)
        price = 4*500 + 3*500 + 2.5*1000 + 2*(dist-2000); //For the next 2000 kms the rate is 2.0 INR.
    else
        price = 4*500 + 3*500 + 2.5*1000 + 2*2000 + 1.5*(dist-4000);  //For the rest of the journey, the price is 1.5 INR. 
        

    switch(Age_grp)
    {
    case 0: return 0;   //We're not charging any price for an infant as they will be carried in the lap by their parents,
        break;  
    case 1: return 0.8*price;  //The price for children has been kept 0.8 times the price that an adult will be charged.
        break;
    case 2: return price;
    }
}

/*This will ask the details of the passenger from the user and generate the final amount and print the ticket on the terminal. 
It'll will also save the ticket in a text file on the system to keep as records.*/
int ticket_saver(User user1, Flight flt1, char date[])
{
    /*This will follow after the user has searched and chosen his flight of interest (flight no., source and destination etc.) 
    and now giving the passenger details.*/


    if(flt1.seats_available>=1)
    {

        Ticket new_ticket;
        char p_name[50], file_name[50];
        int p_age,Age_grp;
        float fare,price;

        printf("Kindly enter the name of the passenger:\t");
        scanf("%s",new_ticket.psngr_name);

        printf("Kindly enter the age of the passenger:\t");
        scanf("%d",&p_age);

        printf("\nYou've successfully booked the flight.\n\n");
        printf("The ticket details are:\n\n");




        /*Here we're copying all the flight and passenger details in the 'Ticket' struct. Using 'Ticket' we'll save the ticket of the
        passenger in a text file on the system.*/
        strcpy(new_ticket.flight_no,flt1.flight_no);
        strcpy(new_ticket.airline_name,flt1.airline_name);
        strcpy(new_ticket.source,flt1.source);
        strcpy(new_ticket.destination,flt1.destination);

        /*The seat no's first char is the first letter of the source, the second char is the first letter of the destination and the
        following no is the seat no of the plane that will be alloted to the passenger.*/
        sprintf(new_ticket.seat_no,"%c%c%d",flt1.flight_no[0],flt1.flight_no[1],flt1.total_seats+1-flt1.seats_available);
        sprintf(new_ticket.depart_time,"%s %s",date,flt1.depart_time);
        sprintf(new_ticket.arrive_time,"%s %s",date,flt1.arrive_time);
        
        strcpy(new_ticket.status,"Yet to travel");
        
        printf("a) Passenger details:\n\n");
        printf("Name of the passenger:\t\t\t%s\n",new_ticket.psngr_name);
        printf("Age of the passenger:\t\t\t%d\n\n",p_age);


        //This part will classify the passenger into one of the age group based, of course, on their present age.
        if(p_age<2)
        {
            new_ticket.psngr_category = Infant;
            printf("Age group of the passenger:\t\tInfant\n\n");
        }
        else if(2<=p_age && p_age<18)
        {
            new_ticket.psngr_category = Child;
            printf("Age group of the passenger:\t\tChild\n\n");
        }
        else
        {
            new_ticket.psngr_category = Adult;
            printf("Age group of the passenger:\t\tAdult\n\n");
        }

        new_ticket.fare = kitna_paisa(new_ticket.psngr_category,flt1.distance);

        printf("b) Flight details:\n\n");
        printf("Airline name and flight no.:\t\t%s, %s\t\n",flt1.airline_name,new_ticket.flight_no);
        printf("Boarding station:\t\t\t%s\n",new_ticket.source);
        printf("Destination:\t\t\t\t%s\n",flt1.destination);
        if (new_ticket.psngr_category != Infant){
            printf("Seat no.:\t\t\t\t%s\n",new_ticket.seat_no);
        }
        printf("Date of journey:\t\t\t%s\t\n",date);
        printf("Departure time:\t\t\t\t%s\n",flt1.depart_time);
        printf("Arrival time:\t\t\t\t%s\n",flt1.arrive_time);

        printf("The final ticket price is =\t\tINR  %f\n\n",new_ticket.fare);

        /*This function is generating the file name that will contain the saved ticket on the system.
        We're keeping the filename on the name of user's id as it is unique.  */
        sprintf(file_name,"data/%s_tickets.txt",user1.id);

        /*This function is finally appending the newly booked ticket details into the 'file_name' file 
        that will be generated through this function itself and will be stored on the system.*/
        appendFile(file_name,&new_ticket,sizeof(Ticket),1);

        if (new_ticket.psngr_category == Infant){
            return 0;
        }
        else
        {
            return 1;
        }
   
    }
    
    else
    {
        printf("Sorry! There's no seat available on this flight.\nLook for another flight which may carry you to your destination.\n");
        return 0;
    }


}

