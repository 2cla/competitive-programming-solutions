#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
using namespace __gnu_pbds;
 
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
typedef unordered_map<ll,ll> uml;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
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
#define clz __builtin_clz

int chk(vector<vi>&bl,vi &ww){
    int n=sz(ww);
    vi wr(6);
    F0Rd(i,n){
        F0R(j,6){
            if(wr[j])continue;
            if(bl[j][i]!=ww[i])wr[j]=1;
        }
        if(accumulate(all(wr),0)==6)return 1;
    }
    return 0;
}
vi inv(vi &ww){
    int n=sz(ww);
    vi tt(n);
    F0R(i,n)tt[i]=n+1-ww[i];
    return tt;
}
int f(int n){
    if(n==1)return 1;
    return n*f(n-1);
}
void solve(){
    int n,k;cin>>n>>k;
    if(k==1){
        if(n==1){
            cout<<"yes\n";
            cout<<"1\n";
            return;
        }
        cout<<"no\n";return;
    }
    if(n<10&&(k>f(n)||k==f(n)-1)){
        cout<<"no\n";return;
    }
    if(k&1){
        if(!(n&1)){
            cout<<"no\n";return;
        }
        vector<vi>bl(6,vi(n));
        iota(all(bl[0]),1);
        int j=1;
        F0R(i,n){
            j-=2;
            if(j<=0)j+=n;
            bl[1][i]=j;
        }
        F0R(i,n){
            int w=3*(n+1)/2;
            bl[2][i]=w-bl[1][i]-bl[0][i];
        }
        cout<<"yes\n";
        F0R(i,3){
            print(bl[i])
        }
        F0R(i,3)bl[i+3]=inv(bl[i]);
        vi tt(n),tt2;
        iota(all(tt),1);
        tt2=inv(tt);
        int ctr=0;
        while(ctr<((k-3)>>1)){
            if(chk(bl,tt)&&chk(bl,tt2)){
                print(tt)print(tt2)
                ctr++;
            }
            next_permutation(all(tt));
            tt2=inv(tt);
        }
    }else{
        cout<<"yes\n";
        vi tt(n),tt2;
        iota(all(tt),1);
        tt2=inv(tt);
        F0R(i,k>>1){
            print(tt)print(tt2)
            next_permutation(all(tt));
            tt2=inv(tt);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}