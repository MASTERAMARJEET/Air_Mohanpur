#include<stdio.h>
#include "../objects.h"
#include "../file.h"

void main(){

    char flights_file[] = "../data/flight_list.txt";

    Flight flights[30] = {{"Kolkata","Delhi","KD1060","SpiceJet","16:00 hrs","13:00 hrs",1500,60,41},
                {"Kolkata","Mumbai","KM1060","GoAir","16:00 hrs","13:00 hrs",1970,60,23},
                {"Kolkata","Chennai","KC1060","GoAir","15:00 hrs","12:00 hrs",1750,60,52},
                {"Kolkata","Hyderabad","KH1060","SpiceJet","14:00 hrs","11:00 hrs",1510,60,15},
                {"Kolkata","Bangalore","KB1060","GoAir","11:00 hrs","8:00 hrs",1600,1620,55},
                {"Delhi","Kolkata","DK1060","GoAir","15:00 hrs","12:00 hrs",1500,60,16},
                {"Delhi","Mumbai","DM1060","IndiGo","21:00 hrs","18:00 hrs",1150,60,23},
                {"Delhi","Chennai","DC1060","GoAir","7:00 hrs","4:00 hrs",1800,60,54},
                {"Delhi","Hyderabad","DH1060","GoAir","16:00 hrs","13:00 hrs",1260,60,55},
                {"Delhi","Bangalore","DB1060","Air India","7:00 hrs","4:00 hrs",1800,60,12},
                {"Mumbai","Kolkata","MK1060","SpiceJet","15:00 hrs","12:00 hrs",1970,60,46},
                {"Mumbai","Delhi","MD1060","GoAir","11:00 hrs","8:00 hrs",1150,60,43},
                {"Mumbai","Chennai","MC1060","Air India","21:00 hrs","18:00 hrs",1000,60,49},
                {"Mumbai","Hyderabad","MH1060","IndiGo","17:00 hrs","14:00 hrs",625,60,47},
                {"Mumbai","Bangalore","MB1060","IndiGo","14:00 hrs","11:00 hrs",850,60,57},
                {"Chennai","Kolkata","CK1060","Air India","12:00 hrs","9:00 hrs",1750,60,46},
                {"Chennai","Delhi","CD1060","GoAir","20:00 hrs","17:00 hrs",1800,60,56},
                {"Chennai","Mumbai","CM1060","IndiGo","12:00 hrs","9:00 hrs",1000,60,40},
                {"Chennai","Hyderabad","CH1060","SpiceJet","11:00 hrs","8:00 hrs",520,60,26},
                {"Chennai","Bangalore","CB1060","Air India","9:00 hrs","6:00 hrs",300,60,59},
                {"Hyderabad","Kolkata","HK1060","SpiceJet","16:00 hrs","13:00 hrs",1510,60,32},
                {"Hyderabad","Delhi","HD1060","IndiGo","20:00 hrs","17:00 hrs",1260,60,16},
                {"Hyderabad","Mumbai","HM1060","Air India","21:00 hrs","18:00 hrs",625,60,36},
                {"Hyderabad","Chennai","HC1060","Air India","9:00 hrs","6:00 hrs",520,60,49},
                {"Hyderabad","Bangalore","HB1060","Air India","9:00 hrs","6:00 hrs",500,60,48},
                {"Bangalore","Kolkata","BK1060","Air India","17:00 hrs","14:00 hrs",1600,60,20},
                {"Bangalore","Delhi","BD1060","Air India","21:00 hrs","18:00 hrs",1800,60,47},
                {"Bangalore","Mumbai","BM1060","SpiceJet","11:00 hrs","8:00 hrs",850,60,55},
                {"Bangalore","Chennai","BC1060","SpiceJet","12:00 hrs","9:00 hrs",300,60,14},
                {"Bangalore","Hyderabad","BH1060","Air India","14:00 hrs","11:00 hrs",500,60,53}};

    writeFile(flights_file, &flights, sizeof(Flight), 30);

}