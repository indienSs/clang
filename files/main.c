#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_BUFFER_SIZE 1024

char* files_read_file(char*);

int main(void) {
    return 0;
}

char* files_read_file(char* path) {
    FILE *fb;
    int buffer_size = DEFAULT_BUFFER_SIZE;
    char *buffer = NULL;

    fb = fopen(path, "r");
    if (fb == NULL) return buffer;
    buffer = malloc(sizeof(char) * buffer_size);
    int i = 0;
    while ((buffer[i] = fgetc(fb)) != EOF) {
        ++i;
        if (i == buffer_size) {
            buffer_size *= 2;
            buffer = realloc(buffer, sizeof(char) * buffer_size);
        }
    }
    fclose(fb);
    return buffer;
}