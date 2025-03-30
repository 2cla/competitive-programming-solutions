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

const ll MOD=998244353;
const ll N=2e5+10;
vl facts(N);
vl invfacts(N);
vl pws(N);
vl brr(N);
ll pow(ll x,ll y,ll m){
    if(!y)return 1;
    ll p=pow(x,y/2,m)%m;
    p=(p*p)%m;
    if(!(y%2))return p;
    return (x*p)%m;
}
void solve(){
    ll n;cin>>n;
    vl arr(n);F0R(i,n)cin>>arr[i];
    trav(a,arr)brr[a]++;
    ll k=brr[1],l=0;
    stack<pl>st;
    ll ctr=brr[0];
    FOR(i,1,N){
        if(!brr[i])break;
        l=i;
        ctr+=brr[i];
        k=min(k,brr[i]);
        st.push({k,i});
    }
    vl lol(l+2,pws[n-ctr]);
    FORd(i,1,l+1){
        lol[i]=(lol[i+1]*pws[brr[i]])%MOD;
    }
    vl subs(l+1);
    vl ans(brr[0]);
    ll lans=0;
    F0R(i,brr[0]){
        while(!st.empty()&&st.top().f<i+1){
            l=st.top().s-1;st.pop();
        }
        ll tt=pws[n-brr[0]],tt2=1;
        FOR(j,1,l+1){
            ll tmp=(facts[brr[j]]*invfacts[brr[j]-i])%MOD;
            tmp=(tmp*invfacts[i])%MOD;
            subs[j]=(subs[j]+tmp)%MOD;
        }
        FOR(j,1,l+1){
            ll tmp=(MOD+pws[brr[j]]-subs[j])%MOD;
            tt2=(tt2*tmp)%MOD;
            tmp=(tt2*lol[j+1])%MOD;
            tt=(tt+tmp)%MOD;
        }
        lans=(lans+tt)%MOD;
        ans[i]=lans;
    }
    ll aa=0;
    F0R(i,brr[0]){
        ll tmp=(ans[i]*facts[brr[0]])%MOD;
        tmp=(tmp*invfacts[i+1])%MOD;
        tmp=(tmp*invfacts[brr[0]-i-1])%MOD;
        aa=(aa+tmp)%MOD;
    }
    cout<<aa<<'\n';
    trav(a,arr)brr[a]=0;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    facts[0]=1;invfacts[0]=1;
    FOR(i,1,N)facts[i]=(facts[i-1]*i)%MOD;
    invfacts[N-1]=pow(facts[N-1],MOD-2,MOD);
    FORd(i,1,N-1)invfacts[i]=(invfacts[i+1]*(i+1))%MOD;
    pws[0]=1;
    FOR(i,1,N)pws[i]=(pws[i-1]*2)%MOD;
    cin>>t;
    while(t--)solve();
    return 0;
}