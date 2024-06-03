#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_BUFFER_SIZE 1024

char* files_read_file(char*);
void files_append(char* path, char* data);

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