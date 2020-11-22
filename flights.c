#include <stdio.h>
#include <string.h>
#include "objects.h"
#include "file.h"


/*
This function checks if a given string is contained in the other or not.

Returns 1 is it does and 0 if it doesn't.
*/
int contains_str(char string[], char pattern[]){

    int str_len, ptrn_len,i,j,key;
    str_len = strlen(string);
    ptrn_len = strlen(pattern);


    if (ptrn_len>str_len)
        return 0;

    for (i=0;i<str_len-ptrn_len+1;i++){
        key=1;
        for (j=0;j<ptrn_len;j++){
            if (pattern[j]!=string[j+i]){
                key=0;
                break;
            }
            if (j==ptrn_len-1){
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
*/
void select_date(char date[]){

    char month[5];
    int day;

    printf("You need to select the date of travel.\n");
    get_month:
    printf("At the moment you can book ticket for the months of Dec 2020, Jan 2021 and Feb 2021\n");
    printf("Enter month name(one of Dec, Jan or Feb): ");
    scanf("%4s",month);

    if (strcmp(month,"Dec")==0){
        dec_day:
        printf("Enter the day of travel(between 1 to 31): ");
        scanf("%d",&day);
        if (day<1 || day>31){
            goto dec_day;
        }
        sprintf(date,"%d %s 2020",day,month);
    }
    else if (strcmp(month,"Jan")==0){
        jan_day:
        printf("Enter the day of travel(between 1 to 31): ");
        scanf("%d",&day);
        if (day<1 || day>31){
            goto jan_day;
        }
        sprintf(date,"%d %s 2021",day,month);
    }
    else if (strcmp(month,"Feb")==0){
        feb_day:
        printf("Enter the day of travel(between 1 to 28): ");
        scanf("%d",&day);
        if (day<1 || day>28){
            goto feb_day;
        }
        sprintf(date,"%d %s 2021",day,month);
    }
    else{
        printf("\nInvalid month! Try again!!");
        goto get_month;
    }

}

void search_flight(User user){

    char flight_list_file[] = "data/flight_list.txt", prompt;
    char date[25];
    char airport_list[15][20], src_choice[20], dest_choice[20];
    Flight flights[100], filtered[100];
    int i, j, flight_num, filter_num, counter=0, key, flight_choice;

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

    for (i=0; i<counter; i++){
        printf("%d. %s\n",i+1,airport_list[i]);
    }

    select_date(date);

    choose_src:
    printf("\nNow, you need to enter the airport name(or part of name) for boarding and destination\n");
    printf("Enter the boarding airport: ");
    scanf("%s", src_choice);

    printf("\nEnter the destination airport: ");
    scanf("%s", dest_choice);

    for (i=0;i<flight_num;i++){
        if (contains_str(flights[i].source,src_choice)==1 &&
            contains_str(flights[i].destination,dest_choice)==1 &&
            flights[i].seats_available>0){
            filtered[filter_num]=flights[i];
            filter_num++;
        }
    }

    if (filter_num==0){
        printf("\n\tSORRY.\nThe flight for your desired choice are unavailabe.\n");
        printf("If you want to retry with different input press R(otherwise press any other key): ");
        scanf("\n%c",&prompt);
        if (prompt=='R')
            goto choose_src;
    }
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

        // ticket_saver(user,filtered[flight_choice]);
    }

}