#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* buffers_create(int size) {
    int* buffer = malloc(sizeof(int) * size);

    int data = 0;
    int element_number = 0;

    // пример получения новых данных для записи в буфер через терминал
    while (true) {
        if (element_number == size) {
            size *= 2;
            buffer = realloc(buffer, sizeof(int) * size);
        }
        printf("Enter number (-1 to break): ");
        scanf("%d", &data);
        if (data == -1) break;
        else buffer[element_number] = data;
        element_number++;
    }
}