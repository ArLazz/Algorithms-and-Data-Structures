#include <vector>
#include <stdio.h>
#include <algorithm>

int main(){
    char q, c;
    unsigned p, e, j = 0;
    q = getchar();
    std::vector<unsigned> v(26);
    while (q != '\n'){
        v[q- 'A'] += 1;
        q = getchar();
    }
    for (unsigned i = 0;i < 26; i++){
        j += v[i] != 0;
    }
    for (unsigned i = 0;i < j; i++){
            p = std::max_element(v.begin(), v.end()) - v.begin();
            e = *std::max_element(v.begin(), v.end());
            c = 'A' + p;
            v[p] = 0;
            printf("%c %u\n", c, e);
    }
}