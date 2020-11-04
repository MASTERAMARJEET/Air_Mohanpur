#ifndef HEADER_FILE
#define HEADER_FILE

#include<time.h>
#include<stdbool.h>

typedef enum Gender {Male, Female, Others};

typedef enum AgeGrp {Infant, Child, Adult, Senior};

typedef struct
{
    char id[20];
    char password[20];
}Admin;

typedef struct
{
    char name[50];
    char id[20];
    char password[20];
    int age;
    enum Gender gender;
    char phone_no[15];
    char email[50];
}User;

typedef struct
{
    char name[50];
    int age;
    enum AgeGrp category;
}Passenger;

typedef struct
{
    char psngr_name[50];
    enum AgeGrp psngr_category;
    char flight_no[10];
    char airline_name[20];
    char source[20];
    char destination[20];
    char seat_no[10];
    struct tm arrive_time;
    struct tm depart_time;
    struct tm booking_time;
    char status[15];
}Ticket;

typedef struct
{
    char source[20];
    char destination[20];
    char flight_no[15];
    char airline_name[20];
    struct tm arrive_time;
    struct tm depart_time;
    int total_seats;
    int seats_available;
    bool is_available;
}Flight;

#endif