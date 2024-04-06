#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define string char*

int letters_counter(const string str);
int vowels_counter(const string str);

int main(void) {
    string example = "this is string";
    int total_letters = letters_counter(example);
    int total_vowels = vowels_counter(example);

    printf("total letters: %d\n", total_letters);
    printf("total vowels: %d\n", total_vowels);

    return 0;
}

int letters_counter(const string str) {
    return strlen(str);
}

int vowels_counter(const string str) {
    int counter = 0;
    for (int i = 0; i < strlen(str); i++) {
        switch (tolower(str[i])) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                counter++;
        }
    }
    return counter;
}
