#include<stdio.h>
#include "objects.h"

void main(){

    // Object 1
    Admin admin1 = {"123654","abcdef"};
    printf("Admin Id: %s\nAdmin Password: %s\n\n",admin1.id,admin1.password);

    // Object 2
    User user1 = {"fjkajk",
                "kjhkfjahk",
                "random",
                20,
                Male,
                "9966663322",
                "email@email.com"};
    printf("User Name: %s\n",user1.name);
    printf("User Id: %s\n",user1.id);
    printf("User Password: %s\n",user1.password);
    printf("User Age: %d\n",user1.age);
    printf("User Gender: %d\n",user1.gender);
    printf("User Phone NO.: %s\n",user1.phone_no);
    printf("User Email Id: %s\n",user1.email);

    enum Gender mygender = Others;
    printf("Here: %d\n",mygender);

    if (mygender==Others){
        printf("The gender is Others.\n");
    }

    // Object 3
    Passenger passenger1 = {"NoOne", 42, Adult};
    printf("Passanger Name: %s\n",passenger1.name);
    printf("Passanger Age: %d\n",passenger1.age);
    printf("Passanger Age Group: %d\n",passenger1.category);

    // Object 4

    float fare = 2000;

    Ticket ticket1 = {"Passenger1",
                        Adult,
                        "AM7171",
                        "Air India",
                        "Mohanpur",
                        "Kolkata",
                        "FW21",
                        "2 Feb 2021 15:00 hrs",
                        "2 Feb 2021 12:00 hrs",
                        fare,
                        "Yet to travel"};

    // Object 5
    Flight flight1 = {"Mohanpur",
                        "Kolkata",
                        "ZSH2148",
                        "Air India",
                        "15:00 hrs",
                        "12:00 hrs",
                        75,
                        10,
                        true};

}
