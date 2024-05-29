#include <stdbool.h>
#include <stdio.h>

void algorithhm_bubble_sort(int*, int);
void algorithm_insertion_sort(int*, int);
int algorithm_binary_search(int*, int, int);
int algorithm_fibonacci(int);

int main(void) {
    int arr[] = {0, 3, 1, 5, 6, 4, 2};

    algorithm_insertion_sort(arr, 7);
    // algorithhm_bubble_sort(arr, 7);
    for (int i = 0; i < 7; ++i)
        printf("%d", arr[i]);

    int idx = algorithm_binary_search(arr, 7, 5);
    printf("\n%d", idx);
    
    return 0;
}

void algorithhm_bubble_sort(int* arr, int length) {
    bool swapped = false;
    do {
        swapped = false;
        for (int i = 0; i < length - 1; ++i) {
            if (arr[i] > arr[i+1]) {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                swapped = true;
            }
        }
    } while (swapped);
}

void algorithm_insertion_sort(int* arr, int length) {
    for (int i = 1; i < length; ++i) {
        int num = arr[i];
        int comp = i - 1;
        while (comp >= 0 && arr[comp] > num) {
            arr[comp+1] = arr[comp];
            comp -= 1;
        }
        arr[comp+1] = num;
    }
}

int algorithm_fibonacci(int num) {
    if (num <= 1) return 0;
    if (num == 2) return 1;
    
    int first = 0;
    int second = 1;

    for (int i = 0; i < num - 2; i++) {
        int tmp = second;
        second += first;
        first = tmp;
    }

    return second;
}

int algorithm_binary_search(int* arr, int length, int element) {
    int left = 0;
    int right = length - 1;
    int middle;
    while (left <= right) {
        middle = (left + right) / 2;
        if (arr[middle] == element) return middle;
        else if (arr[middle] < element) left = middle + 1;
        else right = middle;
    }
    return -1;
}