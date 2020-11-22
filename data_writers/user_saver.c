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

    User existing_users[10] = {{"Madhav","Madhav2020Mohan","Mohan*30*20",28,Male,"9474550316","madhav_mohan@gmail.com"},
                {"Aparna","AparnaMukherjee","utsav5060",25,Female,"9004555516","mukherjee.aparna@gmail.com"},
                {"Nico","Nico_DSouza","57#DSouza*57",45,Others,"9463487616","madhav_mohan@yahoo.com"},
                {"Vidyasagar","Vidya30303030","Sagar#qwerty",75,Male,"9486320376","vidyasagar@iiserkalyani.com"},
                {"Divyalakshmi","Divya_Rathode","drlakshmi",18,Female,"9008888316","dr.lakshmi@gmail.com"},
                {"Irfan","MuhammadIrfan99","Irfan70*30",26,Male,"9474558558","irfan.muhammad@rediffmail.com"},
                {"Kanjee","Kanjee1970Lalit","1970#LalitK",54,Male,"94748805356","Lalit17Kanjee@hotmail.com"},
                {"Misaal","MisaalPratapMohan","Misaal*78#25",40,Others,"9333507786","Pratap.Mohan@gmail.com"},
                {"Tenzing","Tenzingbendong","I*Love*India",54,Male,"9474640354","Bendong.India@tango.com"},
                {"Pratap","Shreeprataprathore","PrTaProcks3030",37,Male,"9008360318","Shreeprataprathore@niftr.com"}};

    writeFile(users_file, &existing_users, sizeof(User), 10);

}