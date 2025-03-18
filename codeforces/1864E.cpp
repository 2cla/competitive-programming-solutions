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
#define fir first
#define sec second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const ll mod=998244353;
ll p;
struct tnode {
    int ed[2];
    int cnt;
    tnode() {
        ed[0]=ed[1]=-1;
        cnt = 0;
    }
};
vector<tnode> trie;
void tinsert(ll s){
    int idx=0;
    F0Rd(i,30){
        int e=(s>>i)&1;
        if(trie[idx].ed[e]==-1){
            trie[idx].ed[e]=sz(trie);
            trie.pb(tnode());
        }
        idx=trie[idx].ed[e];
        trie[idx].cnt++;
    }
}
ll pow(ll x,ll y,ll m){
    if(!y)return 1;
    ll p=pow(x,y/2,m)%m;
    p=(p*p)%m;
    if(!(y%2))return p;
    return (x*p)%m;
}
void s2(int idx,int os){
    tnode al=trie[idx];
    if(al.ed[0]==-1&&al.ed[1]==-1){
        p+=1LL*al.cnt*al.cnt*(os+1);return;
    }
    if(al.ed[0]!=-1&&al.ed[1]!=-1){
        p+=1LL*(2*os+3)*trie[al.ed[0]].cnt*trie[al.ed[1]].cnt;
    }
    if(al.ed[0]!=-1)s2(al.ed[0],os);
    if(al.ed[1]!=-1)s2(al.ed[1],os+1);
}
void solve(){
    ll n;cin>>n;
    vl sarr=vl(n);
    F0R(i,n)cin>>sarr[i];
    trie.pb(tnode());
    trav(a,sarr)tinsert(a);
    p=0;ll q=n*n;
    s2(0,0);
    ll tmp=gcd(p,q);
    p/=tmp;q/=tmp;
    p%=mod;q%=mod;
    cout<<(p*pow(q,mod-2,mod))%mod<<'\n';
    trie.clear();
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}