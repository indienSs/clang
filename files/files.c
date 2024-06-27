#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_BUFFER_SIZE 1024
#define DEFAULT_STRING_LENGTH 128

char* files_read_file(char* path);
void files_append(char* path, char* data);
void files_copy(char* path);

int main(void) {
    return 0;
}

char* files_read_file(char* path) {
    FILE *file;
    int buffer_size = DEFAULT_BUFFER_SIZE;
    char *buffer = NULL;

    file = fopen(path, "r");
    if (file == NULL) return buffer;
    buffer = malloc(sizeof(char) * buffer_size);
    int i = 0;
    while ((buffer[i] = fgetc(file)) != EOF) {
        ++i;
        if (i == buffer_size) {
            buffer_size *= 2;
            buffer = realloc(buffer, sizeof(char) * buffer_size);
        }
    }
    fclose(file);
    return buffer;
}

void files_append(char* path, char* data) {
    FILE* file;
    file = fopen(path, "a");
    
    if (file == NULL) return;
    fputs(data, file);
    fclose(file);
}

void files_copy(char* path) {
    FILE *file, *copy;
    size_t path_name_length = strlen(path);
    char file_name[DEFAULT_STRING_LENGTH] = "";
    strcpy(file_name, path);
    strcat(file_name, "_copy");

    file = fopen(path, "r");
    copy = fopen(file_name, "w");

    if (file == NULL || copy == NULL) return;

    char c;
    while ((c = fgetc(file)) != EOF) 
        fputc(c, copy);
    
    fclose(file);
    fclose(copy);
}