#include<string.h>
#include "objects.h"
#include "file.h"

void main(){
    float fare = 1500;
    time_t current_time = time(NULL);
    printf("%ld\n",current_time);   // time_t gives time since epoch

    struct tm now = *localtime(&(time_t){current_time});
    printf("The now is %s", asctime(&now));

    struct tm depart_time = now;
    depart_time.tm_mon += 3;
    mktime(&depart_time);
    printf("The depart time is %s", asctime(&depart_time));

    struct tm arrival_time = depart_time;
    arrival_time.tm_hour += 3;
    mktime(&arrival_time);
    printf("The arrival time is %s", asctime(&arrival_time));

    Ticket tickets[5] = {{"Father",
                        Adult,
                        "AM7171",
                        "Air India",
                        "Mohanpur",
                        "Kolkata",
                        "FW21",
                        depart_time,
                        arrival_time,
                        now,
                        fare,
                        "Yet to travel"},

                        {"Mother",
                        Adult,
                        "AM7171",
                        "Air India",
                        "Mohanpur",
                        "Kolkata",
                        "FW21",
                        depart_time,
                        arrival_time,
                        now,
                        fare,
                        "Yet to travel"},

                        {"Son",
                        Infant,
                        "AM7171",
                        "Air India",
                        "Mohanpur",
                        "Kolkata",
                        "FW21",
                        depart_time,
                        arrival_time,
                        now,
                        fare,
                        "Yet to travel"},

                        {"Daughter",
                        Child,
                        "AM7171",
                        "Air India",
                        "Mohanpur",
                        "Kolkata",
                        "FW21",
                        depart_time,
                        arrival_time,
                        now,
                        fare,
                        "Yet to travel"},

                        {"Grandpa",
                        Senior,
                        "AM7171",
                        "Air India",
                        "Mohanpur",
                        "Kolkata",
                        "FW21",
                        depart_time,
                        arrival_time,
                        now,
                        fare,
                        "Yet to travel"}};

    char user_id[] = "demo_user";
    char user_file[50];
    strcpy(user_file,user_id);
    strcat(user_file,"_ticket.txt");
    writeFile(user_file, &tickets, sizeof(Ticket), 5);

}