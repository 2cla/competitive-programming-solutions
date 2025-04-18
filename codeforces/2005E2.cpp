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
 
void solve(){
    int l,m,n;cin>>l>>n>>m;
    vi brr(n*m+1,-1);
    set<int>fu;
    vi arr;
    F0R(i,l){
        int tt;cin>>tt;
        if(!fu.count(tt)){
            fu.ins(tt);
            arr.pb(tt);
            brr[tt]=sz(arr)-1;
        }
    }
    l=sz(arr);
    vector<vi>dd(l,vi(n,-1));
    vector<vi>ww(l,vi(n,0));
    F0R(i,n){
        F0R(j,m){
            int w;cin>>w;
            if(brr[w]!=-1)dd[brr[w]][i]=j;
        }
    }
    F0R(i,l){
        int w=-1;
        F0Rd(j,n){
            if(dd[i][j]<=w)dd[i][j]=-1;
            else w=dd[i][j];
        }
    }
    F0R(i,n){
        if(dd[l-1][i]!=-1)ww[l-1][i]=1;
    }
    F0Rd(i,l-1){
        int ls=0,w=-1;
        vi dp(m);
        if(dd[i][n-1]!=-1){
            ww[i][n-1]=1;w=dd[i][n-1];
        }
        FORd(j,1,n){
            if(dd[i+1][j]>w&&ww[i+1][j]){
                ls++;dp[dd[i+1][j]]++;
            }
            if(dd[i][j-1]==-1)continue;
            ww[i][j-1]=1;
            while(w<dd[i][j-1]){
                w++;ls-=dp[w];
            }
            if(ls)ww[i][j-1]=0;
        }
    }
    int fl=0;
    F0R(i,n)fl|=ww[0][i];
    cout<<(fl?'T':'N')<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}