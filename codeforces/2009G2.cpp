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
	typedef ll T;
	static constexpr T unit = 1e9;
	T f(T a, T b) {return min(a,b);
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
    ll n,k,q;cin>>n>>k>>q;
    vl arr(n);F0R(i,n)cin>>arr[i];
    vl ans(q);
    vector<vl>ls(n+1);
    vector<vpl>rs(n+1);
    F0R(i,q){
        ll l,r;cin>>l>>r;l--;r-=k-1;
        ls[l].pb(i);rs[r].pb({l,i});
    }
    vl tmp;
    F0R(i,n)arr[i]-=i;
    map<ll,ll>ctr;
    F0R(i,k)ctr[arr[i]]++;
    pq<pl>hp;
    trav(a,ctr){
        hp.push({a.s,a.f});
    }
    tmp.pb(k-hp.top().f);
    FOR(i,k,n){
        ctr[arr[i]]++;ctr[arr[i-k]]--;
        hp.push({ctr[arr[i]],arr[i]});
        hp.push({ctr[arr[i-k]],arr[i-k]});
        while(!hp.empty()&&ctr[hp.top().s]!=hp.top().f)hp.pop();
        tmp.pb(k-hp.top().f);
    }
    ll m=sz(tmp);
    Tree st=Tree(m);
    F0R(i,m)st.update(i,tmp[i]);
    vl suf(m+1);
    stack<pl>stk;
    ll rr=0;
    F0Rd(i,m){
        ll tt=1;
        while(!stk.empty()&&stk.top().f>=tmp[i]){
            tt+=stk.top().s;
            rr-=stk.top().f*stk.top().s;
            stk.pop();
        }
        stk.push({tmp[i],tt});
        rr+=tt*tmp[i];
        suf[i]=rr;
        trav(a,ls[i]){
            ans[a]+=rr;
        }
        trav(a,rs[i]){
            ll lrm=st.query(a.f,i);
            if(lrm<=st.query(i,m)){
                ans[a.s]-=(m-i)*lrm;
            }else{
                ll lo=i,hi=m-1;
                while(lo<hi){
                    ll mid=(lo+hi)/2;
                    if(st.query(lo,mid+1)<lrm)hi=mid;
                    else lo=mid+1;
                }
                ans[a.s]-=suf[lo]+(lo-i)*lrm;
            }
        }
    }
    trav(a,ans){
        cout<<a<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}