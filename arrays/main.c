#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void array_reverse(int*, size_t);
void array_print(int*, size_t);
int* array_copy(int*, size_t);
int array_intersection_index(int*, int, int*, int);
int* array_merge_sorted(int*, int, int*, int);
int array_count_uniq(int*, int);
void array_sort_strings(char**, int length, int order);

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

int* array_merge_sorted(int* first, int first_length, int* second, int second_length) {
    int shortest_length = first_length > second_length ? second_length : first_length;
    int biggest_length = first_length < second_length ? second_length : first_length;
    int* biggest_array = first_length < second_length ? second : first;
    int* result = malloc(sizeof(int) * (first_length + second_length));

    for (int i = 0; i < shortest_length; i++) {
        int insert_index = i*2;
        if (first[i] < second[i]) {
            result[insert_index] = first[i];
            result[insert_index+1] = second[i];
        } else {
            result[insert_index+1] = first[i];
            result[insert_index] = second[i];
        }
    }

    for (int i = shortest_length; i < biggest_length; i++)
        result[i*2] = biggest_array[i];

    return result;
}

int array_count_uniq(int* arr, int length) {
    int uniq_counter = 0;
    int j;

    for (int i = 0; i < length; ++i) {
        for (j = 0; j < length; ++j) 
            if (arr[i] == arr[j] && i != j) 
                break;
        
        if (j == length) uniq_counter++;
    }
    
    return uniq_counter;
}

void array_sort_strings(char** strs, int length, int order) {
    char temp[128] = "";
    for (int i = 0; i < length - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < length; ++j) 
            if (strcmp(strs[j], strs[min]) < 0)
                min = j;
        if (min != i) {
            strcpy(temp, strs[i]);
            strcpy(strs[i], strs[min]);
            strcpy(strs[min], temp);
        }
    }
}