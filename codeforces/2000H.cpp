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

const ll N=2e6+5;
set<ll>fl;
vector<set<ll>>ints(N);
struct Tree {
	typedef ll T;
	static constexpr T unit = 1e9;
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
Tree st;
void solve(){
    ll n;cin>>n;
    vl arr(n+1,0);
    F0R(i,n)cin>>arr[i+1];
    set<ll>brr;
    F0R(i,n){
        brr.insert(arr[i]);
        ints[arr[i+1]-arr[i]].insert(arr[i]);
        fl.insert(arr[i+1]-arr[i]);
    }brr.insert(arr[n]);
    trav(ff,fl){
        st.update(ff,*ints[ff].begin());
    }
    ll m;cin>>m;
    F0R(i,m){
        string c;ll x;cin>>c>>x;
        if(c=="+"){
            auto it=brr.lb(x);
            if(it==brr.end()){
                ints[x-*prev(it)].insert(*prev(it));
                fl.insert(x-*prev(it));
                st.update(x-*prev(it),*ints[x-*prev(it)].begin());
            }else{
                ll aa=*it,bb=*prev(it);
                ints[x-bb].insert(bb);
                fl.insert(x-bb);
                st.update(x-bb,*ints[x-bb].begin());
                ints[aa-x].insert(x);
                fl.insert(aa-x);
                st.update(aa-x,*ints[aa-x].begin());
                ints[aa-bb].erase(bb);
                if(ints[aa-bb].empty()){
                    fl.erase(aa-bb);
                    st.update(aa-bb,1e9);
                }else{
                    st.update(aa-bb,*ints[aa-bb].begin());
                }
            }
            brr.insert(x);
        }else if(c=="-"){
            auto it=brr.lb(x);
            if(next(it)==brr.end()){
                ints[x-*prev(it)].erase(*prev(it));
                if(ints[x-*prev(it)].empty()){
                    fl.erase(x-*prev(it));
                    st.update(x-*prev(it),1e9);
                }else{
                    st.update(x-*prev(it),*ints[x-*prev(it)].begin());
                }
            }else{
                ll aa=*next(it),bb=*prev(it);
                ints[x-bb].erase(bb);
                if(ints[x-bb].empty()){
                    fl.erase(x-bb);
                    st.update(x-bb,1e9);
                }else{
                    st.update(x-bb,*ints[x-bb].begin());
                }
                ints[aa-x].erase(x);
                if(ints[aa-x].empty()){
                    fl.erase(aa-x);
                    st.update(aa-x,1e9);
                }else{
                    st.update(aa-x,*ints[aa-x].begin());
                }
                ints[aa-bb].insert(bb);
                fl.insert(aa-bb);
                st.update(aa-bb,*ints[aa-bb].begin());
            }
            brr.erase(x);
        }else{
            ll tt=st.query(x+1,N);
            if(tt>1e8){
                if(brr.empty())cout<<"1 ";
                else cout<<1+*prev(brr.end())<<' ';
            }else{
                cout<<1+tt<<' ';
            }
        }
    }
    cout<<'\n';
    trav(a,fl){
        ints[a].clear();
        st.update(a,1e9);
    }
    fl.clear();
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    st=Tree(N);
    F0R(i,N)st.update(i,1e9);
    while(t--)solve();
    return 0;
}