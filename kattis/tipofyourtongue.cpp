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

struct tnode1 {
    umi ed;
    int cnt;
    tnode1() {
        cnt = 0;
    }
};
struct tnode2 {
    umi ed;
    int cnt;
    tnode2() {
        cnt = 0;
    }
};
vector<tnode1> t1,t2;
vector<tnode2> t3;
void tinsert1(string ss,vector<tnode1>&trie){
    int idx=0,sidx=0;
    while(sidx<sz(ss)){
        int c=ss[sidx]-65;
        if(!trie[idx].ed.count(c)){
            trie[idx].ed[c]=sz(trie);
            trie.pb(tnode1());
        }
        idx=trie[idx].ed[c];
        trie[idx].cnt++;
        sidx++;
    }
}
void tinsert2(string ss,string tt,vector<tnode2>&trie){
    int idx=0,sidx=0;
    while(sidx<sz(ss)){
        int c=ss[sidx]-65,t=tt[sidx]-65;
        int cc=c*26+t;
        if(!trie[idx].ed.count(cc)){
            trie[idx].ed[cc]=sz(trie);
            trie.pb(tnode2());
        }
        idx=trie[idx].ed[cc];
        trie[idx].cnt++;
        sidx++;
    }
}
int qu1(string ss,vector<tnode1>&trie){
    int idx=0,sidx=0;
    while(sidx<sz(ss)){
        int c=ss[sidx]-65;
        if(!trie[idx].ed.count(c))return 0;
        idx=trie[idx].ed[c];
        sidx++;
    }
    return trie[idx].cnt;
}
int qu2(string ss,string tt,vector<tnode2>&trie){
    int idx=0,sidx=0;
    while(sidx<sz(ss)){
        int c=ss[sidx]-65,t=tt[sidx]-65;
        int cc=c*26+t;
        if(!trie[idx].ed.count(cc))return 0;
        idx=trie[idx].ed[cc];
        sidx++;
    }
    return trie[idx].cnt;
}
void solve(){
    int n,q;cin>>n>>q;
    t1.pb(tnode1());t2.pb(tnode1());t3.pb(tnode2());
    F0R(i,n){
        string ss,tt;cin>>ss;
        tt=ss;reverse(all(tt));
        tinsert1(ss,t1);tinsert1(tt,t2);tinsert2(ss,tt,t3);
    }
    F0R(i,q){
        string o,p,ss;cin>>o>>p>>ss;
        reverse(all(ss));
        int ans=0;
        if(o=="AND"){
            ans+=qu2(p,ss,t3);
        }else if(o=="OR"){
            ans+=qu1(p,t1)+qu1(ss,t2);
            ans-=qu2(p,ss,t3);
        }else{
            ans+=qu1(p,t1)+qu1(ss,t2);
            ans-=2*qu2(p,ss,t3);
        }
        cout<<ans<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}