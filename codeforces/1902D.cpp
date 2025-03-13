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

void solve(){
    int n,q;cin>>n>>q;
    string s;cin>>s;
    vector<pi> pos=vector<pi>(n+1);
    map<pi,vi> posi;
    pi curr={0,0};posi[{0,0}].pb(0);
    F0R(i,n){
        curr.fir+=(s[i]=='R')-(s[i]=='L');
        curr.sec+=(s[i]=='U')-(s[i]=='D');
        pos[i+1]=curr;posi[curr].pb(i+1);
    }
    F0R(i,q){
        int x,y,l,r;cin>>x>>y>>l>>r;
        pi anc=pos[l-1];
        if(posi.count({x,y})&&(posi[{x,y}][0]<l||posi[{x,y}].back()>=r)){cout<<"yes\n";continue;}
        pi np={pos[r].fir-x+pos[l-1].fir,pos[r].sec-y+pos[l-1].sec};
        if(posi.count(np)){
            auto j=lb(all(posi[np]),l);
            if(j!=posi[np].end()&&*j<=r){cout<<"yes\n";continue;}
        }
        cout<<"no\n";
    }
    
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}