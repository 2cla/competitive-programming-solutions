#include <bits/stdc++.h>
using namespace std;
const int MAX = 55000;
int dp[2][2][MAX];
int main() {
    int b,p;
    scanf("%d%d",&b,&p);
    int num[p];
    for (int i=0;i<p;i++) scanf("%d",&num[p-i-1]);
    for (int i=0;i<4;i++) {
        for (int j=0;j<MAX;j++) {
            dp[i/2][i%2][j] = 1e9;
        }
    }
    dp[1][0][0] = 0;
    for (int i=0;i<p;i++) {
        int mp = i%2;
        int m = (i+1)%2;
        for (int j=0;j<MAX;j++) {
            if (dp[0][mp][j] < 1e8) {
                dp[0][m][j] = min(dp[0][m][j],dp[0][mp][j] + b-num[i]-1);
                dp[1][m][j+num[i]+1] = min(dp[1][m][j+num[i]+1],dp[0][mp][j]);
            }
            if (dp[1][mp][j] < 1e8) {
                dp[0][m][j] = min(dp[0][m][j],dp[1][mp][j] + b-num[i]);
                dp[1][m][j+num[i]] = min(dp[1][m][j+num[i]],dp[1][mp][j]);
            }
        }
        for (int j=0;j<MAX;j++) {dp[0][mp][j] = 1e9; dp[1][mp][j] = 1e9;}
    }
    int ans = 1e9;
    for (int i=0;i<MAX;i++) {
        ans = min(ans,max(i,dp[0][p%2][i]));
        ans = min(ans,max(i,dp[1][p%2][i]));
    }
    printf("%d",ans);
    return 0;
}