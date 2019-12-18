#include <stdbool.h>
#include <string.h>
#include <regex.h>

bool valid_phone_number(const char* number) {
    //  <----  hajime!
    regex_t regex;
    int reti;

    reti = regcomp(&regex,"^\([0-9]{3}\)\s[0-9]{3}-[0-9]{4}$",0);
    printf("Regex Value %d\n",reti);
    reti = regexec(&regex,number,0,NULL,0);
    
    if(reti != 0){
        return false;
    }

  /*   if(strlen(number) > 14){
        printf("Longer than 14\n");
        return false;
    }
    for(int i = 0; i < strlen(number); i++){
        printf("Current Character %c\n",number[i]);
        printf("\tInt is %d\n",number[i]);
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
        else if(number[i] < '0' || number[i] > '9'){
            return false;
        }
    } */
    return true;
}