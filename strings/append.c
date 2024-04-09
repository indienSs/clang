#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define string char*

string str_append(const string, const string);

int main(void) {

    string str1 = "first string";
    string str2 = "second string";
    // strcat(str1, str2);

    // printf("String 1 value: %s\n", str1);

    string str3 = str_append(str1, str2);
    printf("append function result: %s\n", str3);

    return 0;
}

string str_append(const string str1, const string str2) {
    int str1_length = strlen(str1);
    int str2_length = strlen(str2);
    int new_string_length = str1_length + str2_length + 1;

    string new_string = calloc(new_string_length, sizeof(char));

    for (int i = 0; i < str1_length; i++) {
        new_string[i] = str1[i];
    }

    for (int i = 0; i < str2_length; i++) {
        new_string[str1_length + i] = str2[i];
    }

    return new_string;
}