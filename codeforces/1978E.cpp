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

void solve(){
    int n;cin>>n;
    vi arr(n),brr(n);
    string s1,s2;cin>>s1>>s2;
    F0R(i,n){
        arr[i]=s1[i]-48;
        brr[i]=s2[i]-48;
    }
    vi crr=arr,drr=brr;
    F0R(i,n-2){
        if(!crr[i]&&!crr[i+2])drr[i+1]=1;
    }
    F0R(i,n-2){
        if(drr[i]&&drr[i+2])crr[i+1]=1;
    }
    vi pre(n+1);
    F0R(i,n){
        pre[i+1]=pre[i]+crr[i];
    }
    int q;cin>>q;
    F0R(w,q){
        int l,r;cin>>l>>r;l--;r--;
        if(r-l>3){
            int ans=0;
            vi tt(4),tt2(4);
            FOR(j,l,l+4){
                tt[j-l]=arr[j];
                tt2[j-l]=brr[j];
            }
            F0R(i,2){
                if(!tt[i]&&!tt[i+2])tt2[i+1]=1;
            }
            F0R(i,2){
                if(tt2[i]&&tt2[i+2])tt[i+1]=1;
            }
            ans+=tt[0]+tt[1];
            tt=vi(4),tt2=vi(4);
            FOR(j,r-3,r+1){
                tt[j-r+3]=arr[j];
                tt2[j-r+3]=brr[j];
            }
            F0R(i,2){
                if(!tt[i]&&!tt[i+2])tt2[i+1]=1;
            }
            F0R(i,2){
                if(tt2[i]&&tt2[i+2])tt[i+1]=1;
            }
            ans+=tt[2]+tt[3];
            cout<<ans+pre[r-1]-pre[l+2]<<'\n';
        }else{
            vi tt(r-l+1),tt2(r-l+1);
            FOR(j,l,r+1){
                tt[j-l]=arr[j];
                tt2[j-l]=brr[j];
            }
            F0R(i,sz(tt)-2){
                if(!tt[i]&&!tt[i+2])tt2[i+1]=1;
            }
            F0R(i,sz(tt2)-2){
                if(tt2[i]&&tt2[i+2])tt[i+1]=1;
            }
            cout<<accumulate(all(tt),0)<<'\n';
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}