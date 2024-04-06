#include <stdio.h>

int calculate_fib(int num);

int main(void) {
    
    int result = calculate_fib(10);

    printf("result: %d\n", result);

    return 0;
}

int calculate_fib(int num) {
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
