#include<string.h>
#include "../objects.h"
#include "../file.h"

void main(){


    Ticket tickets[5] = {{"Father",
                        Adult,
                        "KC1060",
                        "GoAir",
                        "Kolkata",
                        "Chennai",
                        "KC01",
                        "2 Feb 2021 15:00 hrs",
                        "2 Feb 2021 12:00 hrs",
                        fare,
                        "Yet to travel"},

                        {"Mother",
                        Adult,
                        "KC1060",
                        "GoAir",
                        "Kolkata",
                        "Chennai",
                        "KC02",
                        "2 Feb 2021 15:00 hrs",
                        "2 Feb 2021 12:00 hrs",
                        fare,
                        "Yet to travel"},

                        {"Son",
                        Infant,
                        "KC1060",
                        "GoAir",
                        "Kolkata",
                        "Chennai",
                        "KC03",
                        "2 Feb 2021 15:00 hrs",
                        "2 Feb 2021 12:00 hrs",
                        fare,
                        "Yet to travel"},

                        {"Daughter",
                        Child,
                        "KC1060",
                        "GoAir",
                        "Kolkata",
                        "Chennai",
                        "KC04",
                        "2 Feb 2021 15:00 hrs",
                        "2 Feb 2021 12:00 hrs",
                        fare,
                        "Yet to travel"},

                        {"Grandpa",
                        Senior,
                        "KC1060",
                        "GoAir",
                        "Kolkata",
                        "Chennai",
                        "KC05",
                        "2 Feb 2021 15:00 hrs",
                        "2 Feb 2021 12:00 hrs",
                        fare,
                        "Yet to travel"}};

    char user_id[] = "demo_user";
    char user_file[50];
    strcpy(user_file,"../data/");
    strcat(user_file,user_id);
    strcat(user_file,"_tickets.txt");
    writeFile(user_file, &tickets, sizeof(Ticket), 5);

}}
