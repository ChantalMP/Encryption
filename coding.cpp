//
// Created by Chantal on 24.01.2018.
//
#include "data.h"

void encode(char input[], char key[]){
    int inputlength = strlen(input);
    int keylength = strlen(key);
    char output[inputlength];

    for(int i = 0; i < inputlength-1; i++){
        char clearChar = tolower(input[i]);
        char keyChar = tolower(key[i%keylength]);
        int clearCharValue = (int)clearChar % 97;
        int keyCharValue = (int)keyChar % 97;
        char newChar = vigenereSquare[clearCharValue][keyCharValue];
        output[i] = newChar;
    }
    printf(output);
}

void decode(char input[], char key[]){

}

