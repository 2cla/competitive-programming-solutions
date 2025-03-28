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
#define all(x) begin(x), end(x)
#define ins insert
#define print(x) trav(a,x)cout<<a<<' ';cout<<'\n';

const ll MOD=(int)1e9+7;
ll add(ll a,ll b){
    return (a+b)%MOD;
}
ll mult(ll a,ll b){
    return (a*b)%MOD;
}
void solve(){
    string ss;cin>>ss;
    int n=sz(ss);
    unordered_map<char,int>vows{{'a',0},{'e',1},{'i',2},{'o',3},{'u',4},{'A',5},{'E',6},{'I',7},{'O',8},{'U',9}};
    unordered_map<char,int>cons;
    int j=0;
    FOR(i,65,123){
        if(i>90&&i<97)continue;
        if(!vows.count((char)i)){
            cons[(char)i]=j;j++;
        }
    }
    ll pre1[n+1][10],pre2[n+1][10][42],suf1[10],suf2[10][42];
    ll s1[n+1][10],s2[n+1][42],s3[10],s4[42];
    ll dp[5];
    memset(pre1,0,sizeof(pre1));
    memset(pre2,0,sizeof(pre2));
    memset(suf1,0,sizeof(suf1));
    memset(suf2,0,sizeof(suf2));
    memset(s1,0,sizeof(s1));
    memset(s2,0,sizeof(s2));
    memset(s3,0,sizeof(s3));
    memset(s4,0,sizeof(s4));
    memset(dp,0,sizeof(dp));
    F0R(i,n){
        F0R(j,10){
            s1[i+1][j]=s1[i][j];
            pre1[i+1][j]=pre1[i][j];
            F0R(k,42){
                pre2[i+1][j][k]=pre2[i][j][k];
            }
        }
        F0R(k,42)s2[i+1][k]=s2[i][k];
        if(vows.count(ss[i])){
            int tmp=vows[ss[i]];
            dp[4]=add(dp[3],dp[4]);dp[2]=add(dp[1],dp[2]);dp[0]++;
            pre1[i+1][tmp]++;
        }else{
            int tmp=cons[ss[i]];
            dp[3]=add(dp[3],dp[2]);dp[1]=add(dp[1],dp[0]);
            F0R(j,10){
                pre2[i+1][j][tmp]=add(pre2[i+1][j][tmp],pre1[i][j]);
                s1[i+1][j]=add(s1[i+1][j],pre1[i][j]);
                s2[i+1][tmp]=add(s2[i+1][tmp],pre1[i][j]);
            }
        }
    }
    ll ans=dp[4];
    F0Rd(i,n){
        char c=ss[i];
        if(vows.count(c)){
            int tt=vows[c];
            ll lt=accumulate(all(s1[i]),0ll);
            ll rt=accumulate(all(s3),0ll);
            ans+=MOD-mult(s1[i][tt],rt);
            ans+=MOD-mult(s3[tt],lt);
            F0R(j,10){
                ans+=MOD-mult(s1[i][j],s3[j]);
            }
            F0R(j,42){
                ans+=MOD-mult(s2[i][j],s4[j]);
            }
            ans+=2*mult(s1[i][tt],s3[tt]);
            F0R(j,42){
                ans+=mult(pre2[i][tt][j],s4[j]);
                F0R(k,10){
                    ans+=mult(pre2[i][k][j],suf2[k][j]);
                }
                ans+=mult(s2[i][j],suf2[tt][j]);
                ans+=2*(MOD-mult(pre2[i][tt][j],suf2[tt][j]));
            }
            ans%=MOD;
            suf1[tt]++;
        }else{
            int tt=cons[ss[i]];
            F0R(j,10){
                suf2[j][tt]=add(suf2[j][tt],suf1[j]);
                s3[j]=add(s3[j],suf1[j]);
                s4[tt]=add(s4[tt],suf1[j]);
            }
        }
    }
    cout<<ans<<'\n';

}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}