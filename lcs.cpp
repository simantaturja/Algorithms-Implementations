#include <bits/stdc++.h>
using namespace std;

const int N = 2010;

int dp[N + 7][N + 7];
int lenA, lenB;
string a, b;

int solve(int i, int j) {
    if ( i == lenA || j == lenB ) {
        return 0;
    }
    if ( dp[i][j] != -1 ) {
        return dp[i][j];
    }
    if ( a[i] == b[j] ) {
        dp[i][j] = max(dp[i][j], solve(i + 1, j + 1) + 1);
    } else {
        dp[i][j] = max(dp[i][j], max(solve(i + 1, j), solve(i, j + 1)));
    }
    return dp[i][j];
}

int main() {    
    cin >> a >> b;

    lenA = (int)a.length();
    lenB = (int)b.length();
    
    memset(dp, -1, sizeof(dp));

    int ans = solve(0, 0);
    printf("%d\n", ans);
    return 0;
}