#ifndef OBJECTS_H
#define OBJECTS_H

#include<time.h>
#include<stdbool.h>

/* enum for Gender:
    - [0] Male
    - [1] Female
    - [2] Others
*/
typedef enum Gender {Male, Female, Others};

/* enum for Age Group of Passanger:
    - [0] Infant
    - [1] Child
    - [2] Adult
    - [3] Senior
*/
typedef enum AgeGrp {Infant, Child, Adult, Senior};

/* (Custom) Data Type for Admins.
    Fields (**Mind the size for strings**):
    > char id[20];
    > char password[20];
*/
typedef struct
{
    char id[21];
    char password[21];
}Admin;

/* (Custom) Data Type for Users.
    Fields (**Mind the size for strings**):
    > char name[50];
    > char id[20];
    > char password[20];
    > int age;
    > enum Gender gender;
    > char phone_no[15];
    > char email[50];

*/
typedef struct
{
    char name[51];
    char id[21];
    char password[21];
    int age;
    enum Gender gender;
    char phone_no[16];
    char email[51];
}User;

/* (Custom) Data Type for Passanger info.
    Fields (**Mind the size for strings**):
    > char name[50];
    > int age;
    > enum AgeGrp category;
*/
typedef struct
{
    char name[51];
    int age;
    enum AgeGrp category;
}Passenger;

/* (Custom) Data Type for Ticket details.
    Fields (**Mind the size for strings**):
    > char psngr_name[50];
    > enum AgeGrp psngr_category;
    > char flight_no[10];
    > char airline_name[20];
    > char source[20];
    > char destination[20];
    > char seat_no[10];
    > struct tm arrive_time;
    > struct tm depart_time;
    > struct tm booking_time;
    > char status[16];
*/
typedef struct
{
    char psngr_name[51];
    enum AgeGrp psngr_category;
    char flight_no[11];
    char airline_name[21];
    char source[21];
    char destination[21];
    char seat_no[11];
    struct tm arrive_time;
    struct tm depart_time;
    struct tm booking_time;
    char status[15];
}Ticket;

/* (Custom) Data Type for Flight details.
    Fields (**Mind the size for strings**):
    > char source[20];
    > char destination[20];
    > char flight_no[15];
    > char airline_name[20];
    > struct tm arrive_time;
    > struct tm depart_time;
    > int total_seats;
    > int seats_available;
    > bool is_available;
*/
typedef struct
{
    char source[21];
    char destination[21];
    char flight_no[16];
    char airline_name[21];
    struct tm arrive_time;
    struct tm depart_time;
    int total_seats;
    int seats_available;
    bool is_available;
}Flight;

#endif // OBJECTS_H