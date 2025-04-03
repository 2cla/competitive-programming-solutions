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

ll vv(ll l){return l/2+(l&1);}
void solve(){
    ll n;cin>>n;
    vl arr(n);F0R(i,n)cin>>arr[i];
    ll mm=*max_element(all(arr));
    vl pre(n+1),pre1(n+1),pre2(n+1);
    map<ll,vl,greater<ll>>idx;
    ll tm=0;
    F0R(i,n){
        idx[arr[i]].pb(i);
        pre[i+1]=pre[i];pre1[i+1]=pre1[i];pre2[i+1]=pre2[i];
        if(arr[i]!=mm)continue;
        if(i&1)pre1[i+1]++;
        else pre2[i+1]++;
        pre[i+1]++;
        tm++;
    }
    ll ctr1=0,ctr2=0,tmp=0,ans=0;set<pl>ints;
    trav(a,idx){
        trav(b,a.s){
            auto it=ints.lb({b,0});
            pl ii={b,b};
            if(it!=ints.end()&&it->f-1==b){
                ll aa=it->f,bb=it->s;
                ii.s=bb;
                if((bb-aa+1)&1){
                    if(aa&1){
                        ctr2-=pre1[bb+1]-pre1[aa];
                        ctr1-=pre[bb+1]-pre[aa];
                    }else{
                        ctr2-=pre2[bb+1]-pre2[aa];
                        ctr1-=pre[bb+1]-pre[aa];
                    }
                }
                tmp-=vv(bb-aa+1);
                ints.erase({aa,bb});
            }
            it=ints.lb({b,0});
            if(it!=ints.begin()&&prev(it)->s+1==b){
                ll aa=prev(it)->f,bb=prev(it)->s;
                ii.f=aa;
                if((bb-aa+1)&1){
                    if(bb&1){
                        ctr2-=pre1[bb+1]-pre1[aa];
                        ctr1-=pre[bb+1]-pre[aa];
                    }else{
                        ctr2-=pre2[bb+1]-pre2[aa];
                        ctr1-=pre[bb+1]-pre[aa];
                    }
                }
                tmp-=vv(bb-aa+1);
                ints.erase({aa,bb});
            }
            tmp+=vv(ii.s-ii.f+1);
            ints.insert(ii);
            if((ii.s-ii.f+1)&1){
                if(ii.f&1){
                    ctr2+=pre1[ii.s+1]-pre1[ii.f];
                    ctr1+=pre[ii.s+1]-pre[ii.f];
                }else{
                    ctr2+=pre2[ii.s+1]-pre2[ii.f];
                    ctr1+=pre[ii.s+1]-pre[ii.f];
                }
            }
        }
        ans=max(ans,mm+tmp+a.f-(ctr1==tm&&ctr2==0));
    }
    cout<<ans<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}