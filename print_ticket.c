#include<stdio.h>
#include "objects.h"
#include<string.h>
#include<math.h>



//This function will classify the passenger into an age group based, of course, on their present age.
int age_grp(int age)
{
    int age_group;

    if(age<2)
        age_group = Infant;
    else if(2<=age<18)
        age_group = Child;
    else
        age_group = Adult;

    return age_group;
}


//This function is to calculate the fare for the flight based on the age group of the passener and the distance to be travelled.
float kitna_paisa(int Age_grp, int dist)
{
    int price;

    //This part decides the price based on the distance travelled.
    if(dist<=1000)
        price = 3*dist;  //The price is 3.0 INR for the first 1000 kms
    else if(1000<dist<=2000)
        price = 3*1000 + 2.5*(dist-1000);   //For the next 1000 kms the rate is 2.5 INR
    else if(2000<=dist<=4000)
        price = 3*1000 + 2.5*1000 + 2*(dist-2000); //For the next 2000 kms the rate is 2.0 INR.
    else
        price = 3*1000 + 2.5*1000 + 2*2000 + 1.5*(dist-4000);  //For the rest of the journey, the price is 1.5 INR. 
        

    switch(Age_grp)
    {
    case 0: return 0;   //We're not charging any price for an infant as they will be carried in the lap by their parents,
        break;  
    case 1: return 0.8*price;  //The price for children has been kept 0.8 times the price that an adult will be charged.
        break;
    case 2: return price;
    }
}


void ticket_saver(User user1, Flight flt1, char date[])
{
    /*This will follow after the user has searched and chosen his flight of interest (flight no., source and destination etc.) 
    and now giving the passenger details.*/

/*I've user the details (usr1.id etc.) and flight chosen(flt1).
I need to print and save the ticket details like departure and arrival time along with the date of
journey.  


    char psngr_name[51];         (I've to ask this.)
    enum AgeGrp psngr_category;  (I will ask the age of the passenger and classify him as infant/child etc.)
    char flight_no[11];             (This is from flt1)
    char airline_name[21];          (This is from flt1)
    char source[21];                (This is from flt1)
    char destination[21];           (This is from flt1)
    char seat_no[11];              (Still to be thought.)
    char arrive_time[51];           (This is from flt1)
    char depart_time[51];           (This is from flt1)
    float fare;                     (Have to write a function acc to age grp and distance of the journey)
    char status[15];                (Booked. Yet to travel.)*/
    

    if(flt1.seats_available>=1)
   {

        Ticket new_ticket;
        char p_name[50],status[15];
        int p_age,Age_grp;
        float fare,price;

        printf("Kindly enter the name of the passenger:\t");
        scanf("%s",new_ticket.psngr_name);

        printf("\nKindly enter the age of the passenger:\t");
        scanf("%d",&p_age);

        printf("\nYou've successfully saved the details of the passengers.\n");
        printf('The ticket details are:\n');

        printf("a) Passenger details:\n\n");
        printf("Name of the passenger:\t%s\n",new_ticket.psngr_name);
        printf("Age of the passenger:\t%d\n",p_age);


        //This part will classify the passenger into one of the age group based, of course, on their present age.
        if(p_age<2)
        {
            new_ticket.psngr_category = Infant;
            printf("Age group of the passenger:\tInfant\n");
        }
        else if(2<=p_age<18)
        {
            new_ticket.psngr_category = Child;
            printf("Age group of the passenger:\tChild\n");
        }
        else
        {
            new_ticket.psngr_category = Adult;
            printf("Age group of the passenger:\tAdult\n");
        }

        strcpy(new_ticket.flight_no,flt1.flight_no);
        strcpy(new_ticket.airline_name,flt1.airline_name);
        strcpy(new_ticket.source,flt1.source);
        strcpy(new_ticket.destination,flt1.destination);
        /*The seat no's first char is the first letter of the source, the second char is the first letter of the destination and the
        following no is the seat no of the plane that will be alloted to the passenger.*/
        sprintf(new_ticket.seat_no,"%c%c%d",flt1.flight_no[0],flt1.flight_no[1],flt1.total_seats+1-flt1.seats_available);
        strcpy(new_ticket.depart_time,flt1.depart_time);
        strcpy(new_ticket.arrive_time,flt1.arrive_time);
        new_ticket.fare = kitna_paisa(new_ticket.psngr_category,flt1.distance);
        
        printf("b) Flight details:\n\n");
        printf("Airline name and flight no.:\t%s,%%s\t\n",flt1.airline_name,new_ticket.flight_no);
        printf("Boarding station:\t%s\n",new_ticket.source);
        printf("Destination:\t%s\n",flt1.destination);
        printf("Seat no.:\t%s\n",new_ticket.seat_no);
        flt1.seats_available-- ;
        printf("Date of journey:\t%s\n",date);
        printf("Departure time:\t%s\n",flt1.depart_time);
        printf("Arrival time:\t%s\n",flt1.arrive_time);

        printf("The final ticket price is =\tINR  %f\n",new_ticket.fare);
        char status = "Ticket booked. Yet to travel.";
   }
   else
   {
       printf("Sorry! There's no seat available on this flight.\nLook for another flight which may carry you to your destination.\n");
   }
}


void main()
{
    User abc = {"fjkajk",
                "kjhkfjahk",
                "random",
                20,
                Male,
                "9966663322",
                "email@email.com"};

    Flight flt1 = {"Chennai","Kolkata","CK1060","Air India","12:00 hrs","9:00 hrs",60,46,true};
    char date[] = "22 Nov 2020";
    ticket_saver(abc,flt1, date);
   
}
