#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define length 4

char * func(){
    int i = 0,n = 4;
    char q, *str1, *str = (char*)malloc(n);
    q = getchar();
    *str = q;
    i += 1;
    while ((q != '\n') && (q != EOF)){
        if (n <= (i + 1)){
            n += length;
            str1 = (char*)realloc(str, n);
            if (str1 == NULL){
                printf("Ошибка");
            }else{
                str = str1;
            }
        }
        q = getchar();
        *(str + i) = q;
        i += 1;
    }
    *(str + i) = '\0';
    return str;
}


int main(void){
    char *s;
    int q[4] = {0}, i = 0;
    while (s[i] != EOF || s[i] != '\0'){
        s = func();
        while (s[i] != '\n' || s[i] != EOF){
            if (s[i] == '(' && s[i + 1] == '*') {
                while (s[i] != '*' && s[i + 1] != ')') {
                    i += 1;
                }
                q[0] += 1;
            }
            else if (s[i] == '{') {
                while (s[i] != '}') {
                    i += 1;
                }
                q[1] += 1;
            }
            else if (s[i] == '/' && s[i + 1] == '/') {
                while (s[i] != '\n') {
                    i += 1;
                }
                q[2] += 1;
            }
            else if (s[i] == '\'') {
                while (s[i] != '\'')) {
                    i += 1;
                }
                q[3] += 1;
            }
            i += 1;
        }
    }
    for (i = 0; i < 4; i++){
        printf("%d", q[i]);
    }
}