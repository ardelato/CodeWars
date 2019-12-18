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

//Best Solutions

// sscanf solution
/* 
#include <stdbool.h>

bool valid_phone_number(const char* number)
{
   int frmt_len = strlen("(123) 456-7890");
   if (strlen(number) == frmt_len)
   {
      char b[frmt_len];
      if (sscanf(number, "%1[(]%3[0-9]%1[)]%1[ ]%3[0-9]%1[-]%4[0-9]%1s", b, b, b, b, b, b, b, b) == 7) return true;
   }
   return false;
}
*/

// Macro solution
/* 
#include <stdbool.h>
#include <ctype.h>

bool valid_phone_number(const char* number) {
#define SCAN(c)   if (*number++ != c) { return false; }
#define SCAN_D(n) for (int i = 0; i < n; i += 1) { if (!isdigit(*number++)) { return false; } }
    SCAN('(');
    SCAN_D(3);
    SCAN(')');
    SCAN(' ');
    SCAN_D(3);
    SCAN('-');
    SCAN_D(4);
    SCAN('\0');
    return true;
} 
*/