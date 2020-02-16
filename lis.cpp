#include <bits/stdc++.h>
using namespace std;

const int N = 2010;

int dp[N + 7][N + 7];
int arr[N + 7];
int n;

int solve(int pos, int last) {
    if ( pos == n + 1 ) {
        return 0;
    }
    if ( dp[pos][last] != -1 ) {
        return dp[pos][last];
    }
    if ( arr[last] < arr[pos] ) {
        dp[pos][last] = max(dp[pos][last], solve(pos + 1, pos) + 1);
    }
    dp[pos][last] = max(dp[pos][last], solve(pos + 1, last));
    return dp[pos][last];
}

int main() {    
    scanf("%d", &n);
    arr[0] = -1;
    for ( int i = 1; i <= n; ++i ) {
        scanf("%d", &arr[i]);
    }

    memset(dp, -1, sizeof(dp));
    int ans = solve(1, 0);
    printf("%d\n", ans);
    return 0;
}