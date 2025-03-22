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
    ll n;cin>>n;
    vb barr(n+1);
    vl marr(n),arr(n);
    ll mex=0;
    F0R(i,n)cin>>arr[i];
    if(n==1){
        cout<<"1\n";return;
    }
    ll j=0;
    F0R(i,n){
        barr[arr[i]]=true;
        while(barr[j])j++;
        mex+=j;
        marr[i]=j;
    }
    j=n-2;ll ans=mex;
    stack<pl> st;
    F0R(i,n){
        ll k=0,tj=j;
        while(!st.empty()&&arr[i]<st.top().f){
            mex-=st.top().f*st.top().s;
            k+=st.top().s;
            st.pop();
        }
        st.push({arr[i],k+1});
        while(j>=0&&marr[j]>=arr[i]){
            mex-=marr[j];j--;
        }
        st.top().s+=tj-j;
        mex+=st.top().f*st.top().s;
        ans=max(ans,mex);
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