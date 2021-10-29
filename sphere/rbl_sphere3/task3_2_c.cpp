#include <stdio.h>
#include <stdlib.h>
#define MODULE 1000000009
bool* eratosphen(int bound) {
    bool* a = (bool*) malloc(bound * sizeof(bool));
    for (int i = 0; i < bound; i++) {
        a[i] = true;
    }
    a[0] = false;
    a[1] = false;
    int cur = 2;
    while (cur < bound) {
        int k = cur * cur;
        while (k < bound) {
            a[k] = false;
            k += cur;
        }
        cur++;
        while ((cur < bound) && (!a[cur])) {
            cur++;
        }
    }
    return a;
}
int main() {
    int n;
    scanf("%u", &n);
    if (n < 3) {
        return 0;
    }
    if (n == 3) {
        printf("143\n");
        return 0;
    }
    bool* primes = eratosphen(1000);
    int profile[100][100];
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            profile[i][j] = false;
        }
    }
    for (int i = 10; i < 100; i++) {
        for (int j = 0; j < 10; j++) {
            if ((primes[i * 10 + j]) && ((i % 10) * 10 + j > 9)) {
                profile[i][(i % 10) * 10 + j] = true;
            }
        }
    }
    int a[100], b[100];
    for (int i = 0; i < 100; i++) {
        a[i] = 0;
        b[i] = 0;
    }
    for (int i = 100; i < 1000; i++) {
        if ((primes[i]) && (i % 100 > 9)) {
            a[i % 100]++;
        }
    }
    for (int i = 0; i < n - 3; i++) {
        for (int j = 10; j < 100; j++) {
            for (int k = 10; k < 100; k++) {
                if (profile[j][k]) {
                    b[k] = (b[k] + a[j]) % MODULE;
                }
            }
        }
        for (int i = 0; i < 100; i++) {
            a[i] = b[i];
            b[i] = 0;
        }
    }
    int ans = 0;
    for (int i = 10; i < 100; i++) {
        ans = (ans + a[i]) % MODULE;
    }
    printf("%d\n", ans);
}