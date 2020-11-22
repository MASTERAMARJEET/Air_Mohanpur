#include<stdio.h>

/* Write array data to a file.

    Parameters(in order):
    - file_name - name of file to which data to be wrtitten
    - data_ptr - pointer (starting address) of array whose data to be written
    - data_size - size of each element in the array
    - elem_num - number of elements of array to be written
*/
void writeFile(char *file_name, void* data_ptr, int data_size, int elem_num){

    FILE *fptr;
    fptr = fopen(file_name,"w");

    if (fptr == NULL)
    {
        printf("Couldn't open file: %s\n",file_name);
        return;
    }

    fwrite(data_ptr,data_size,elem_num,fptr);

    fclose(fptr);

}

/* Append array data to a file.

    Parameters(in order):
    - file_name - name of file to which data to be wrtitten
    - data_ptr - pointer (starting address) of array whose data to be written
    - data_size - size of each element in the array
    - elem_num - number of elements of array to be written
*/
void appendFile(char *file_name, void* data_ptr, int data_size, int elem_num){

    FILE *fptr;
    fptr = fopen(file_name,"a");

    if (fptr == NULL)
    {
        printf("Couldn't open file: %s\n",file_name);
        return;
    }

    fwrite(data_ptr,data_size,elem_num,fptr);

    fclose(fptr);

}

/* Read data from a file to array.

    Parameters(in order):
    - file_name - name of file from which data to be read
    - data_ptr - pointer (starting address) of array which will store the data
    - data_size - size of each element in the array
    - elem_num - number of elements to be read from array

    Returns: (**int**) number of elements sucessfully read.
*/
int readFile(char *file_name, void* data_ptr, int data_size, int elem_num){

    FILE *fptr;
    fptr = fopen(file_name,"r");

    if (fptr == NULL)
    {
        printf("Couldn't open file: %s\n",file_name);
        return 0;
    }

    int elem_count=0;

    while (!feof(fptr) && elem_count<elem_num)
    {
        fread(data_ptr+((elem_count)*data_size),data_size,1,fptr);
        elem_count++;
    }

    fclose(fptr);

    return elem_count - 1;
}
