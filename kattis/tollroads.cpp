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
typedef unordered_set<int> usi;
 
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

void build(int n,vi &par,vi &size,vector<usi> &sets){
    F0R(i,n){
        par.pb(i);sets[i].insert(i);
    }
}
int find(vi &par,int x){
    if(par[x]==x)return x;
    par[x]=find(par,par[x]);
    return par[x];
}
int getsize(vi &par,vi &size,int x){
    return size[find(par,x)];
}
vpi join(vi &par,vi &size,vector<usi> &sets,vector<vpi> &qs,int a,int b){
    int ca=find(par,a),cb=find(par,b);
    if(ca==cb)return {};
    vpi tmp;
    if(size[ca]>=size[cb]){
        par[cb]=ca;size[ca]+=size[cb];
        trav(k,sets[cb]){
            trav(kk,qs[k]){
                if(sets[ca].count(kk.f))tmp.pb(kk);
            }
        }
        trav(k,sets[cb])sets[ca].insert(k);
    }else{
        par[ca]=cb;size[cb]+=size[ca];
        trav(k,sets[ca]){
            trav(kk,qs[k]){
                if(sets[cb].count(kk.f))tmp.pb(kk);
            }
        }
        trav(k,sets[ca])sets[cb].insert(k);
    }
    return tmp;
}
void solve(){
    int n,m,q;cin>>n>>m>>q;
    vector<tuple<int,int,int>>es;
    es.pb({1e9,-1,-1});
    F0R(_,m){
        int u,v,t;cin>>u>>v>>t;u--;v--;
        es.pb({t,u,v});
    }
    sort(all(es));
    vector<vpi>qs(n);
    F0R(i,q){
        int a,b;cin>>a>>b;a--;b--;
        qs[a].pb({b,i});qs[b].pb({a,i});
    }
    vi ans1(q),ans2(q);
    vi par,size(n,1);
    vector<usi>sets(n);
    build(n,par,size,sets);
    vector<vpi>mexp(2e5+5);
    F0R(i,m){
        auto[t,a,b]=es[i];
        vpi d=join(par,size,sets,qs,a,b);
        trav(k,d)mexp[t].pb(k);
        if(get<0>(es[i+1])>t){
            trav(qu,mexp[t]){
                ans1[qu.s]=t;ans2[qu.s]=getsize(par,size,qu.f);
            }
        }
    }
    F0R(i,q){
        cout<<ans1[i]<<' '<<ans2[i]<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}