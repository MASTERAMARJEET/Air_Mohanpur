#include<stdio.h>
#include "../objects.h"
#include "../file.h"

void main(){

    char flights_file[] = "../data/flight_list.txt";

    Flight flights[30] = {{"Kolkata","Delhi","KD1060","SpiceJet","16:00 hrs","13:00 hrs",2000,60,41,true},
                {"Kolkata","Mumbai","KM1060","GoAir","16:00 hrs","13:00 hrs",2000,60,23,true},
                {"Kolkata","Chennai","KC1060","GoAir","15:00 hrs","12:00 hrs",2000,60,52,true},
                {"Kolkata","Hyderabad","KH1060","SpiceJet","14:00 hrs","11:00 hrs",2000,60,15,true},
                {"Kolkata","Bangalore","KB1060","GoAir","11:00 hrs","8:00 hrs",2000,60,55,true},
                {"Delhi","Kolkata","DK1060","GoAir","15:00 hrs","12:00 hrs",2000,60,16,true},
                {"Delhi","Mumbai","DM1060","IndiGo","21:00 hrs","18:00 hrs",2000,60,23,true},
                {"Delhi","Chennai","DC1060","GoAir","7:00 hrs","4:00 hrs",2000,60,54,true},
                {"Delhi","Hyderabad","DH1060","GoAir","16:00 hrs","13:00 hrs",2000,60,55,true},
                {"Delhi","Bangalore","DB1060","Air India","7:00 hrs","4:00 hrs",2000,60,12,true},
                {"Mumbai","Kolkata","MK1060","SpiceJet","15:00 hrs","12:00 hrs",2000,60,46,true},
                {"Mumbai","Delhi","MD1060","GoAir","11:00 hrs","8:00 hrs",2000,60,43,true},
                {"Mumbai","Chennai","MC1060","Air India","21:00 hrs","18:00 hrs",2000,60,49,true},
                {"Mumbai","Hyderabad","MH1060","IndiGo","17:00 hrs","14:00 hrs",2000,60,47,true},
                {"Mumbai","Bangalore","MB1060","IndiGo","14:00 hrs","11:00 hrs",2000,60,57,true},
                {"Chennai","Kolkata","CK1060","Air India","12:00 hrs","9:00 hrs",2000,60,46,true},
                {"Chennai","Delhi","CD1060","GoAir","20:00 hrs","17:00 hrs",2000,60,56,true},
                {"Chennai","Mumbai","CM1060","IndiGo","12:00 hrs","9:00 hrs",2000,60,40,true},
                {"Chennai","Hyderabad","CH1060","SpiceJet","11:00 hrs","8:00 hrs",2000,60,26,true},
                {"Chennai","Bangalore","CB1060","Air India","9:00 hrs","6:00 hrs",2000,60,59,true},
                {"Hyderabad","Kolkata","HK1060","SpiceJet","16:00 hrs","13:00 hrs",2000,60,32,true},
                {"Hyderabad","Delhi","HD1060","IndiGo","20:00 hrs","17:00 hrs",2000,60,16,true},
                {"Hyderabad","Mumbai","HM1060","Air India","21:00 hrs","18:00 hrs",2000,60,36,true},
                {"Hyderabad","Chennai","HC1060","Air India","9:00 hrs","6:00 hrs",2000,60,49,true},
                {"Hyderabad","Bangalore","HB1060","Air India","9:00 hrs","6:00 hrs",2000,60,48,true},
                {"Bangalore","Kolkata","BK1060","Air India","17:00 hrs","14:00 hrs",2000,60,20,true},
                {"Bangalore","Delhi","BD1060","Air India","21:00 hrs","18:00 hrs",2000,60,47,true},
                {"Bangalore","Mumbai","BM1060","SpiceJet","11:00 hrs","8:00 hrs",2000,60,55,true},
                {"Bangalore","Chennai","BC1060","SpiceJet","12:00 hrs","9:00 hrs",2000,60,14,true},
                {"Bangalore","Hyderabad","BH1060","Air India","14:00 hrs","11:00 hrs",2000,60,53,true}};

    writeFile(flights_file, &flights, sizeof(Flight), 30);

}