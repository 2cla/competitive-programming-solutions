// I AM A PURE
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
    #define debug(...) 0x0d010F2C
#endif
using namespace std;
using namespace __gnu_pbds;
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
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
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

const ll mod=998244353;
// const ll mod=1e9+7;
const int dx[4]{1,0,-1,0},dy[4]{0,1,0,-1};
ll pow(ll a,ll b,ll p=mod){a%=p;ll r=1%p;while(b){if(b&1)r=r*a%p;a=a*a%p;b>>=1;}return r;}
ll inv(ll x,ll p=mod){return pow(x,p-2,p);}

array<vi, 2> manacher(const string& s) {
	int n = sz(s);
	array<vi,2> p = {vi(n+1), vi(n)};
	FOR(z,0,2) for (int i=0,l=0,r=0; i < n; i++) {
		int t = r-i+!z;
		if (i<r) p[z][i] = min(t, p[z][l+t]);
		int L = i-p[z][i], R = i+p[z][i]-!z;
		while (L>=1 && R+1<n && s[L-1] == s[R+1])
			p[z][i]++, L--, R++;
		if (R>r) l=L, r=R;
	}
	return p;
}
void solve(){
    ll n,q;cin>>n>>q;
    string ss;cin>>ss;
    array<vi,2>pp=manacher(ss);
    vector<vi>pre(52,vi(n+1));
    F0R(i,n){
        if(i&1)pre[2*(ss[i]-97)+1][i+1]=1;
        else pre[2*(ss[i]-97)][i+1]=1;
    }
    FOR(i,1,n+1){
        F0R(j,52)pre[j][i]+=pre[j][i-1];
    }
    F0R(_,q){
        ll l,r;cin>>l>>r;l--;r--;
        int c1=ss[l]-97,c2=ss[l+1]-97;
        if(pre[2*c1][r+1]-pre[2*c1][l]+pre[2*c1+1][r+1]-pre[2*c1+1][l]==r-l+1){
            cout<<"0\n";continue;
        }
        ll ans=((r-l)*(r-l+1))/2-1;
        if(pre[2*c1+(l&1)][r+1]-pre[2*c1+(l&1)][l]+pre[2*c2+((l+1)&1)][r+1]-pre[2*c2+((l+1)&1)][l]==r-l+1){
            ans=((r-l)/2)*((r-l)/2+1);
        }
        if((r-l+1)&1){
            if(pp[1][(r+l)/2]*2+1<r-l+1)ans+=r-l+1;
        }else{
            if(pp[0][(r+l+1)/2]*2<r-l+1)ans+=r-l+1;
        }
        cout<<ans<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    // t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}