#include<string.h>
#include "../objects.h"
#include "../file.h"

void main(){

    float fare=1500;

    Ticket tickets[3] = {{"Reetika", Adult, "MK1060","SpiceJet", "Mumbai", "Kolkata", "MK08","21 Dec 2020 15:00 hrs", "21 Dec 2021 12:00 hrs", fare, "Yet to travel"},
                        {"Vidya", Adult, "DB1060","Air India", "Delhi", "Bangalore", "DB01","6 Feb 2021 7:00 hrs", "6 Feb 2021 4:00 hrs", fare, "Yet to travel"},
                        {"Rahul", Adult, "MB1060","IndiGo","Mumbai","Bangalore","MB05","8 Feb 2021 14:00 hrs","8 Feb 2021 11:00 hrs",fare,"Yet to travel"}};

    char user_id[] = "Tenzingbendong";
    char user_file[50];
    strcpy(user_file,"../data/");
    strcat(user_file,user_id);
    strcat(user_file,"_tickets.txt");
    writeFile(user_file, &tickets, sizeof(Ticket), 3);

}
