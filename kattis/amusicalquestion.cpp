#include <bits/stdc++.h>
using namespace std;
int main() {
    int c,n;
    scanf("%d%d", &c,&n);
    int s[n];
    for (int i=0;i<n;i++) scanf("%d", &s[i]);
    bool dp[2][c+1][c+1];
    for (int i=0;i<c+1;i++) {
        for (int j=0;j<c+1;j++) {
            dp[0][i][j] = false; dp[1][i][j] = false;
        }
    }
    dp[1][0][0] = true;
    int t,m1,m2;
    for (int k=0;k<n;k++) {
        t = s[k]; m1 = k%2; m2 = (k+1)%2;
        for (int i=0;i<c+1;i++) {
            for (int j=0;j<c+1;j++) {
                if (dp[m2][i][j]) {
                    dp[m1][i][j] = true;
                    if (i+t<=c) dp[m1][i+t][j] = true;
                    if (j+t<=c) dp[m1][i][j+t] = true; 
                }
            }
        }
    }
    int best,diff,b1,b2;
    best = 0; diff = 0; b1 = 0; b2 = 0;
    for (int i=0;i<c+1;i++) {
        for (int j=0;j<c+1;j++) {
            if (dp[(n+1)%2][i][j]) {
                if (i+j>best) {
                    best = i+j; diff = abs(i-j); b1 = max(i,j); b2 = min(i,j);
                } else if (i+j==best and diff>abs(i-j)) {
                    diff = abs(i-j); b1 = max(i,j); b2 = min(i,j);
                }
            }
        }
    }
    printf("%d %d",b1,b2);
    return 0;
}