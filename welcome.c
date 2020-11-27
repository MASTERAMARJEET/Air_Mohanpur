#include <stdio.h>
#include <string.h>
#include "objects.h"
#include "file.h"

void user_login(); //declaration; function defined in user.c

void admin_login(); //declaration; function defined in admin.c

void main()
{
printf("\n\t\t\t\t******************************************************************\t\t\n");
printf("\n\t\t\t\t******** W E L C O M E    T O    A I R    M O H A N P U R ********\t\t\n");
printf("\n\t\t\t\t******************************************************************\t\t\n");
printf("\n");

char access[3];
printf("\nWhat do you want to log in as? \n Enter 'Ad' for admin access or 'Us' for user access. \n PRESS 'ENTER' AFTER EVERY INPUT YOU GIVE. \n");
scanf("%2s", access);

if (strcmp(access,"Ad")==0)
{
	admin_login();
}

else if (strcmp(access,"Us")==0)
{
	user_login();
}

else 
{
	printf("\nPlease enter a valid choice from the two listed above.");
}
}