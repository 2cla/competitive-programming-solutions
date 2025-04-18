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
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ors;
 
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

int c1(vi ii){
    return ii[0]+ii[1]>ii[2];
}
int c2(vi ii){
    if((ii[0]+ii[1]>ii[2])&&(ii[3]+ii[4]>ii[5]))return 1;
    if((ii[0]+ii[2]>ii[3])&&(ii[1]+ii[4]>ii[5]))return 1;
    if((ii[0]+ii[3]>ii[4])&&(ii[1]+ii[2]>ii[5]))return 1;
    if((ii[0]+ii[4]>ii[5])&&(ii[1]+ii[2]>ii[3]))return 1;
    return 0;
}
void solve(){
    int n,q;cin>>n>>q;
    vi arr(n);F0R(i,n)cin>>arr[i];
    vi ans(n);
    int l=0,r=0;
    ors ww;
    set<pi>gg;
    while(l<n){
        while(r<n){
            ww.ins({arr[r],r});
            if(r-l<2){
                r++;continue;
            }
            int it=ww.order_of_key({arr[r],r});
            vpi tmp;
            F0R(i,5){
                if(i+it-2>=0&&i+it-2<sz(ww))tmp.pb(*ww.find_by_order(i+it-2));
            }
            F0R(i,sz(tmp)-2){
                vi tt;
                F0R(j,3)tt.pb(tmp[i+j].f);
                if(sz(tt)==3&&c1(tt))gg.ins(tmp[i+2]);
            }
            if(sz(gg)>3)break;
            if(sz(gg)>1){
                int w1=1e9,w2=-1;
                trav(a,gg){
                    it=ww.order_of_key(a);
                    w1=min(w1,it);w2=max(w2,it);
                }
                if(w2-w1>2)break;
                vpi tmp;
                F0R(i,7){
                    if(i+w2-6>=0&&i+w2-6<sz(ww))tmp.pb(*ww.find_by_order(i+w2-6));
                }
                int fl=0;
                F0R(i,sz(tmp)-5){
                    vi tt;
                    F0R(j,6)tt.pb(tmp[i+j].f);
                    if(sz(tt)==6&&c2(tt))fl=1;
                }
                if(fl)break;
            }
            r++;
        }
        ans[l]=r;
        int it=ww.order_of_key({arr[l],l});
        gg.erase({arr[l],l});
        vpi tmp;
        F0R(i,2){
            if(i+it-2>=0&&i+it-2<sz(ww)){
                tmp.pb(*ww.find_by_order(i+it-2));
            }
        }
        F0R(i,2){
            if(i+it+1>=0&&i+it+1<sz(ww)){
                tmp.pb(*ww.find_by_order(i+it+1));
                gg.erase(tmp[sz(tmp)-1]);
            }
        }
        F0R(i,sz(tmp)-2){
            vi tt;
            F0R(j,3)tt.pb(tmp[i+j].f);
            if(sz(tt)==3&&c1(tt))gg.ins(tmp[i+2]);
        }
        ww.erase({arr[l],l});
        l++;
    }
    F0R(i,q){
        int l,r;cin>>l>>r;l--;r--;
        cout<<((ans[l]<=r)?"yes":"no")<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}