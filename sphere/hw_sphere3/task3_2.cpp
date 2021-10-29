#include <vector>
#include <stdio.h>
#include <algorithm>
void sort_bubble_traditional_s(int *a, int n,int q,int m, int l) {
    for (int i = n-1; --n >- 0;) {
        for (int j = 0; j < i; j++) {
            if (a[q + j] > a[q + j+1]) {
                for (int k = 0; k < m; k++) {
                    int tmp = a[k * l + j];
                    a[k * l + j] = a[k * l + j + 1];
                    a[k * l + j + 1] = tmp;
                }
                printf("123\n");

            }
        }
    }
}

using namespace std;
static const int QUICK_THRESHOLD = 0;
void quickSortBase_s(int *a, int l, int r, int q, int n, int m1) {
    if (r - l < QUICK_THRESHOLD) {
        sort_bubble_traditional_s(a+l,r-l+1, q, n, m1);
        return;
    }
    int i = l, j = r;
    int pp[3] = { a[q + l], a[q + r], a[q + ((l+r)>>1)]};
    if (pp[0] < pp[1]) swap(pp[0],pp[1]);
    if (pp[1] < pp[2]) swap(pp[1],pp[2]);
    if (pp[0] < pp[1]) swap(pp[0],pp[1]);
    int p = pp[1];
    while (i <= j) {
        while (p > a[q + i])
            i++;
        while (a[q + j] > p)
            j--;
        if (i <= j) {
            for (int k = 0; k < n; k++){
                int tmp = a[k * m1 + i];
                a[k * m1 + i] = a[k * m1 + j];
                a[k * m1 + j] = tmp;
            }
            i++;
            j--;
        }
    }
    if (l < j)
        quickSortBase_s(a, l, j, q, n, m1);
    if (i < r)
        quickSortBase_s(a, i, r, q, n, m1);
}

void sort_quick_recursive_s(int *a, int m,int q, int n, int l) {
    quickSortBase_s(a,0,m-1,q, n, l);
}





void sort_bubble_traditional_l(int *a, int n, int m) {
    for (int i = n-1; --n >- 0;) {
        for (int j = 0; j < i; j++) {
            if (a[j*m] > a[(j+1) * m]) {
                for (int k = 0; k < m; k ++){
                    int tmp = a[j * m + k];
                    a[j * m + k] = a[(j + 1) * m + k];
                    a[(j + 1) * m + k] = tmp;
                }
            }
        }
        printf("123\n");
    }
}



void quickSortBase_l(int *a, int l, int r, int m) {
    if (r - l < QUICK_THRESHOLD) {
        sort_bubble_traditional_l(a+l,r-l+1, m);
        return;
    }
    int i = l, j = r;
    int pp[3] = { a[l * m], a[r * m], a[((l+r)*m)>>1]};
    if (pp[0] < pp[1]) swap(pp[0],pp[1]);
    if (pp[1] < pp[2]) swap(pp[1],pp[2]);
    if (pp[0] < pp[1]) swap(pp[0],pp[1]);
    int p = pp[1];
    while (i <= j) {
        while (p > a[i * m])
            i++;
        while (a[j * m] > p)
            j--;
        if (i <= j) {
            for (int k = 0; k < m; k ++){
                int tmp = a[i * m + k];
                a[i * m + k] = a[j * m + k];
                a[j * m + k] = tmp;
            }
            /*int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;*/
            i++;
            j--;
        }
    }
    if (l < j)
        quickSortBase_l(a, l, j, m);
    if (i < r)
        quickSortBase_l(a, i, r, m);
}

void sort_quick_recursive_l(int *a, int n,int m) {
    quickSortBase_l(a,0,n-1,m);
}



int main(){
    unsigned n, m, min = -1, imin;
    scanf("%u %u", &n, &m);
    int a[n][m];
    for (unsigned i = 0; i < n; i++){
        for (unsigned j = 0; j < m; j++){
            scanf("%u",&a[i][j]);
            if (a[i][j] < min) {
                min = a[i][j];
                imin = i;
            }
        }
    }
    sort_quick_recursive_s(*a, m, imin * m, n, m);
    sort_quick_recursive_l(*a, n, m);
    for (unsigned i = 0; i < n; i++){
        for (unsigned j = 0; j < m; j++){
            printf("%u ",a[i][j]);
        }
        printf("\n");
    }

}