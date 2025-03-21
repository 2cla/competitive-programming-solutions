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

const ll MAX=200007;
void solve(){
    ll n,m,q;cin>>n>>m>>q;
    vl arr=vl(n),brr=vl(m);
    F0R(i,n)cin>>arr[i];
    F0R(i,m)cin>>brr[i];
    ll asum=accumulate(all(arr),0ll),bsum=accumulate(all(brr),0ll);
    vb na=vb(MAX),pa=vb(MAX),nb=vb(MAX),pbb=vb(MAX);
    trav(a,arr){
        if(abs(asum-a)<MAX){
            if(asum-a>=0)pa[asum-a]=true;
            else na[a-asum]=true;
        }
    }
    trav(a,brr){
        if(abs(bsum-a)<MAX){
            if(bsum-a>=0)pbb[bsum-a]=true;
            else nb[a-bsum]=true;
        }
    }
    vector<vl>nums(MAX,vl());
    FOR(i,1,MAX){
        int j=1;
        while(j*i<MAX){
            nums[j*i].pb(i);j++;
        }
    }
    F0R(i,q){
        ll x;cin>>x;
        bool neg=(x<0);x=abs(x);
        bool fd=false;
        trav(a,nums[x]){
            if(!neg&&pa[a]&&pbb[x/a]){
                cout<<"yes\n";fd=true;break;
            }
            if(!neg&&na[a]&&nb[x/a]){
                cout<<"yes\n";fd=true;break;
            }
            if(neg&&na[a]&&pbb[x/a]){
                cout<<"yes\n";fd=true;break;
            }
            if(neg&&pa[a]&&nb[x/a]){
                cout<<"yes\n";fd=true;break;
            }
        }
        if(!fd)cout<<"no\n";
    }

}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}