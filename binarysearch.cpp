#include <bits/stdc++.h>
using namespace std;

int arr[] = {2, 3, 5, 8, 9};
int n = 5; //array size

int binary_search(int num) {
    int lo = 0, hi = n - 1;
    int mid;
    while ( lo <= hi ) {
        mid = lo + (hi - lo) / 2;
        if ( num == arr[mid] ) {
            return num; //number found
        } else if ( num > arr[mid] ) {
            lo = mid + 1;
        } else if ( num < arr[mid] ) {
            hi = mid - 1;
        }
    }
    return -1; //number not found
}

int main() {
    int num = 8;
    if ( binary_search(num) != -1 ) {
        cout << "Found " << num << '\n';
    } else {
        cout << "Not Found\n";
    }
    return 0;
}
