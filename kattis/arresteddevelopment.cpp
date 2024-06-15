#include <bits/stdc++.h>
using namespace std;

const int MAX = 5000001;
const int INF = 1000000000;

int main() {
    int n,a,b;
    cin>>n;
    int **dp = new int*[2];
    dp[0] = new int[MAX];
    dp[1] = new int[MAX];
    for (int i=0;i<MAX;i++) {dp[0][i]=INF; dp[1][i]=INF;}
    dp[0][0] = 0;
    for (int i=0;i<n;i++) {
        cin>>a>>b;
        for (int j=0;j<=min(i * 100000, MAX - 1);j++) {
            dp[(i+1)%2][j] = min(dp[(i+1)%2][j],dp[i%2][j]+b);
            dp[(i+1)%2][j+a] = min(dp[(i+1)%2][j+a],dp[i%2][j]);
        }
        for (int j=0;j<MAX;j++) dp[i%2][j]=INF;
    }
    int ans=INF;
    for (int i=0;i<MAX;i++) ans = min(ans,max(i,dp[n%2][i]));
    cout<<ans;
}