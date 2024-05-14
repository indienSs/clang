#include <stdio.h>
#include <stdlib.h>

void array_reverse(int*, size_t);
void array_print(int*, size_t);
int* array_copy(int*, size_t);
int array_intersection_index(int*, int, int*, int);

int main(void) {
    int arr[] = {0, 1, 2, 3, 4, 5};
    size_t length = sizeof(arr) / sizeof(int);

    printf("array length: %zu\n", length);
    print_array(arr, length);
    reverse_array(arr, length);
    print_array(arr, length);

    return 0;
}

void array_reverse(int *arr, size_t length) {
    for (int i = 0; i < length / 2; i++) {
        int tmp = arr[i];
        arr[i] = arr[length - i - 1];
        arr[length - i - 1] = tmp;
    }
}

void array_print(int *arr, size_t length) {
    for (int i = 0; i < length; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

void* array_copy(int *arr, size_t length) {
    int* copy_arr = malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++) 
        copy_arr[i] = arr[i];
    
    return copy_arr;
}

int array_intersection_index(int* first, int first_length, int* second, int second_length) {
    int iteration_length = first_length > second_length ? second_length : first_length;

    for (int i = 0; i < iteration_length; ++i)
        if (first[i] == second[i]) 
            return i;
        
    return -1;
}