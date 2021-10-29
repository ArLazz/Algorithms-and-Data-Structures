#include <stdio.h>

int _mergeSort(int a[], int t[], int left, int right);
int merge(int a[], int t[], int left, int mid, int right);
int mergeSort(int a[], int a1)
{
    int t[a1];
    return _mergeSort(a, t, 0, a1 - 1);
}
int _mergeSort(int a[], int t[], int left, int right){
    int mid, ic = 0;
    if (right > left) {
        mid = (right + left) / 2;
        ic += _mergeSort(a, t, left, mid);
        ic += _mergeSort(a, t, mid + 1, right);
        ic += merge(a, t, left, mid + 1, right);
    }
    return ic;
}
int merge(int a[], int t[], int left, int mid, int right){
    int i, j, k;
    int ic = 0;
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (a[i] <= a[j]) {
            t[k++] = a[i++];
        }
        else {
            t[k++] = a[j++];
            ic = ic + (mid - i);
        }
    }
    while (i <= mid - 1)
        t[k++] = a[i++];
    while (j <= right)
        t[k++] = a[j++];
    for (i = left; i <= right; i++)
        a[i] = t[i];
    return ic;
}

int main()
{
    int n, l;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    l = mergeSort(a,n);
    printf("%d", l);

}

