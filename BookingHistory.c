#include<stdio.h>
#include<string.h>
#include<stdlib.h> //for exit()

void showbookinghistory(char destination[])
{
	FILE*fptr;
	char c,x[5],y[]="yes";
	printf("Do you wish to view your Booking History(yes/no)\n");
	scanf("%s",x);
	printf("%s %s",x,y);
	//open file
	if(strcmp(x,y)==0)
	{
		fptr = fopen(destination,"r");
		if(fptr == NULL)
		{
		printf("Cannot open file \n");
		exit(0);
		}
		//Read contents from file
		c = fgetc(fptr);
		while(c!= EOF)
		{
			printf("%c",c);
			c = fgetc(fptr);
		}
	}
	else
	{
		exit(0);
	}
	fclose(fptr);
	return;
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
	char source[] = "ticket.txt",
		destination[] = "BookingHistory.txt";

	// calling Function with file names.
	showbookinghistory(destination);
	appendFiles(source, destination);

	return 0;
}
