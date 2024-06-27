#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define string char*

int number_randomize(int);
int number_binary_to_decimal(string);

int main(void) {
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
        printf("random number is: %d\n", number_randomize(10));

    return 0;
}

int number_randomize(int max) {
    return rand() % max + 1;
}

int number_binary_to_decimal(string str) {
    size_t length = strlen(str);
    int result = 0;
    int period = 1;
    
    for (int i = length - 1; i >= 0; --i, period *= 2) 
        if (str[i] == "1")
            result += period;

    return result;
}