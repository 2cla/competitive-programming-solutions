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

const ll NMAX=200000;
const ll MOD=998244353;
vector<vector<pl>>pfl(NMAX+1);
vector<vl>primelist(NMAX+1);
vector<vector<ll>>g;
map<pl,pl>rat;
ll ans;
ll pow(ll x,ll y,ll m){
    if(!y)return 1;
    ll p=pow(x,y/2,m)%m;
    p=(p*p)%m;
    if(!(y%2))return p;
    return (x*p)%m;
}
map<ll,ll> rec(ll u,ll prev){
    map<ll,ll>tmp;
    if(sz(g[u])==1)return tmp;
    trav(a,g[u]){
        if(a==prev)continue;
        pl r=rat[{u,a}];
        vector<pl>pfx=pfl[r.f],pfy=pfl[r.s];
        map<ll,ll>tmp2=rec(a,u);
        trav(b,pfy){
            tmp2[b.f]=max(tmp2[b.f],b.s);
            tmp2[b.f]-=b.s;
        }
        trav(b,pfx){
            tmp2[b.f]+=b.s;
        }
        if(tmp.size()<tmp2.size())swap(tmp,tmp2);  
        trav(a,tmp2){
            tmp[a.f]=max(tmp[a.f],a.s);
        }
    }
    return tmp;
}
void rec2(ll rv,ll u,ll prev){
    ans=(ans+rv)%MOD;
    if(sz(g[u])==1)return;
    trav(a,g[u]){
        if(a==prev)continue;
        pl r=rat[{u,a}];
        ll tmp=(pow(r.f,MOD-2,MOD)*rv)%MOD;
        rec2((tmp*r.s)%MOD,a,u);
    }
}
void solve(){
    int n;cin>>n;
    g=vector<vector<ll>>(n);
    rat=map<pl,pl>();
    F0R(_,n-1){
        ll i,j,x,y;cin>>i>>j>>x>>y;i--;j--;
        ll tmp=gcd(x,y);x/=tmp;y/=tmp;
        g[i].pb(j);g[j].pb(i);
        if(n==2){
            cout<<x+y<<'\n';return;
        }
        rat[{i,j}]={x,y};rat[{j,i}]={y,x};
    }
    ll root=0;
    if(sz(g[0])==1)root=g[0][0];
    map<ll,ll>tmp=rec(root,-1);
    ll tmp2=1;
    trav(a,tmp){
        tmp2=(tmp2*pow(a.f,a.s,MOD))%MOD;
    }
    ans=0;
    rec2(tmp2,root,-1);
    cout<<ans%MOD<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    vl primes;
    vb nums(NMAX+1,true);
    FOR(i,2,NMAX+1){
        int j=2;
        while(j*i<=NMAX){
            nums[j*i]=false;j++;
        }
    }
    FOR(i,2,NMAX+1){
        if(nums[i])primes.pb(i);
    }
    trav(a,primes){
        int j=1;
        while(j*a<=NMAX){
            primelist[j*a].pb(a);j++;
        }
    }
    FOR(i,2,NMAX+1){
        int tmp=i;
        trav(a,primelist[i]){
            int j=0;
            while(!(tmp%a)){
                tmp/=a;j++;
            }
            pfl[i].pb({a,j});
        }
    }
    cin>>t;
    while(t--)solve();
    return 0;
}