#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef vector<bool> vb;

typedef unordered_map<int,int> umi;
 
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define print(x) trav(a,x)cout<<a<<' ';cout<<'\n';
#define clz __builtin_clz

vector<vi>dp;
vector<vi>eg;
int n;
int rec(int ww,int c){
    if(dp[c][ww]!=1e9)return dp[c][ww];
    if(!ww)return dp[c][ww];
    F0R(i,n){
        if(!(ww&(1<<i)))continue;
        dp[c][ww]=min(dp[c][ww],eg[i][c]+rec(ww^(1<<i),i));
    }
    return dp[c][ww];
}
void solve(){
    int q;cin>>n>>q;
    eg=vector<vi>(n,vi(n,1));
    vpi qs(q);
    F0R(i,q){
        int nn;string ss;
        cin>>nn>>ss;
        qs[i]={nn-1,(ss=="+")};
    }
    vi id(n,0);
    F0R(i,n){
        vi pp(n,1);
        F0R(j,q){
            if(qs[j].f==i){
                if(!qs[j].s){
                    F0R(k,n)pp[k]--;
                }else id[i]++;
            }else{
                if(qs[j].s)pp[qs[j].f]++;
                eg[qs[j].f][i]=max(eg[qs[j].f][i],pp[qs[j].f]);
            }
        }
    }
    int ans=1e9;
    dp=vector<vi>(n,vi(1<<n,1e9));
    F0R(i,n)dp[i][0]=1;
    F0R(i,n)rec(((1<<n)-1)^(1<<i),i);
    F0R(i,n)ans=min(ans,dp[i][((1<<n)-1)^(1<<i)]+id[i]);
    cout<<ans<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}