#include <stdio.h>
static const int MERGE_THRESHOLD = 8;

void sort_bubble_traditional(int *a, int n, int &s ) {
    for (int i = n-1; --n >- 0;) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j+1]) {
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                s += 1;
            }
        }
    }
}

void merge(int *a, int low, int mid, int high, int *aux ,int &s) {
    int i,j,q = 0,s1 = 0, s2 = 0;
    bool f = 0;
    for (i = mid+1; i > low; i--) aux[i-1] = a[i-1];
    for (j = mid; j < high; j++) aux[high+mid-j]=a[j+1];
    for (int k = low; k <= high; k++) {
        if (aux[j] <= aux[i]) {
            a[k] = aux[j--];
            q += 1;
        }
        else {
            s1 += q + s2;
            s2 = q;
            q = 0;
            a[k] = aux[i++];
        }
    }
    s += s1 + s2 + q;
}

void mergeSort(int a[], int low, int high, int *aux, int &s) {
    if (high - low < MERGE_THRESHOLD) {
        sort_bubble_traditional(a+low, high-low+1, s);
    } else {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid, aux, s);
        mergeSort(a, mid+1, high, aux, s);
        merge(a, low, mid ,high, aux, s);
    }
}

void sort_merge(int *a, int n, int &s) {
    int *aux = new int[n];
    mergeSort(a,0,n-1, aux, s);
    delete [] aux;
}

int main(){
    int s = 0, n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    sort_merge(a, n, s);
    printf("%d", s);
}