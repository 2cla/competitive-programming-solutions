// I AM A PURE
#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
    #define debug(...) 0x0d010F2C
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef unordered_map<int,int> umi;
typedef unordered_map<ll,ll> uml;
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define F0R(i,a) for(int i=0;i<(a);i++)
#define FORd(i,a,b) for(int i=(b)-1;i>=a;i--)
#define F0Rd(i,a) for(int i=(a)-1;i>=0;i--)
#define trav(a,x) for(auto& a:x)
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
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
#define prt(x) trav(a,x)cout<<a<<' ';cout<<'\n';
#define clz __builtin_clz
#define pct __builtin_popcount
#define YES cout<<"yes\n"
#define NO cout<<"no\n"
#define dbg debug

const ll mod=998244353;
// const ll mod=1e9+7;
const int dx[4]{1,0,-1,0},dy[4]{0,1,0,-1};
ll pow(ll a,ll b,ll p=mod){a%=p;ll r=1%p;while(b){if(b&1)r=r*a%p;a=a*a%p;b>>=1;}return r;}
ll inv(ll x,ll p=mod){return pow(x,p-2,p);}
ll add(ll a,ll b){return (a+b)%mod;}
ll mul(ll a,ll b){return (a*b)%mod;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vi ppp;
vi eulerWalk(vector<vector<pi>>& gr, int nedges, int src=0) {
	int n = sz(gr);
	vi D(n), its(n), eu(nedges), ret, s = {src};
	D[src]++; // to allow Euler paths, not just cycles
	while (!s.empty()) {
		int x = s.back(), y, e, &it = its[x], end = sz(gr[x]);
		if (it == end){ ret.push_back(x); s.pop_back(); continue; }
		tie(y, e) = gr[x][it++];
		if (!eu[e]) {
			D[x]--, D[y]++;
			eu[e] = 1; s.push_back(y);
		}}
	for (int x : D) if (x < 0 || sz(ret) != nedges+1) return {};
	return {ret.rbegin(), ret.rend()};
}
void solve(){
    int n;cin>>n;
    int lo=1,hi=2e3;
    while(lo<hi){
        int mid=(lo+hi)/2;
        if((mid*(mid+1))/2<n-1){
            lo=mid+1;
        }else if(!(mid&1)&&mid*mid/2<n-2){
            lo=mid+1;
        }else hi=mid;
    }
    vector<vpi>gr(lo);
    int cc=0,dd=0;
    F0R(i,lo){
        F0R(j,i+1){
            if(!(lo&1)){
                if(j+lo/2==i){
                    if(dd)continue;
                    dd++;
                }
            }
            gr[i].pb({j,cc});
            gr[j].pb({i,cc});
            cc++;
        }
    }
    vi ww=eulerWalk(gr,cc);
    F0R(i,n){
        cout<<ppp[ww[i]]<<' ';
    }cout<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    // t=1;
    int N=2e4;
    vi pp(N+1,1);
    FOR(i,2,N){
        if(!pp[i])continue;
        int j=2;
        while(i*j<=N){
            pp[i*j]=0;j++;
        }
    }
    FOR(i,2,N){
        if(pp[i])ppp.pb(i);
    }
    cin>>t;
    while(t--)solve();
    return 0;
}