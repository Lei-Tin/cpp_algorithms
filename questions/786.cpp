#include <iostream>

using namespace std;

const int N = 1e6 + 1;
int n, k;

int lst[N];

void quick_sort(int q[], int l, int r){
    if (l >= r) return;
    
    int i = l - 1, j = r + 1;
    
    int pivot = q[(l + r) >> 1];
    while (i < j) {
        while (q[++i] < pivot);
        while (q[--j] > pivot);
        
        if (i < j) swap(q[i], q[j]);
    }
    
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main(){
    scanf("%d %d", &n, &k);
    
    for (int i = 0; i < n; i++) scanf("%d ", &lst[i]);
    
    quick_sort(lst, 0, n - 1);
    
    printf("%d", lst[k - 1]);
}