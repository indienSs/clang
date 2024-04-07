#include <stdio.h>
#include <stdlib.h>

void reverse_array(int *arr, size_t length);
void print_array(int *arr, size_t length);

int main(void) {
    int arr[] = {0, 1, 2, 3, 4, 5};
    size_t length = sizeof(arr) / sizeof(int);

    printf("array length: %zu\n", length);
    print_array(arr, length);
    reverse_array(arr, length);
    print_array(arr, length);

    return 0;
}

void reverse_array(int *arr, size_t length) {
    for (int i = 0; i < length / 2; i++) {
        int tmp = arr[i];
        arr[i] = arr[length - i - 1];
        arr[length - i - 1] = tmp;
    }
}

void print_array(int *arr, size_t length) {
    for (int i = 0; i < length; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}