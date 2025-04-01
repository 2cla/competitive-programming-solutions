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
    int n;cin>>n;
    vi arr(n),brr(n),crr(n);
    F0R(i,n)cin>>arr[i];F0R(i,n)cin>>brr[i];F0R(i,n)cin>>crr[i];
    vi ans1(n+1,-1),ans2(n+1,-1);
    pqg<pi>h1,h2,h3;
    F0R(i,n)h1.push({arr[i],i+1});F0R(i,n)h2.push({brr[i],i+1});F0R(i,n)h3.push({crr[i],i+1});
    pqg<int>qq;qq.push(1);
    while(!qq.empty()){
        int tt=qq.top();
        while(!h1.empty()&&h1.top().f<arr[tt-1]){
            if(tt<h1.top().s){
                qq.push(h1.top().s);
                if(ans1[h1.top().s]==-1){
                    ans1[h1.top().s]=tt;
                    ans2[h1.top().s]=0;
                }
            }
            h1.pop();
        }
        while(!h2.empty()&&h2.top().f<brr[tt-1]){
            if(tt<h2.top().s){
                qq.push(h2.top().s);
                if(ans1[h2.top().s]==-1){
                    ans1[h2.top().s]=tt;
                    ans2[h2.top().s]=1;
                }   
            }
            h2.pop();
        }
        while(!h3.empty()&&h3.top().f<crr[tt-1]){
            if(tt<h3.top().s){
                qq.push(h3.top().s);
                if(ans1[h3.top().s]==-1){
                    ans1[h3.top().s]=tt;
                    ans2[h3.top().s]=2;
                }
            }
            h3.pop();
        }
        qq.pop();
    }
    if(ans1[n]==-1){
        cout<<"no\n";return;
    }
    vpi st;
    int curr=n;
    while(curr!=1){
        st.pb({ans2[curr],curr});
        curr=ans1[curr];
    }
    cout<<"yes\n";
    cout<<sz(st)<<'\n';
    string tmp="qkj";
    F0Rd(i,sz(st)){
        cout<<tmp[st[i].f]<<' '<<st[i].s<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}