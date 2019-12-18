#include <stdbool.h>
#include <string.h>

bool valid_phone_number(const char* number) {
    //  <----  hajime!
    if(strlen(number) != 14){
        return false;
    }
    for(int i = 0; i < strlen(number); i++){
        if( i == 0 && number[i] != '('){
            return false;
        }
        else if (i == 4 && number[i] != ')'){
            return false;
        }
        else if (i == 5 && number[i] != ' '){
            return false;
        }
        else if(i == 9 && number[i] != '-'){
            return false;
        }
        else if(i != 0 && i != 4 && i != 5 && i != 9){
            if (number[i] < '0' || number[i] > '9'){
                return false;
            }
        }
    }
    return true;
}