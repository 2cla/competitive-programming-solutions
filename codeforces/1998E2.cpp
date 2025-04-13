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
 
//#define sz(x) (int)(x).size()
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

struct node
{
    ll sum;
    ll setAll;
    ll increment;
    bool setAllValid;
    node()
    {
       sum = 0;
       setAllValid = 0;
       increment = 0;
    }
    void Reset()
    {
       setAllValid = increment = 0;
    }
};
 
class segtree
{
    int range;
    vector<node> tree;
public:
    void build(vector<int>& v)
    {
        range = v.size();
        tree.assign(4*range, node());
        build_recur(v, 0, range-1, 0);
    }
    void build_recur(vector<int>& v, int l, int r, int node_no)
    {
        if(l == r){
            if(l < v.size())
                tree[node_no].sum = v[l];
            else tree[node_no].sum = 0;
            return;
        }
        int mid = (l+r)/2;
        build_recur(v, l, mid, 2*node_no + 1);
        build_recur(v, mid + 1, r, 2*node_no + 2);
        tree[node_no].sum = tree[2*node_no + 1].sum + tree[2*node_no + 2].sum;
    }
    ll range_query(int L, int R)
    {
        return range_query_recur(0, 0, range - 1, L, R);
    }
 
    void incUpdate_recur(int node, int l, int r, int& L, int& R, int& X)
    {
        if(r < L || R < l || l >= range)
            return;
        if(L <= l && R >= r)
        {
            tree[node].increment += X;
            return;
        }
        applyAggr(node,l,r);
        int mid = (l+r)/2;
        incUpdate_recur(2*node+1,l,mid,L,R,X);
        incUpdate_recur(2*node+2,mid+1,r,L,R,X);
        applyAggr(2*node+1, l, mid);
        applyAggr(2*node+2, mid+1, r);
        tree[node].sum = tree[2*node+1].sum + tree[2*node+2].sum;
    }
 
    void incUpdate(int L, int R, int X)
    {
        incUpdate_recur(0,0,range-1,L,R,X);
    }
 
    void setUpdate_recur(int node, int l, int r, int& L, int& R, int& X)
    {
        if(r < L || R < l || l >= range)
            return;
        if(L <= l && R >= r)
        {
            tree[node].setAllValid = 1;
            tree[node].setAll = X;
            tree[node].increment = 0;
            return;
        }
        applyAggr(node,l,r);
        int mid = (l+r)/2;
        setUpdate_recur(2*node+1,l,mid,L,R,X);
        setUpdate_recur(2*node+2,mid+1,r,L,R,X);
        applyAggr(2*node+1, l, mid);
        applyAggr(2*node+2, mid+1, r);
        tree[node].sum = tree[2*node+1].sum + tree[2*node+2].sum;
    }
 
    void setUpdate(int L, int R, int X)
    {
        setUpdate_recur(0,0,range-1,L,R,X);
    }
 
    void compose(int par, int child)
    {
        if(tree[par].setAllValid){
            tree[child].setAllValid = 1;
            tree[child].setAll = tree[par].setAll;
            tree[child].increment = tree[par].increment;
        }
        else tree[child].increment += tree[par].increment;
    }
 
    void applyAggr(int node, int l, int r)
    {
        if(tree[node].setAllValid)
            tree[node].sum = (r-l+1)*tree[node].setAll;
 
        tree[node].sum += (r-l+1)*tree[node].increment;
 
        if(l != r){
            compose(node, 2*node + 1);
            compose(node, 2*node + 2);
        }
 
        tree[node].Reset();
    }
 
    ll range_query_recur(int node, int l, int r, int& L, int& R)
    {
        if(r < L || R < l || l >= range)
            return 0;
        applyAggr(node, l, r);
        if(L <= l && R >= r)
            return tree[node].sum;
        int mid = (l+r)/2;
        return range_query_recur(2*node + 1, l, mid, L, R) + range_query_recur(2*node + 2, mid+1, r, L, R);
    }
};
void solve(){
    ll n,x;cin>>n>>x;
    vl arr(n);F0R(i,n)cin>>arr[i];
    if(n==1){
        cout<<"1\n";return;
    }
    if(n==2){
        if(arr[0]<arr[1]||arr[1]<arr[0])cout<<"1 1\n";
        else cout<<"1 2\n";
        return;
    }
    vl pre=arr;
    FOR(i,1,n)pre[i]+=pre[i-1];
    vector<vl>gg(n);pq<pl>dd;
    F0R(i,n-2){
        auto it=prev(lb(all(pre),arr[i]+pre[i]));
        if(it-pre.begin()>=i+1)dd.push({it-pre.begin(),i+1});
    }
    set<ll>ww;
    FORd(i,2,n){
        while(!dd.empty()&&dd.top().f>=i-1){
            ww.ins(dd.top().s);dd.pop();
        }
        auto it=next(ub(all(pre),pre[i-1]-arr[i]));
        auto it2=ww.lb(it-pre.begin());
        if(it2!=ww.end()&&i-1>=*it2){
            gg[i].pb(*it2);
        }
    }
    vi ans(n),tmp(n,1),t1(n),t2(n);
    segtree st;st.build(tmp);
    ll w=0;
    F0R(i,n-1){
        w+=arr[i];
        if(w<arr[i+1]){
            t1[i+1]=1;
        }
    }
    int ss=0;
    FOR(i,1,n){
        while(pre[i]-pre[ss]>=arr[ss])ss++;
        t2[i]=ss;
    }
    F0R(i,n){
        trav(a,gg[i])st.setUpdate(a,i-1,0);
        if(t1[i])st.setUpdate(0,i-1,0);
        ans[i]=st.range_query(0,t2[i]);
    }
    print(ans)
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}