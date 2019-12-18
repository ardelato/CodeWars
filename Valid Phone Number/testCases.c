#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h> 

char *phoneOne = "(123) 456-7890";
char *phoneTwo = "(1111) 456-7890";
char *phoneThree = "(abc) def-hihk";
char *phoneFour = "(098) 123 4567";

void assertPrint(char *expected, bool actual){
    char *ac = actual==true?"True":"False";
    printf("Expeceted: %s, Actual: %s\n",expected,ac);
}

int main(){
    assertPrint("True",valid_phone_number(phoneOne));
    assertPrint("False",valid_phone_number(phoneTwo));
    assertPrint("False",valid_phone_number(phoneThree));
    assertPrint("False",valid_phone_number(phoneFour));
}

