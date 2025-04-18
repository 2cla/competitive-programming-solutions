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


void solve(){
    ll n,m,k;cin>>n>>m>>k;
    vpl arr;
    F0R(i,n){
        ll d,a;cin>>d>>a;
        arr.pb({d,a});arr.pb({d+k,0});
    }
    sort(all(arr));
    stack<pl>st;
    ll t=0,ans=0;
    F0R(i,2*n){
        ll tt=arr[i].f,w=0;
        while(!st.empty()&&t<tt){
            if(st.top().f+k<=t){
                st.pop();continue;
            }
            if(!w){
                if(st.top().s>=(tt-t)*m){
                    st.top().s-=(tt-t)*m;
                    ans+=tt-t;t=tt;
                }else{
                    ll tm=(st.top().s/m);
                    w=st.top().s%m;
                    ans+=tm;t+=tm;
                    st.pop();
                }
            }else{
                if(st.top().s>=m-w){
                    st.top().s-=m-w;
                    ans++;t++;w=0;
                }else{
                    w+=st.top().s;
                    st.pop();
                }
            }
        }
        t=tt;
        st.push(arr[i]);
    }
    cout<<ans<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}