#include <stdbool.h>

typedef struct stack
{
    int maxsize; //Max is 100
    int size;
    char *items;
}Stack;

Stack *newStack(){
    Stack *pt = (Stack *)malloc(sizeof(Stack));
    
    pt->maxsize = 100;
    pt->size = 0;
    pt->items = (char*)malloc(sizeof(char) * 100);

    return pt;
}

int size(Stack *pt){
    return pt->size;
}

int isEmpty(Stack *pt){
    return pt->size == 0;
}

int isFull(Stack *pt){
    return pt->size == 100;
}

bool push(Stack *pt, char x){
    if(isFull(pt))
    {
        return true;
    }
    pt->items[pt->size++] = x;
    return false;
}

char pop(Stack *pt){
    if(isEmpty(pt))
    {
        return 'f';
    }
    return pt->items[--pt->size];
}

bool validParentheses(const char* string){
    Stack *nStack = newStack();

    for(int i = 0; i < strlen(string); i++){
        if(string[i] == '('){
            if(push(nStack,string[i])){
                return false;
            }
        }
        else if(string[i] == ')'){
            char x = pop(nStack);
            if(x != '(') {
                return false;
            }
        }
    }
    if(size(nStack) != 0) return false;
    free(nStack);
    return true;
}

// Best Solutions

/*
#include <stdbool.h>

bool validParentheses(const char* strin)
{
    int c = 0;
    while(*strin) {
        switch(*strin) {
            case '(':
                c++; break;
            case ')':
                if (c == 0) return false;
                c--; break;
        }
        strin++;
    }

    return c == 0;
}
*/

/*
#include <stdbool.h>

bool validParentheses(const char* p) {
  int n = 0;
  for (; *p; p++) if ((n += (*p == '(') - (*p == ')')) < 0) break;
  return n == 0;
}
*/
