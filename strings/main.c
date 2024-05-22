#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define string char*

void string_switch_capitalize(string);
void string_remove_letter(string, char);
void string_trim_begin(string);
void string_trim_end(string);
void string_replace_letter(string, char, char);
int string_vowels_counter(const string);
int string_word_count(string str);
bool string_includes(string, string);
bool string_is_only_letters(string str);
string string_append(const string, const string);

int main(void) {
    string example = "this is string";
    size_t total_letters = strlen(example);
    int total_vowels = vowels_counter(example);

    printf("total letters: %d\n", total_letters);
    printf("total vowels: %d\n", total_vowels);

    return 0;
}

int string_vowels_counter(const string str) {
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
    size_t str_len = strlen(str);
    size_t word_len = strlen(word);
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

void string_remove_letter(string str, char letter) {
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

string string_append(const string str1, const string str2) {
    size_t str1_length = strlen(str1);
    size_t str2_length = strlen(str2);
    int new_string_length = str1_length + str2_length + 1;

    string new_string = calloc(new_string_length, sizeof(char));

    for (int i = 0; i < str1_length; i++) 
        new_string[i] = str1[i];
    
    for (int i = 0; i < str2_length; i++) 
        new_string[str1_length + i] = str2[i];
    
    return new_string;
}

void string_switch_capitalize(string str) {
    size_t length = strlen(str);

    for (int i = 0; i < length; i++) 
        if (isupper(str[i])) str[i] = tolower(str[i]);
        else str[i] = toupper(str[i]);
}

void string_replace_letter(string str, char old, char new) {
    size_t length = strlen(str);

    for (int i = 0; i < length; ++i)
        if (str[i] == old)
            str[i] = new;
}

bool string_is_only_letters(string str) {
    bool result = true;
    size_t length = strlen(str);

    for (int i = 0; i < length; ++i) 
        if (str[i] != ' ' && !isalpha(str[i]))
            result = false;
    
    return result;
}

void string_trim_begin(string str) {
    int count = 0;
    
    while (isspace(str[count]))
        ++count;

    if (count != 0) {
        int pos = 0;
        while (str[count] != '\0') {
            str[pos] = str[pos+count];
            ++pos;
        }
        str[pos] = '\0';
    }

}

void string_trim_end(string str) {
    size_t index = strlen(str) - 1;
    
    while (index > 0)
        if (isspace(str[index]))
            --index;
        else
            break;
    
    str[index+1] = '\0';
}

int string_word_count(string str) {
    int length = strlen(str);
    int count = 0;

    for (int i = 0; i < length; ++i) 
        if (str[i] == ' ') 
            ++count;
    
    return count + 1;
}