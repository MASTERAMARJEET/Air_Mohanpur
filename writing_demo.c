#include<stdio.h>
#include "objects.h"
#include "file.h"

int main(){

    // defining new admins (via struct)
    Admin admins[2] = {{"123654","poiuytr"},{"987654321","abcdef"}};

    // defining empty array where we will read and save the data
    Admin buffer[10];
    
    //defining empty flight array 
	Flight flightname[10];

    printf("The size of the struct is: %lu\n",sizeof(Admin));

    // Saving the admins data to file (same data 10 times for example sake)
    int j;
    for (j=0;j<=9;j++){
        appendFile("Write.txt",&admins,sizeof(Admin),2);
    }

    // Reading it back from file into buffer.
    int num = readFile("Write.txt",&buffer,sizeof(Admin),4);
    printf("Total number of admins read from the file: %d\n",num);
    int i;
    for (i=0;i<=num-1;++i){
        printf("%d. Id: %s Password: %s\n",i+1,buffer[i].id,buffer[i].password);
    }

    return 0;
}
