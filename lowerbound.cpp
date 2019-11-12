#include <bits/stdc++.h>
using namespace std;

int arr[] = {2, 3, 5, 8, 9};

int lowerbound(int n, int num) {
    int lo = 0, hi = n - 1;
    int mid, ans = -1;
    while ( lo <= hi ) {
        mid = lo + (hi - lo) / 2;
        if ( num <= arr[mid] ) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans; //position of lower bound
}

int main() {
    int num = 6;
    int ans = lowerbound(5, num);
    printf("Found %d at position %d\n", arr[ans], ans);
    return 0;
}
