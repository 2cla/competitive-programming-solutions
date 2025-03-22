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

int n;
vi pre;
int calc(int mid,int i){
    int j=1;
    int tmp=pre[mid];
    while(mid+j*i<=n){
        tmp+=pre[mid+j*i]-pre[j*i-1];j++;
    }
    if(j*i-1<n)tmp+=pre[n]-pre[j*i-1];
    return tmp;
}
void solve(){
    int q;cin>>n>>q;
    vi arr(n),ans(n+1);ans[1]=0;
    pre=vi(n+1);
    F0R(i,n){
        cin>>arr[i];pre[arr[i]]++;
    }
    FOR(i,1,n+1)pre[i]+=pre[i-1];
    FOR(i,2,n+1){
        int lo=0,hi=i-1;
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(calc(mid,i)>=n/2+1)hi=mid;
            else lo=mid+1;
        }
        ans[i]=lo;
    }
    F0R(i,q){
        int x;cin>>x;
        cout<<ans[x]<<' ';
    }
    cout<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}