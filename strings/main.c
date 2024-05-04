#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define string char*

int vowels_counter(const string str);
bool string_includes(string str, string word);
void remove_letter(string str, char letter);

int main(void) {
    string example = "this is string";
    int total_letters = strlen(example);
    int total_vowels = vowels_counter(example);

    printf("total letters: %d\n", total_letters);
    printf("total vowels: %d\n", total_vowels);

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

bool string_includes(string str, string word) {
    int str_len = strlen(str);
    int word_len = strlen(word);
    int str_end = str_len - word_len + 1;
    bool includes = false;

    for (int i = 0; i < str_end; i++) {
        bool found = true;
        for (int j = 0; j < word_len; j++) {
            if (word[j] != str[i + j]) {
                found = false;
                break;
            }
        }
        if (found) {
            includes = true;
            break;
        }
    }

    return includes;
}

void remove_letter(string str, char letter) {
    int index = 0;

    while (str[index] != "\0") {
        if (str[index] == letter) {
            int shift_position = index;
            while (str[shift_position] != "\0") {
                str[shift_position] = str[shift_position++];
            }
        } else {
            ++index;
        }
    }
}
