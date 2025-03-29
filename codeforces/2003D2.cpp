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

void solve(){
    ll n,m;cin>>n>>m;
    ll N=20;
    vector<vl>tmpls(n);
    F0R(i,n){
        ll l,ww;cin>>l;
        F0R(j,l){
            cin>>ww;tmpls[i].pb(ww);
        }
        N+=l+2;
    }
    vector<vl>arr(N);
    vl brr(N),ans(N);
    vb crr(N);
    ll bb=0;
    F0R(i,n){
        ll j=0,fl=0,sm;
        vl tmp;
        trav(a,tmpls[i]){
            if(a<N){
                crr[a]=1;tmp.pb(a);
            }
        }
        while(fl<2){
            if(!crr[j]){
                if(!fl){
                    sm=j;brr[sm]++;bb=max(bb,sm);
                }else arr[j].pb(sm);
                fl++;
            }
            j++;
        }
        trav(a,tmp)crr[a]=0;
    }
    F0R(i,N)ans[i]=max(1ll*i,bb);
    int k=N-1;queue<ll>qq;
    vb vis(N);
    F0Rd(i,N){
        if(i>k)continue;
        qq.push(i);
        while(!qq.empty()){
            ll mm=qq.front();
            if(!vis[mm]){
                trav(a,arr[mm]){
                    if(brr[a]>1){
                        while(k>=0){
                            ans[k]=max(ans[k],1ll*i);k--;
                        }
                    }
                    ans[a]=max(ans[a],1ll*i);
                    qq.push(a);
                }
            }
            vis[mm]=1;
            qq.pop();
        }
    }
    if(m<N)cout<<accumulate(ans.begin(),ans.begin()+m+1,0ll)<<'\n';
    else cout<<m*(m+1)/2-N*(N-1)/2+accumulate(all(ans),0ll)<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}