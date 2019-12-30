
char* printerError(char *s) {
    // your code
    int errors = 0, length = strlen(s),i;
    char err_msg[5];  
    
    for(i=0;i<length;i++){
      printf("Char is %c\n",s[i]);
      if(s[i] > 'n')
        errors++;
    }
    sprintf(err_msg,"%d/%d",errors,length);
    printf("%s\n",err_msg);
    return err_msg;
}