#include<stdio.h>
#include<string.h>

void main(){

    size_t arrlen = 7, strlen = 10;
    char strings[10][7] = {"zpple","yea","xall","vool","uogg","tlle","satt"}, key[10];
    int i, j, k;

    // start of Insertion Sort
    for (i=1;i<arrlen;i++){
        strcpy(key,strings[i]);
        j = i - 1;

        while (j>=0 && strcmp(strings[j],key)>0){
            strcpy(strings[j+1],strings[j]);
            j = j - 1;
        }
        strcpy(strings[j+1],key);
    }
    // inserstion Sort finished

    for (int i = 0; i < 7; i++)
    {
        printf("%s ",strings[i]);
    }

}