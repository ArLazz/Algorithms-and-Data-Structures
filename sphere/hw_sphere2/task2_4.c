#include <stdio.h>
int main() {
    unsigned n;
    scanf("%u", &n);
    unsigned a[n], b[n];
    getchar();
    for (unsigned i = 0; i < n; i++) {
        unsigned next_flag = 0, secs = 0, counter = 0;
        while (!next_flag) {
            char c = getchar();
            if (c == ':') {
                secs += counter;
                counter = 0;
                secs *=60;
            } else if (c == ' ') {
                a[i] = secs + counter;
                secs = 0;
                counter = 0;
            } else if (c == '\n') {
                b[i] = secs + counter;
                next_flag = 1;
            } else {
                counter *= 10;
                counter += c - '0';
            }
        }
    }
    // for (unsigned i = 0; i < n; i++) {
    //     printf("%u\n", a[i]);
    //     printf("%u\n", b[i]);
    // }
    for (unsigned i = 0; i < n - 1; i++) {
        for (unsigned j = 0; j < n - i - 1; j++) {
            if (b[j] > b[j+1]) {
                unsigned temp = b[j];
                b[j] = b[j+1];
                b[j+1] = temp;

                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    // printf("\n");
    // for (unsigned i = 0; i < n; i++) {
    //     printf("%u\n", a[i]);
    //     printf("%u\n", b[i]);
    // }
    unsigned n_max = 0;
    for (unsigned i = 0; i < n - 1; i++) {
        unsigned n_in = 1;
        if (n_max < n - i + 1) {
            for (unsigned j = i + 1; j < n; j++) {
                if (a[j] <= b[i]) {
                    n_in += 1;
                }
            }
            if (n_max < n_in) {
                n_max = n_in;
            }
        } else break;
    }
    // printf("\n");
    printf("%u", n_max);
    return 0;
}
