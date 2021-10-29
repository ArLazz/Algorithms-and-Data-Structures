#include <set>
#include <string.h>
#include <stdio.h>
using namespace std;
int main(){
    std:set<int[26]> s;
    unsigned n, i , j, b, v, el, y = 0;
    char str[10000];
    scanf("%u", &n);
    for (i = 0; i < n; i++){
        scanf("%s", str);
        int l[26] = {0};
        for (j = 0;j < strlen(str); j++){
            v = str[i] - 'A';
            l[v] += 1;
        }
        s.insert(l);
    }
    i = 0;
    for (auto el: s){
        i += 1;
    }
    printf("%d", i);
}
