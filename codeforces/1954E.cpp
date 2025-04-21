#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
using namespace __gnu_pbds;
 
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
typedef unordered_map<ll,ll> uml;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
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
	typedef pl T;
	static constexpr T unit = {1e9,-1};
	T f(T a, T b) {
        return min(a,b);
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
    ll n;cin>>n;
    vl arr(n);
    ll mm=0;
    F0R(i,n){
        cin>>arr[i];mm=max(mm,arr[i]);
    }
    Tree st(n);
    F0R(i,n)st.update(i,{arr[i],i});
    vl pre(mm+1);
    stack<pair<pl,ll>>stt;stt.push({{0,n-1},0});
    while(!stt.empty()){
        pair<pl,ll>tt=stt.top();stt.pop();
        pl ww=st.query(tt.f.f,tt.f.s+1);
        pre[tt.s]++;pre[ww.f]--;
        if(tt.f.f<=ww.s-1)stt.push({{tt.f.f,ww.s-1},ww.f});
        if(ww.s+1<=tt.f.s)stt.push({{ww.s+1,tt.f.s},ww.f});
    }
    FOR(i,1,mm+1)pre[i]+=pre[i-1];
    vl ans(mm+1);
    FOR(i,1,mm+1){
        ll j=0;
        while(i*j<=mm){
            ans[i]+=pre[i*j];j++;
        }
    }
    FOR(i,1,mm+1)cout<<ans[i]<<' ';
    cout<<'\n';
}
int main(){
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}