#include <stdio.h>
#include <stdlib.h>

char* files_read_file(char*);

int main(void) {
    return 0;
}

char* files_read_file(char* path) {
    FILE *fb;
    int buffer_size = 256;
    char *buffer = malloc(sizeof(char) * buffer_size);

    fb = fopen(path, "r");
    if (fb == NULL) return buffer;
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