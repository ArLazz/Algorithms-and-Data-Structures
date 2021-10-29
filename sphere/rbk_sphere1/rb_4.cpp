#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    char b[10000 + 1];
    scanf("%10000s", b);
    std::string s(b);
    int n = (int)s.size();
    std::vector<int> v(1 + n);
    int sum = 0;
    for (int ix = 0; ix < n; ix++) {
        v[1] = 0;
        int len = 0;
        int m = 0;
        for (int i = 1; i < n; i++) {
            while (true) {
                if (s[i] == s[len]) {
                    len += 1;
                    break;
                }
                if (len == 0) {
                    break;
                }
                len = v[len];
            }
            v[i + 1] = len;
            m = std::max(m, len);
        }
        sum += (int)s.size() - m;
        s.erase(s.begin());
    }
    printf("%d", sum);
    return 0;
}