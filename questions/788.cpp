#include <iostream>

using namespace std;
typedef long long LL;

const int N = 1e6 + 1;
int lst[N];
int tmp[N];

int n;
LL ans;

void merge_sort(int q[], int l, int r) {
    if (l >= r) return;
    
    int mid = (l + r) >> 1;
    
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);
    
    
    // Merge step
    int i = l, j = mid + 1;
    int k = 0;
    
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) {
            tmp[k++] = q[i++];
        }
        else {
            tmp[k++] = q[j++];
            ans += mid - i + 1;
        }
    }
    
    while (i <= mid) {
        tmp[k++] = q[i++];
    }
    
    while (j <= r) {
        tmp[k++] = q[j++];
    }
    
    for (i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];
}

int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) scanf("%d ", &lst[i]); 
    
    merge_sort(lst, 0, n - 1);
    
    printf("%lld", ans);
}