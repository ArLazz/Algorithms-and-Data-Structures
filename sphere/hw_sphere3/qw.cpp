#include <stdio.h>
#include <cstdlib>

int merge(int a[],int t[], int left, int mid, int right){   
    int ic = 0, i = left, j = mid, k = left;
    while((i <= mid-1) && (j <= right)){
        if(a[i] <= a[j]){
            t[k++] = a[i++];
        } else {
            t[k++] = a[j++];
            ic += (mid - i);
        }
    }
    while(i <= mid-1)
        t[k++] = a[i++];
    while(j <= right)
        t[k++] = a[j++];
    for(i = left; i <= right; i++)
        a[i] = t[i];
    return ic;
}

int merge2(int a[], int t[], int left, int right){
    int mid, ic = 0;
    if(right > left){
        mid = (right+left)/2;
        ic = merge2(a,t,left,mid);
        ic += merge2(a,t,mid+1,right);
        ic += merge(a,t,left,mid+1,right);
    }
    return ic;
}

int merge_sort(int a[], int a1){
    int *t = (int *)malloc(sizeof(int)*a1);
    return (merge2(a,t,0,a1-1));
}

int main(){
    int n, l;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    l = merge_sort(a,n);
    printf("%d", l);
}

