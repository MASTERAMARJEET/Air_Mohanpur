#include<stdio.h>
#include<string.h>

void main()
{

    size_t arrlen = 7, strlen = 10;
    char strings[10][7] = {"zpple","yea","xall","vool","uogg","tlle","satt"}, key[10];
    int i, j;

    // start of Insertion Sort
    for (i=1;i<arrlen;i++)
    {
        strcpy(key,strings[i]);
        j = i - 1;

        while (j>=0 && strcmp(strings[j],key)>0)
        {
            strcpy(strings[j+1],strings[j]);
            j = j - 1;
        }
        strcpy(strings[j+1],key);
    }
    // inserstion Sort finished

    for  (i = 0; i < 7; i++)
    {
        printf("%s ",strings[i]);
    }

    // binary search sequence started
    // Returns index of x if it is present in arr[], 
    // else return -1 
    char search_string = "tlle";
    { 
        int l = 0; 
        int r = arrlen - 1; 
        while (l <= r)  
        { 
            int m = l + (r - l) / 2; 
  
        int res; 
        if (strcmp(search_string,strings[m])==0) 
            // Check if x is present at mid 
            printf("The search string %s",strings[m]," was found at %d",m+1,"th position."); 
            
            // If x greater, ignore left half 
            if (strcmp(search_string,strings[m])>0) 
                l = m + 1; 
  
            // If x is smaller, ignore right half 
            else
                r = m - 1; 
        } 
  
         
    } 
}
