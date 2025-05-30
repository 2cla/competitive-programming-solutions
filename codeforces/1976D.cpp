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

void solve(){
    string ss;cin>>ss;
    ll n=sz(ss);
    vector<vl>ww(n+7);ww[0].pb(0);
    set<ll>idk;
    ll ans=0,ctr=0;
    F0R(i,n){
        if(ss[i]=='(')ctr++;
        else ctr--;
        ww[ctr].pb(i+1);
    }
    F0Rd(i,n/2+1){
        trav(a,ww[2*i+1])idk.ins(a);
        trav(a,ww[2*i+2])idk.ins(a);
        ll l=0,r=0;
        while(r<sz(ww[i])){
            if(l==r){
                r++;continue;
            }
            auto it1=idk.lb(ww[i][l]),it2=idk.lb(ww[i][r]);
            if(it1==it2)r++;
            else{
                ans+=r-l-1;l++;
            }
        }
        while(l<sz(ww[i])){
            ans+=r-l-1;l++;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}