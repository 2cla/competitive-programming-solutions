#include <bits/stdc++.h>
using namespace std;

double dp[101][2001];
vector<double> tot;
vector<double> pre;
vector<double> sqpre;

int main() {
    int m,n,k;
    double s,mu;
    scanf("%d%d%d%lf",&m,&n,&k,&s);
    tot.resize(m+n, 0); pre.resize(m+n+1, 0); sqpre.resize(m+n+1, 0);
    for (int i=0; i<m+n; i++) scanf("%lf", &tot[i]);
    sort(tot.begin(), tot.end());
    for (int i=1; i<=m+n; i++) {
        pre[i] = pre[i-1]+tot[i-1];
        sqpre[i] = sqpre[i-1]+tot[i-1]*tot[i-1];
    }
    for (int i=0; i<101; i++) {
        for (int j=0; j<2001; j++) {
            dp[i][j] = 2e9+7;
        }
    }
    dp[0][0] = 0;
    for (int i=1; i<k+1; i++) {
        for (int y=1; y<m+n+1; y++) {
            for (int z=0; z<y; z++) {
                mu = (pre[y]-pre[z])/(y-z);
                dp[i][y] = min(dp[i][y], dp[i-1][z] + (sqpre[y]-sqpre[z])-2*mu*(pre[y]-pre[z])+(y-z)*mu*mu);
            }
        }
    }
    printf("%.9f\n", dp[k][m+n]+s*s*(m+n)/4);
    return 0;
}