//
// Created by Chantal on 24.01.2018.
//
#include "data.cpp"
#include <cstring>

void crypt(char input[], char key[], int mode){
    int inputlength = strlen(input);
    int keylength = strlen(key);
    char output[inputlength];

    if(mode) {
        for (int i = 0; i < inputlength - 1; i++) {
            char clearChar = tolower(input[i]);
            if ((int) clearChar >= 97 && (int) clearChar <= 122) {
                char keyChar = tolower(key[i % keylength]);
                int clearCharValue = (int) clearChar % 97;
                int keyCharValue = (int) keyChar % 97;
                char newChar = vigenereSquare[clearCharValue][keyCharValue];
                output[i] = newChar;
            } else
                output[i] = input[i];
        }
    }

    else{
        for (int i = 0; i < inputlength - 1; i++) {
            char cryptChar = tolower(input[i]);
            if ((int)cryptChar >= 97 && (int)cryptChar <= 122) {
                int cryptCharValue = (int) cryptChar % 97;
                char keyChar = tolower(key[i % keylength]);
                int keyCharValue = (int) keyChar % 97;
                for (int j = 0; j < charNumber; j++) {
                    char tmp = vigenereSquare[keyCharValue][j];
                    if (tmp == cryptChar) {
                        char clearChar = vigenereSquare[0][j];
                        output[i] = clearChar;
                    }
                }
            }
            else
                output[i] = input[i];
        }
    }
    printf("output:%s\n", output);
    fflush(stdin);
    fflush(stdout);
}

