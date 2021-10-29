#include <stdio.h>
#include <deque>
bool prime(unsigned x){
    if(x == 2)
        return true;
    for(int i=0;i<100;i++){
        unsigned a = (rand() % (x - 2)) + 2;
        if (gcd(a, x) != 1)
            return false;
        if( pows(a, x-1, x) != 1)
            return false;
    }
    return true;
}
unsigned gcd(unsigned a, unsigned b){
    if(b==0)
        return a;
    return gcd(b, a%b);
}
unsigned mul(unsigned a, unsigned b, unsigned m){
    if(b==1)
        return a;
    if(b%2==0){
        unsigned t = mul(a, b/2, m);
        return (2 * t) % m;
    }
    return (mul(a, b-1, m) + a) % m;
}

unsigned pows(unsigned a, unsigned b, unsigned m){
    if(b==0)
        return 1;
    if(b%2==0){
        unsigned t = pows(a, b/2, m);
        return mul(t , t, m) % m;
    }
    return ( mul(pows(a, b-1, m) , a, m)) % m;
}


int main() {

    unsigned m, n, count = 0, i;
    bool f;
    std::deque<bool> d;

    scanf("%u %u", &m, &n);

    for (i = 2; i < n + 2; i++){
        f = prime(i);
        d.push_back(f);
        count += f;
    }

    for (i = (n + 2); i <= 20000000; i++){
        if (count == m){
            break;
        }
        count -= d.front();
        d.pop_front();
        f = prime(i);
        d.push_back(f);
        count += f;
    }

    if (i == 20000000){
        printf("-1");
    } else {
        printf("%u", i - n);
    }

    return 0;
}