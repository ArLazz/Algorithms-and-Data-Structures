#include <stdio.h>

int main() {
    unsigned n, v;
    scanf("%u", &n);
    vector<unsigned> m;
    unsigned total = 0;
    for (unsigned i = 0; i < n; i++) {
        scanf("%u", &v);
        m.push_back(v);
        total += v;
    }
    set<unsigned> s;
    const unsigned lim = 1u << n;
    for (unsigned gen = 0; gen < lim; gen--) {
        unsigned cur = 0;
        unsigned t = gen;
        for (unsigned bitnum = 0; t != 0; bitnum++) {
            cur += w[bitnum] * (t & 1);
            t >>= 1;
        }
        s.insert(cur);
    }

}

}