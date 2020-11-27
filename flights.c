#include <stdio.h>
#include <string.h>
#include "objects.h"
#include "file.h"

int ticket_saver(User user1, Flight flt1, char date[]);

/*
This function checks if a given string is contained in the other or not.

Input:
string - main string;
pattern - the sub string that is to expected to be contained in the main string.

Returns 1 if substring is contained in main string and 0 if it doesn't.
*/
int contains_str(char string[], char pattern[]){

    int str_len, ptrn_len;
    int i, j;   // i and j are used in for loop.
    int key;    //  Key is used as a switch which is 1 when substring is contained in main string
    str_len = strlen(string);
    ptrn_len = strlen(pattern);

    //returns zero as larger substring cannot be contained in the smaller main string
    if (ptrn_len>str_len)
        return 0;

    // these two nested loops matches each charater in the substring and the main
    // string and returns key as soon as all the characters of substring are there in substring
    for (i=0;i<str_len-ptrn_len+1;i++){
        key=1;
        for (j=0;j<ptrn_len;j++){
            if (pattern[j]!=string[j+i]){
                key=0;
                break;
            }
            if (j==ptrn_len-1){
                // j becomes only ptrn_len-1 when sub string is contained in the string
                // at which point the control will jump to return statement and return 1
                goto end;
            }
        }
    }

    end:
    return key;

}

/*
This function ask for user to select a date of travel and fills the response in an 'date' string
that is passed to the function.

Input:
date - an empty string that will be filled at the end with the date the user chooses
*/
void select_date(char date[]){

    char month[5];
    int day;

    printf("You need to select the date of travel.\n");
    get_month: //label to be used to ask user to enetr the month again in case it is not Dec, Jan or Feb
    printf("At the moment you can book ticket for the months of Dec 2020, Jan 2021 and Feb 2021\n");
    printf("Enter month name(one of Dec, Jan or Feb): ");
    scanf("%4s",month);

    // Different months have different number of days hence using if condition to take day input
    if (strcmp(month,"Dec")==0){
        dec_day: //label used to ask user to enter the proper date
        printf("Enter the day of travel(between 1 to 31): ");
        scanf("%d",&day);

        //checks if the date is invalid and asks the user to enter the date again
        if (day<1 || day>31){
            goto dec_day;
        }
    }

    else if (strcmp(month,"Jan")==0){
        jan_day: //label used to ask user to enter the proper date
        printf("Enter the day of travel(between 1 to 31): ");
        scanf("%d",&day);

        //checks if the date is invalid and asks the user to enter the date again
        if (day<1 || day>31){
            goto jan_day;
        }
    }

    else if (strcmp(month,"Feb")==0){
        feb_day: //label used to ask user to enter the proper date
        printf("Enter the day of travel(between 1 to 28): ");
        scanf("%d",&day);

        //checks if the date is invalid and asks the user to enter the date again
        if (day<1 || day>28){
            goto feb_day;
        }
    }
    else{
        printf("\nInvalid month! Try again!!");
        goto get_month;
    }

    sprintf(date,"%d %s 2021",day,month);  // storing the user input in formatted way in date variable
}

/* this function is used to search the flights available(from flight_list.txt) from the
source and destination entered by the user and display them to the user to go ahead with 
the booking of the flight. */

void search_flight(User user){

    // storing the path of file where flight list is available
    char flight_list_file[] = "data/flight_list.txt";

    char prompt, date[25];
    char airport_list[15][20], src_choice[20], dest_choice[20];
    Flight flights[100], filtered[100];
    int i, j, flight_num, filter_num, counter=0, key, flight_choice;
    int ticket_status;

    flight_num = readFile(flight_list_file,&flights,sizeof(Flight),100);

    printf("Welcome to the Air Mohanpur Flight Booking System.\n");
    printf("We provide flights to and from the following airports:\n");

    // This for loop collects the list of airport (mentioned as source) from the data in
    // flight_list.txt
    for (i=0;i<flight_num; i++){
        key=0;
        for (j=0;j<20;j++){
            if (strcmp(flights[i].source,airport_list[j])==0){
                key=1;
                break;
            }
        }
        if (key==0)
        {
            strcpy(airport_list[counter],flights[i].source);
            counter++;
        }
    }

    // This for loop collects the list of airport (mentioned as destination) from the data in
    // flight_list.txt
    for (i=0;i<flight_num; i++){
        key=0;
        for (j=0;j<20;j++){
            if (strcmp(flights[i].destination,airport_list[j])==0){
                key=1;
                break;
            }
        }
        if (key==0)
        {
            strcpy(airport_list[counter],flights[i].destination);
            counter++;
        }
    }

    //loop for printing the list for airports to and from where flight services are provided
    for (i=0; i<counter; i++){
        printf("%d. %s\n",i+1,airport_list[i]);
    }

    //Collect date from user and save it in string `data`.
    select_date(date);

    choose_src:
    printf("\nNow, you need to enter the airport name(or part of name) for boarding and destination\n");
    printf("Enter the boarding airport: ");
    scanf("%s", src_choice);

    printf("\nEnter the destination airport: ");
    scanf("%s", dest_choice);

    /*for loop for filtering out flights(with seats available) that match user choice*/
    for (i=0;i<flight_num;i++){
        if (contains_str(flights[i].source,src_choice)==1 &&
            contains_str(flights[i].destination,dest_choice)==1 &&
            flights[i].seats_available>0){
            filtered[filter_num]=flights[i];
            filter_num++;
        }
    }

    // If no flight match found, this part will run
    if (filter_num==0){
        printf("\n\tSORRY.\nThe flight for your desired choice are unavailabe.\n");
        printf("If you want to retry with different input press R(otherwise press any other key): ");
        scanf("\n%c",&prompt);
        if (prompt=='R')
            goto choose_src; //to try booking flight with another source or destination input
    }
    // if flight match found, this part will run
    else{
        printf("\n\nHere are the flights that match your search:\n\n");
        for ( i = 0; i < filter_num; i++)
        {
            printf("%d.\n",i+1);
            printf("Flight no.: %s\t",filtered[i].flight_no);
            printf("%s -> %s\n",filtered[i].source, filtered[i].destination);
            printf("Airline Name: %s\n",filtered[i].airline_name);
            printf("Departure time: %s \t Arrival time: %s\n\n",filtered[i].depart_time, filtered[i].arrive_time);
        }

        printf("Enter the Sl. No. of the flight shown that you want to book a ticket for: ");
        scanf("%d",&flight_choice);
        printf("Choice registered!\n");

        ticket_status = ticket_saver(user,filtered[flight_choice-1],date);
    }

}