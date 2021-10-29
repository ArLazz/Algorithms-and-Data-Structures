#include <stdio.h>

int base = 1000000009;
bool check(int x){
    long int t = 2;
    bool f = 1;
    while (t * t <= x){
        if (x % t == 0){
            f = 0;
            return f;
        }
        t += 1;
    }
    return f;
}

int main(){
    int n, i, p1, p2, p3, as,d[10011][10][10];
    bool a[1001];
    scanf("%d", &n);
    for(i = 100; i < 1000; i++){
        a[i] = check(i);
    }
    for(p1 = 0; p1 < 10; p1++){
        for(p2 = 0; p2 < 10; p2++){
            for(p3 = 0; p3 < 10; p3++){
                if(a[p1 * 100 + p2 * 10 + p3])
                    d[3][p3][p2] = d[3][p3][p2] + 1;
            }
        }
    }
    for (i = 4; i <= n; i++){
        for(p1 = 0; p1 < 10; p1++){
            for(p2 = 0; p2 < 10; p2++){
                for(p3 = 0; p3 < 10; p3++){
                    if (a[p1 * 100 + p2 * 10 + p3])
                        d[i][p3][p2] = (d[i][p3][p2] + d[i - 1][p2][p1]) % base;
                }
            }
        }
    }
    for(p1 = 0; p1 < 10; p1++){
        for(p2 = 0; p2 < 10; p2++){
            as = (as + d[n][p1][p2]) % base;
        }
    }
    printf("%d\n", as);
    return 0;
}