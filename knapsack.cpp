#include <bits/stdc++.h>
using namespace std;

const int N = 2010;
int value[N + 7], weights[N + 7];
int cap, n;

int dp[N + 7][N + 7];

int solve(int pos, int w) {
    if ( pos == n + 1 ) {
        return 0;
    }
    if ( dp[pos][w] != -1 ) {
        return dp[pos][w];
    } 
    if ( w + weights[pos] <= cap ) {
        dp[pos][w] = max(dp[pos][w], solve(pos + 1, w + weights[pos]) + value[pos]);
    }
    dp[pos][w] = max(dp[pos][w], solve(pos + 1, w));
    return dp[pos][w];
}

int main() {    
    scanf("%d %d", &cap, &n);
    for ( int i = 1; i <= n; ++i ) {
        scanf("%d %d", &weights[i], &value[i]);
    }
    memset(dp, -1, sizeof(dp));
    int ans = solve(1, 0);
    printf("%d\n", ans);
    return 0;
}