#include <stdbool.h>
#include <stdio.h> 

void assertPrint(char *expected, bool actual){
    char *ac = actual==true?"True":"False";
    printf("Expeceted: %s, Actual: %s\n",expected,ac);
}

int main(){
    char *pOne = "  (";
    char *pTwo = ")test";
    char *pThree = "";
    char *pFour = "hi())(";
    char *pFive = "hi(hi)()";
    char *pSix = "()";
    char *pSeven = "(())((()())())";

    assertPrint("false",validParentheses(pOne));
    assertPrint("false",validParentheses(pTwo));
    assertPrint("true",validParentheses(pThree));
    assertPrint("false",validParentheses(pFour));
    assertPrint("true",validParentheses(pFive));
    assertPrint("true",validParentheses(pSix));
    assertPrint("true",validParentheses(pSeven));
    return 0;
}