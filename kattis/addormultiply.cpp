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

const ll MOD=(ll)1e9+7;
struct Tree {
	typedef ll T;
	static constexpr T unit=1;
	T f(T a, T b) {return (a*b)%MOD;
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
    int n,m;cin>>n>>m;
    string ss;cin>>ss;
    vpi ints={{0,0}},mints={{0,0}};
    Tree st=Tree(n);
    F0R(i,2*n-1){
        if(i&1){
            if(ss[i]=='+'){
                ints.pb({1+(i>>1),1+(i>>1)});
                mints.back().s=1+(i>>1);
            }else{
                mints.pb({1+(i>>1),1+(i>>1)});
                ints.back().s=1+(i>>1);
            }
        }else{
            st.update(i>>1,stoll(string(1,ss[i])));
        }
    }
    set<pi>its(all(ints)),mits(all(mints));
    ll ans=0,mans=0;
    trav(a,its){
        ans=(ans+st.query(a.f,a.s+1))%MOD;
    }
    trav(a,mits){
        mans=(mans+st.query(a.f,a.s+1))%MOD;
    }
    cout<<ans<<'\n';
    F0R(i,m){
        cin>>ss;
        if(ss=="s"){
            int i,j;cin>>i>>j;i--;j--;
            ll t1=st.query(i,i+1),t2=st.query(j,j+1);
            auto it1=prev(its.lb({i,1e8}));
            auto it2=prev(its.lb({j,1e8}));
            auto it3=prev(mits.lb({i,1e8}));
            auto it4=prev(mits.lb({j,1e8}));
            ans=(ans+MOD-st.query(it1->f,it1->s+1))%MOD;
            ans=(ans+MOD-st.query(it2->f,it2->s+1))%MOD;
            mans=(mans+MOD-st.query(it3->f,it3->s+1))%MOD;
            mans=(mans+MOD-st.query(it4->f,it4->s+1))%MOD;
            st.update(i,t2);st.update(j,t1);
            ans=(ans+st.query(it1->f,it1->s+1))%MOD;
            ans=(ans+st.query(it2->f,it2->s+1))%MOD;
            mans=(mans+st.query(it3->f,it3->s+1))%MOD;
            mans=(mans+st.query(it4->f,it4->s+1))%MOD;
        }else if(ss=="f"){
            int i;cin>>i;i--;
            auto it1=prev(its.lb({i,1e8}));
            int t1=it1->f,t2=it1->s;
            ans=(ans+MOD-st.query(t1,t2+1))%MOD;
            if(t2>i){
                its.insert({t1,i});
                its.insert({i+1,t2});
                ans=(ans+st.query(t1,i+1))%MOD;
                ans=(ans+st.query(i+1,t2+1))%MOD;
            }else{
                int t3=next(it1)->s;
                its.erase({t2+1,t3});
                its.insert({t1,t3});
                ans=(ans+MOD-st.query(t2+1,t3+1))%MOD;
                ans=(ans+st.query(t1,t3+1))%MOD;
            }
            its.erase({t1,t2});
            it1=prev(mits.lb({i,1e8}));
            t1=it1->f;t2=it1->s;
            mans=(mans+MOD-st.query(t1,t2+1))%MOD;
            if(t2>i){
                mits.insert({t1,i});
                mits.insert({i+1,t2});
                mans=(mans+st.query(t1,i+1))%MOD;
                mans=(mans+st.query(i+1,t2+1))%MOD;
            }else{
                int t3=next(it1)->s;
                mits.erase({t2+1,t3});
                mits.insert({t1,t3});
                mans=(mans+MOD-st.query(t2+1,t3+1))%MOD;
                mans=(mans+st.query(t1,t3+1))%MOD;
            }
            mits.erase({t1,t2});
        }else{
            swap(ans,mans);
            swap(its,mits);
        }
        cout<<ans<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}