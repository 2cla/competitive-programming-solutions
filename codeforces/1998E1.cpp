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
    ll n,x;cin>>n>>x;
    vl arr(n);F0R(i,n)cin>>arr[i];
    if(n==1){
        cout<<"1\n";return;
    }
    if(n==2){
        if(arr[0]<arr[1]||arr[1]<arr[0])cout<<"1\n";
        else cout<<"2\n";
        return;
    }
    vl pre=arr;
    FOR(i,1,n)pre[i]+=pre[i-1];
    vl i1(n),i2(n);pq<pl>dd;
    F0R(i,n-2){
        auto it=prev(lb(all(pre),arr[i]+pre[i]));
        if(it-pre.begin()>=i+1)dd.push({it-pre.begin(),i+1});
    }
    set<ll>ww;
    FORd(i,2,n){
        while(!dd.empty()&&dd.top().f>=i-1){
            ww.ins(dd.top().s);dd.pop();
        }
        auto it=next(ub(all(pre),pre[i-1]-arr[i]));
        auto it2=ww.lb(it-pre.begin());
        if(it2!=ww.end()&&i-1>=*it2){
            i1[*it2]++;i2[i-1]++;
        }
    }
    vl ans(n,1);ll ctr=0;
    F0R(i,n){
        ctr+=i1[i];
        if(ctr)ans[i]=0;
        ctr-=i2[i];
    }
    ll w=0,pp=-1;
    F0R(i,n-1){
        w+=arr[i];
        if(w<arr[i+1]){
            pp=i;
            
        }
    }
    F0R(j,pp+1)ans[j]=0;
    w=0,pp=n;
    FORd(i,1,n){
        w+=arr[i];
        if(w<arr[i-1]){
            pp=i;
        }
    }
    FOR(j,pp,n)ans[j]=0;
    cout<<accumulate(all(ans),0)<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}