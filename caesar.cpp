//
// Created by Chantal on 31.01.2018.
//

#include <cstring>

void cryptCaesar(char input[], int key, int mode){
    int inputlength = strlen(input);
    char output[inputlength];
    if (!mode)
        key = -key;
    //encode
        for (int i = 0; i < inputlength - 1; i++) {
            //lower case
            char clearChar = input[i];
            int clearCharValue = (int) clearChar;
            if (clearCharValue >= 97 && clearCharValue <= 122) {
                int tmp = clearCharValue-97+key;
                while (tmp < 0)
                    tmp+=26;
                int newCharValue = (tmp%26)+97;
                char newChar = (char) newCharValue;
                output[i] = newChar;
            }
            //upper case
            else if (clearCharValue >= 65 && clearCharValue <= 90) {
                int tmp = clearCharValue-65+key;
                while (tmp < 0)
                    tmp+=26;
                int newCharValue = (tmp % 26)+65;
                char newChar = (char) newCharValue;
                output[i] = newChar;
            }
            else
                output[i] = input[i];
        }

    printf("Caesar: %s\n", output);
    fflush(stdin);
    fflush(stdout);
}