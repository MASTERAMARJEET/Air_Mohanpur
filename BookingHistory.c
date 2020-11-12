#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "objects.h"
#include "file.h"

void showbookinghistory(char ticket_file[])
{
    int i=0, ticket_num;
    Ticket tickets[20];

    ticket_num = readFile(ticket_file,&tickets,sizeof(Ticket),20);

    printf("The tickets booked by you (%d in total) are listed below:\n", ticket_num);

    for (i=0;i<ticket_num;i++){
        printf("Ticket No.: %d\n",i+1);
        printf("Passanger Name: %s\n",tickets[i].psngr_name);
        printf("Source: %s; Destination: %s\n",tickets[i].source, tickets[i].destination);
        printf("Departure Time: %sArrival Time: %s",
            asctime(&tickets[i].depart_time),asctime(&tickets[i].arrive_time));
        printf("Status: %s\n\n",tickets[i].status);
    }
}

void appendFiles(char source[],char destination[])
{
    FILE *fp = fopen(source, "w");
    if (fp == NULL)
    {
        puts("Couldn't open file");
        exit(0);
    }
    else
    {
        fputs("12/12/20\t\tkolkata->Delhi\t\tindigo\t\t2\t\t10,563", fp);
        puts("Done");
        fclose(fp);
    }

    FILE *fp1, *fp2;

    // opening files
    fp1 = fopen(source, "a+");
    fp2 = fopen(destination, "a+");

    // If file is not found then return.
    if (!fp1 && !fp2)
    {
        printf("Unable to open/"
            "detect file(s)\n");
        return;
    }

    char buf[100];

    // explicitly writing "\n"
    // to the destination file
    // so to enhance readability.
    fprintf(fp2, "\n");

    // writing the contents of
    // source file to destination file.
    while (!feof(fp1))
    {
        fgets(buf, sizeof(buf), fp1);
        fprintf(fp2, "%s", buf);
    }

    rewind(fp2);

    // printing contents of
    // destination file to stdout.
    while (!feof(fp2))
    {
        fgets(buf, sizeof(buf), fp2);
        printf("%s", buf);
    }
}

// Driver Code
int main()
{
    char user_id[] = "demo_user";
    char user_file[50];
    strcpy(user_file,user_id);
    strcat(user_file,"_ticket.txt");

    char x[5],y[]="yes";
    printf("Do you wish to view your Booking History(yes/no)\n");
    scanf("%s",x);

    if(strcmp(x,y)==0)
    {
        showbookinghistory(user_file);
    }

    // calling Function with file names.
    // appendFiles(source, destination);

    return 0;
}
