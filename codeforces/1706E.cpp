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

struct Tree {
	typedef int T;
	static constexpr T unit = 0;
	T f(T a, T b) {return max(a,b);
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
void build(int n,vi &par,vi &size,vector<set<int>> &sets){
    F0R(i,n){
        par.pb(i);sets[i].insert(i);
    }
}
int find(vi &par,int x){
    if(par[x]==x)return x;
    par[x]=find(par,par[x]);
    return par[x];
}
int getsize(vi &par,vi &size,int x){
    return size[find(par,x)];
}
void join(vi &par,vi &size,vector<set<int>> &sets,vector<vi> &qs,Tree &st,int a,int b,int t){
    int ca=find(par,a),cb=find(par,b);
    if(ca==cb)return;
    if(size[ca]>=size[cb]){
        par[cb]=ca;size[ca]+=size[cb];
        trav(k,sets[cb]){
            trav(kk,qs[k]){
                if(sets[ca].count(kk)){
                    if(k>kk)st.update(kk,t);
                    else st.update(k,t);
                }
            }
        }
        trav(k,sets[cb])sets[ca].insert(k);
    }else{
        par[ca]=cb;size[cb]+=size[ca];
        trav(k,sets[ca]){
            trav(kk,qs[k]){
                if(sets[cb].count(kk)){
                    if(k>kk)st.update(kk,t);
                    else st.update(k,t);
                }
            }
        }
        trav(k,sets[ca])sets[cb].insert(k);
    }
}
void solve(){
    int n,m,q;cin>>n>>m>>q;
    vector<pi>es;
    F0R(i,m){
        int u,v;cin>>u>>v;u--;v--;
        es.pb({u,v});
    }
    vector<vi>qs(n);
    F0R(i,n-1){
        qs[i].pb(i+1);qs[i+1].pb(i);
    }
    vi par,size(n,1);
    vector<set<int>>sets(n);
    Tree st(n-1);
    build(n,par,size,sets);
    F0R(t,m){
        auto[a,b]=es[t];
        join(par,size,sets,qs,st,a,b,t+1);
    }
    vi ans;
    F0R(i,q){
        int l,r;cin>>l>>r;l--;r--;
        ans.pb(st.query(l,r));
    }
    print(ans)
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}