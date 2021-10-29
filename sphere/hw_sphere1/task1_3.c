#include <stdio.h>
#define length 4


int factorial(int count){
    int v = 1;
    for (int i = 1;i <= count; i++)
        v = v * i;
    return v;
}

int main(void){
    long long int n, k;
    scanf("%lld%lld", &n, &k);
    k -= 1;
    long long int a, cur, fac;
    long long int per[21];
    long long int was[21] = {0};
    if (k > factorial(n)){
        for (long long int i = 1; i <= n; i++){
            printf("%lld ", i);
        }
    } else {
        for (long long int i = 1; i <= n; i++) {
            fac = factorial((n - i));
            a = k / fac;
            k %= fac;
            cur = 0;
            for (long long int j = 1; j <= n; j++) {
                if (was[j] == 0) {
                    cur += 1;
                    if (cur == (a + 1)) {
                        per[i] = j;
                        was[j] = 1;
                    }
                }
            }
        }
        for (long long int i = 1; i <= n; i++) {
            printf("%lldd ", per[i]);
        }
    }
    return 0;
}