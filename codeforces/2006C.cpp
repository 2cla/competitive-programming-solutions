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

struct Tree {
	typedef pi T;
	static constexpr T unit = {2e9,-1};
	T f(T a, T b) {
        int w=-1;
        if(a.f!=b.f&&a.f!=2e9&&b.f!=2e9)w=abs(a.f-b.f);
        if(a.s!=-1){
            if(w==-1)w=a.s;
            else w=gcd(w,a.s);
        }
        if(b.s!=-1){
            if(w==-1)w=b.s;
            else w=gcd(w,b.s);
        }
        return {min(a.f,b.f),w};
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
    int n;cin>>n;
    Tree st(n);
    vi arr(n);F0R(i,n){
        cin>>arr[i];
        st.update(i,{arr[i],-1});
    }
    ll ans=0,j=0,ww=0;
    F0R(i,n){
        while(j<n){
            int tmp=st.query(i,j+1).s;
            if(tmp&(tmp-1))j++;
            else break;
        }
        ans+=n-j;
    }
    vpi tt={{arr[0],1}};
    FOR(i,1,n){
        if(arr[i]==tt[sz(tt)-1].f)tt[sz(tt)-1].s++;
        else tt.pb({arr[i],1});
    }
    F0R(i,sz(tt))ww+=1ll*tt[i].s*(tt[i].s+1)/2;
    cout<<(ans+ww)<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}