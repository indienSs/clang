void algorithhm_bubble_sort(int*, int);
int calculate_fib(int);

int main(void) {
    return 0;
}

void algorithhm_bubble_sort(int* arr, int length) {
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length - 1; ++j) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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