#include <string.h>
#include <ctype.h>

int main() {

    char str[] = "abcdEFGH";
    size_t length = strlen(str);

    for (int i = 0; i < length; i++) {
        if (isupper(str[i])) str[i] = tolower(str[i]);
        else str[i] = toupper(str[i]);
    }

    return 0;
}