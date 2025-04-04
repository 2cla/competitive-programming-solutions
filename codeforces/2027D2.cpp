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

const ll MOD=1e9+7;
struct Tree {
	typedef pl T;
	static constexpr T unit = {0,1e15};
	T f(T a, T b) {
        pl tmp={0,1e15};
        if(a.s>=b.s){
            tmp.f=(tmp.f+b.f)%MOD;tmp.s=b.s;
        }
        if(a.s<=b.s){
            tmp.f=(tmp.f+a.f)%MOD;tmp.s=a.s;
        }
        return tmp;
    }
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) {
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};
void solve(){
    ll n,m;cin>>n>>m;
    vl pre(n+1),arr(n),brr(m);
    F0R(i,n){
        cin>>arr[i];
        pre[i+1]=pre[i]+arr[i];
    }
    F0R(i,m){
        cin>>brr[i];
    }
    vector<Tree>stl(m,Tree(n+1));
    vector<vpl>dp(m,vpl(n+1,{0,1e15}));
    dp[0][0]={1,0};
    F0R(j,m){
        stl[j].update(0,{1,0});
        if(j){
            F0R(i,n)dp[j][i]=dp[j-1][i];
        }
        FOR(i,1,n+1){
            auto it=lb(all(pre),pre[i]-brr[j]);
            pl tmp=stl[j].query(it-pre.begin(),i);tmp.s+=m-j-1;
            if(tmp.s==dp[j][i].s){
                dp[j][i].f=(dp[j][i].f+tmp.f)%MOD;
            }else if(tmp.s<dp[j][i].s){
                dp[j][i]=tmp;
            }
            stl[j].update(i,dp[j][i]);
        }
    }
    ll ctr=0,mm=1e15;
    F0R(j,m){
        if(mm==dp[j][n].s){
            ctr=(ctr+dp[j][n].f)%MOD;
        }else if(mm>dp[j][n].s){
            mm=dp[j][n].s;ctr=dp[j][n].f;
        }
    }
    if(mm>1e14)cout<<"-1\n";
    else cout<<mm<<' '<<ctr<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}