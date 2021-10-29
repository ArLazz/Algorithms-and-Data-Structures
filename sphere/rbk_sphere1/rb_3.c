#include <stdio.h>

int f(int n, int i) {
    if (i == 0) return  n;
    int y = 1 << (n-1);
    if (i < y) return f(n-1, i - 1 +  - (((n - 9) >0) * (n - 9)));
    else       return f(n-1, 2 * y - i - 2);
}

int main() {
    int n,k,l,c;
    scanf("%u%u%u",&n,&k,&l);
    for (int i = k; i <= l; i++) {
        c = f(n,i-1);
        printf("%d ", c);
    }
}