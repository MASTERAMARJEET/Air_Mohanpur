#ifndef FILE_H
#define FILE_H
// The functions declared here are defined in file.c

void writeFile(char *file_name, void* data_ptr, int data_size, int elem_num);

void appendFile(char *file_name, void* data_ptr, int data_size, int elem_num);

int readFile(char *file_name, void* data_ptr, int data_size, int elem_num);

#endif // FILE_H