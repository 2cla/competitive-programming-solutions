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

void solve(){
    ll n;cin>>n;
    vl arr(n);F0R(i,n)cin>>arr[i];
    vl ans(n);ll aa=0,t1=0,t2=0;
    vector<vpl>lt(n),rt(n);
    vpl wt(n);
    stack<pl>st;
    F0Rd(i,n){
        pl tt={arr[i],1};
        while(!st.empty()&&st.top().f>=arr[i]){
            t1-=st.top().f*st.top().s;
            tt.s+=st.top().s;
            rt[i].pb({st.top().f,-st.top().s});
            st.pop();
        }
        st.push(tt);
        wt[i].s=tt.s-1;
        t1+=tt.f*tt.s;
        aa+=t1;
        ans[i]-=t1;
    }
    st=stack<pl>();
    F0R(i,n){
        pl tt={arr[i],1};
        while(!st.empty()&&st.top().f>=arr[i]){
            t2-=st.top().f*st.top().s;
            tt.s+=st.top().s;
            lt[i].pb(st.top());
            st.pop();
        }
        st.push(tt);
        wt[i].f=tt.s-1;
        t2+=tt.f*tt.s;
        ans[i]-=t2;
    }
    F0R(i,n){
        ans[i]-=arr[i]*(wt[i].f*wt[i].s-1);
        pqg<pl>ww;
        trav(a,lt[i])ww.push(a);
        trav(a,rt[i])ww.push(a);
        while(!ww.empty()){
            if(ww.top().s<0){
                ans[i]+=ww.top().f*(-ww.top().s)*wt[i].f;
                wt[i].s+=ww.top().s;
            }else{
                ans[i]+=ww.top().f*ww.top().s*wt[i].s;
                wt[i].f-=ww.top().s;
            }
            ww.pop();
        }
    }
    F0R(i,n)cout<<ans[i]+aa<<' ';cout<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}