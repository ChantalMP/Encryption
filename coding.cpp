//
// Created by Chantal on 24.01.2018.
//
#include "data.h"
#include <cstring>

void crypt(char input[], char key[], int mode){
    int inputlength = strlen(input);
    int keylength = strlen(key);
    char output[inputlength];

    if(mode) {
        for (int i = 0; i < inputlength - 1; i++) {
            char clearChar = tolower(input[i]);
            char keyChar = tolower(key[i % keylength]);
            int clearCharValue = (int) clearChar % 97;
            int keyCharValue = (int) keyChar % 97;
            char newChar = vigenereSquare[clearCharValue][keyCharValue];
            output[i] = newChar;
        }
    }

    else{
        for (int i = 0; i < inputlength - 1; i++) {
            char cryptChar = tolower(input[i]);
            char keyChar = tolower(key[i % keylength]);
            int keyCharValue = (int) keyChar % 97;
            for (int j=0; j < charNumber; j++){
                char v = vigenereSquare[keyCharValue][j];
                if(v == cryptChar){
                    printf("if");
                    char clearChar = vigenereSquare[0][j];
                    output[i] = clearChar;
                }
            }
        }
    }
    printf("output:%s", output);
}

