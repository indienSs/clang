#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomize(int);

int main(void) {
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
        printf("random number is: %d\n", randomize(10));

    return 0;
}

int randomize(int max) {
    return rand() % max + 1;
}