#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

int main(){
    regex_t regex;
    int reti;

    // ^\([0-9]{3}\)\s[0-9]{3}-[0-9]{4}$
    
    //Testing Area Code w/o parenthesis
    reti = regcomp(&regex,"[0-9]{3}",0);
    printf("Regex Value %d\n",reti);
    reti = regexec(&regex,"023",0,NULL,0);
    printf("Regex Value %d\n",reti);

    reti = regcomp(&regex,"[0-9]{3}",0);
    printf("Regex Value %d\n",reti);
    reti = regexec(&regex,"abc",0,NULL,0);
    printf("Regex Value %d\n",reti);

    //Testing Area Code w/ parenthesis
    reti = regcomp(&regex,"\([0-9]{3}\)",0);
    printf("Regex Value %d\n",reti);
    reti = regexec(&regex,"(023)",0,NULL,0);
    printf("Regex Value %d\n",reti);

    //Testing Area Code, parenthesis, and space
    reti = regcomp(&regex,"\([0-9]{3}\)",0);
    printf("Regex Value %d\n",reti);
    reti = regexec(&regex,"(023)",0,NULL,0);
    printf("Regex Value %d\n",reti);
    
}