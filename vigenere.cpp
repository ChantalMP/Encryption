#include <iostream>
#include <cstring>
#include "coding.cpp"

int main() {
    bool end = false;
    while (!end) {
        printf("Do you want to encode or decode? Choose E or D. If you want to quit please press Q.\n");
        char mode[2];
        fgets(mode, 2, stdin);
        fflush(stdin);
        while(strcmp(mode, "D") && strcmp(mode, "d") && strcmp(mode, "E") && strcmp(mode, "e") && strcmp(mode, "Q") && strcmp(mode, "q")){
            printf("No valid input. Please choose again.\n");
            fgets(mode, 2, stdin);
            fflush(stdin);
        }

        if (!strcmp(mode, "D") || !strcmp(mode, "d"))
        {
            printf("Please type the text you want to decode: (until 127 characters)\n");
            char input[128];
            fgets(input, 128, stdin);
            fflush(stdin);
            crypt(input, "test", 0);
        }
        else if (!strcmp(mode, "E") || !strcmp(mode, "e"))
        {
            printf("Please type the text you want to encode: (until 127 characters)\n");
            char input[128];
            fgets(input, 128, stdin);
            fflush(stdin);
            crypt(input, "test", 1);
        }
        else
        {
            return 0;
        }
    }
}