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
void comb(int &st,int &en,pi &mid){
    if(mid.f&&st+1>=mid.f){
        st=mid.s;mid={0,0};
    }
    if(mid.s&&en-1<=mid.s){
        en=mid.f;mid={0,0};
    }
    if(st+1>=en){
        en=n+1;st=n;
    }
}
void solve(){
    int m,q;cin>>n>>m>>q;
    int st=0,en=n+1;
    pi mid={0,0};
    if(m==1)st=1;
    if(m==n)en=n;
    if(m>1&&m<n)mid={m,m};
    comb(st,en,mid);
    F0R(i,q){
        int q;cin>>q;
        int ns=st,ne=en;
        pi nmid=mid;
        if(mid.f==q&&mid.s==q){
            ns=1,ne=n;nmid={0,0};
        }else if((mid.f<=q&&q<=mid.s)||q<=st||q>=en){
            ns=max(ns,1);
            ne=min(ne,n);
        }
        if(mid.f&&mid.f>q)nmid.f=mid.f-1;
        if(mid.s&&mid.s<q)nmid.s=mid.s+1;
        if(st&&q>st)ns=st+1;
        if(en!=n+1&&q<en)ne=en-1;
        int ans=0;
        st=ns;en=ne;mid=nmid;
        comb(st,en,mid);
        ans+=st;
        ans+=n+1-en;
        if(mid.f)ans+=mid.s-mid.f+1;
        cout<<ans<<' ';
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