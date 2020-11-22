#include<stdio.h>
#include "../objects.h"
#include "../file.h"

void main()
{

    char users_file[] = "../data/user_list.txt";

    char name[51];
    char id[21];
    char password[21];
    int age;
    enum Gender gender;
    char phone_no[16];
    char email[51];

    User existing_users[10] = {{"Aparna","AparnaMukherjee","utsav5060",25,Female,"9004555516","mukherjee.aparna@gmail.com"},
                {"Nico","Nico_DSouza","57#DSouza*57",45,Others,"9463487616","madhav_mohan@yahoo.com"},
                {"Irfan","MuhammadIrfan99","Irfan70*30",26,Male,"9474558558","irfan.muhammad@rediffmail.com"},
                {"Tenzing","Tenzingbendong","I*Love*India",54,Male,"9474640354","Bendong.India@tango.com"}};

    writeFile(users_file, &existing_users, sizeof(User), 10);

}