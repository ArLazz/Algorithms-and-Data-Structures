#include <stdio.h>
int main(){
    unsigned n, v;
    scanf("%u %u", &v, &n);
    unsigned w[30];
    unsigned total = 0;
    for (unsigned i = 0; i < 2 * n; i += 2) {
        scanf("%u", &w[i]);
        w[i + 1] = w[i];
        total += w[i] << 1;
    }
    if (total < v){
        printf("Impossible");
    } else if (total == v){
        printf("%u", n << 1);
    } else {
        const unsigned lim = 1u << (n << 1);
        unsigned result = -1;
        for (unsigned gen = (lim - 1); gen > 0; gen--) {
            unsigned cur = 0;
            unsigned t = gen;
            unsigned q;
            unsigned c = 0;
            for (unsigned bitnum = 0; t != 0; bitnum++) {
                q = t & 1;
                cur += w[bitnum] * q;
                c += q;
                t >>= 1;
            }
            if (v == cur) {
                result = c;
                break;
            }
        }
        if (result == -1){
            printf("Change");
        } else {
            printf("%u", result);
        }
    }
}