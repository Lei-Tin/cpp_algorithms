#include <iostream>

using namespace std;

int main() {
    double eps = 1e-8;
    
    double l = -1e4, r = 1e4;
    
    double x;
    scanf("%lf", &x);
    
    while (r - l > eps) {
        double mid = (l + r) / 2;
        
        if (mid * mid * mid <= x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    
    printf("%f", l);
    
    return 0;
}