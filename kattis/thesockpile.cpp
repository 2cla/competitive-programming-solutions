#include <bits/stdc++.h>
using namespace std;
using ll = long long;

unordered_map<ll,double> dp;
ll m,n;

double rec(int x,int y,int z) {
    ll key = 4e6*x+2e3*y+z;
    if (dp.find(key) != dp.end()) return dp[key];
    if (y==0 && z<=1) {dp[key] = 1.0; return 1.0;}
    if (x<0 || y<0 || z<0) {dp[key] = 0.0; return 0.0;}
    double d = (x+y+z)*(x+y+z-1);
    dp[key] = (x*(x-1)*rec(x-2,y,z) + 2.0*x*y*rec(x,y-2,z) + 2.0*x*z*rec(x-1,y,z-1) + 2.0*y*z*rec(x+1,y-2,z-1) + y*(y-2)*rec(x+2,y-4,z))/d;
    return dp[key];
}

int main() {
    cin>>m>>n;
    cout<<rec(0,2*m,n);
    return 0;
}