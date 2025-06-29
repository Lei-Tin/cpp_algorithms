#include <iostream>

using namespace std;

const int N = 1e6 + 1;
int n, q, k;

int lst[N];


int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) scanf("%d ", &lst[i]);
    
    int mid; 
    int l, r;
    
    while (q--) {
        int x;
        scanf("%d", &x);
        
        l = 0, r = n - 1;
        mid;
        
        while (l < r) {
            mid = (l + r) >> 1;
            
            // Find left boundary
            if (lst[mid] >= x) r = mid;
            else l = mid + 1;
        }
        
        if (lst[l] != x) {
            printf("-1 -1\n");
            continue;
        }
        
        printf("%d ", l);
        
        // Find right boundary
        l = 0, r = n - 1;
        
        while (l < r) {
            mid = (l + r + 1) >> 1;
    
            if (lst[mid] <= x) l = mid;
            else r = mid - 1;
        }
        
        printf("%d\n", l);
    }
}