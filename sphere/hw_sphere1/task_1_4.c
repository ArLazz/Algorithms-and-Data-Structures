#include <stdio.h>


int main()
{   unsigned long int n, m;
    unsigned long int s[2][2];
    unsigned long int q[2][2];
    unsigned long int z[2][2];
    q[0][0] = 1;
    q[0][1] = 0;
    q[1][0] = 0;
    q[1][1] = 1;
    z[0][0] = 1;
    z[0][1] = 1;
    z[1][0] = 1;
    z[1][1] = 0;
    scanf("%lu %lu", &n, &m);
    while (n){
        if (n & 1) {
            s[0][0] = q[0][0];
            s[0][1] = q[0][1];
            s[1][0] = q[1][0];
            s[1][1] = q[1][1];
            q[0][0] = (s[0][0] * z[0][0] + s[0][1] * z[1][0])%m;
            q[0][1] = (s[0][0] * z[0][1] + s[0][1] * z[1][1])%m;
            q[1][0] = (s[1][0] * z[0][0] + s[1][1] * z[1][0])%m;
            q[1][1] = (s[1][0] * z[0][1] + s[1][1] * z[1][1])%m;
        }
        s[0][0] = z[0][0];
        s[0][1] = z[0][1];
        s[1][0] = z[1][0];
        s[1][1] = z[1][1];
        z[0][0] = (s[0][0] * s[0][0] + s[0][1] * s[1][0]) % m;
        z[0][1] = (s[0][0] * s[0][1] + s[0][1] * s[1][1]) % m;
        z[1][0] = (s[1][0] * s[0][0] + s[1][1] * s[1][0]) % m;
        z[1][1] = (s[1][0] * s[0][1] + s[1][1] * s[1][1]) % m;
        n >>= 1;
    }
    printf("%lu",q[0][1]);
    return 0;
}