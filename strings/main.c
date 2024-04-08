#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define string char*

int vowels_counter(const string str);

typedef struct {
    int length;
    char *value;
} String;

void* new_string(const string);

int main(void) {
    string example = "this is string";
    int total_letters = strlen(example);
    int total_vowels = vowels_counter(example);

    printf("total letters: %d\n", total_letters);
    printf("total vowels: %d\n", total_vowels);

    String *strnew = (String *)new_string("this is new struct string");
    printf("string struct value: %s\n", strnew->value);

    free(strnew);

    return 0;
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

void to_upper_case(String *str) {
    for (int i = 0; i < str->length; i++) {
        str->value[i] = toupper(str->value[i]);
    }
}

void to_lower_case(String *str) {
    for (int i = 0; i < str->length; i++) {
        str->value[i] = tolower(str->value[i]);
    }
}

void* new_string(const string str) {
    String *strct = malloc(sizeof(int) + strlen(str));
    strcpy_s(strct->value, strlen(str), str);
    strct->length = strlen(str);

    return (void*)strct;
}