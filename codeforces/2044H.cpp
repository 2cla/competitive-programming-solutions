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
#define fir first
#define sec second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define print(x) trav(a,x)cout<<a<<' ';cout<<'\n';

vector<vl> g1,g2,g3;
void pre(vector<vl> &g){
    ll n=sz(g);
    FOR(i,1,n){
        FOR(j,1,n){
            g[i][j]+=g[i][j-1];
        }
    }
    FOR(i,1,n){
        FOR(j,1,n){
            g[i][j]+=g[i-1][j];
        }
    }
}
void solve(){
    ll n,q;cin>>n>>q;
    g1=vector<vl>(n+1,vl(n+1));
    g2=vector<vl>(n+1,vl(n+1));
    g3=vector<vl>(n+1,vl(n+1));
    F0R(i,n){
        F0R(j,n){
            ll t;cin>>t;
            g1[i+1][j+1]=t;
            g2[i+1][j+1]=(n*i+j+1)*t;
            g3[i+1][j+1]=t*(i+1);
        }
    }
    pre(g1);pre(g2);pre(g3);
    F0R(i,q){
        ll x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        ll ans=g2[x2][y2]-g2[x2][y1-1]-g2[x1-1][y2]+g2[x1-1][y1-1];
        ans-=((x1-1)*n+y1-1-((n-(y2-y1+1))*x1))*(g1[x2][y2]-g1[x2][y1-1]-g1[x1-1][y2]+g1[x1-1][y1-1]);
        ans-=(n-(y2-y1+1))*(g3[x2][y2]-g3[x2][y1-1]-g3[x1-1][y2]+g3[x1-1][y1-1]);
        cout<<ans<<' ';
    }
    cout<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}