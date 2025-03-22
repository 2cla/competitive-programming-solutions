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

vector<vi> g;
int rec(int p){
    if(g[p].empty())return 0;
    map<int,int> m;
    int b1=0,b2=0;
    trav(a,g[p]){
        int tmp=rec(a);
        m[tmp]++;b1=max(b1,tmp);
    }
    bool fl=false;
    trav(a,m){
        if(a.f>=b1&&a.s==2)return a.f+1+fl;
        if(a.s){
            if(a.s&1)fl=true;
            m[a.f+1]+=a.s/2;
            b2=max(b2,a.f);
        }
    }
    return b2+1;
}
void solve(){
    int n;cin>>n;
    g=vector<vi>(n+1);
    F0R(i,n-1){
        int q;cin>>q;
        g[q].pb(i+2);
    }
    cout<<rec(1)<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}