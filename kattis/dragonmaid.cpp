#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define qb pop_back
#define ph push_heap
#define qh pop_heap

using ll = long long;
using vll = vector<ll>;
using hs = unordered_set<ll>;
using hm = unordered_map<ll,vll>;
const ll INF = 2e5;

int main() {
    ll n,q,p,v,x,k;
    hs keys;
    vll keys2,temp;
    hm items,best;

    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>p>>v;
        keys.insert(v);
        if (items.find(v) == items.end()) items[v] = vll();
        items[v].pb(i-INF*p);
    }
    for (ll i:keys) keys2.pb(i);
    sort(keys2.begin(),keys2.end());
    for (int i=0;i<keys2.size();i++) {
        vll temp2;
        for (ll j:items[keys2[i]]) {
            temp.pb(j);
            ph(temp.begin(),temp.end());
            if (temp.size() > 10) {
                qh(temp.begin(),temp.end()); temp.qb();
            }
        }
        for (ll j:temp) temp2.pb(j);
        sort(temp2.begin(),temp2.end());
        best[i] = temp2;
    }
    cin>>q;
    vector<tuple<int,ll,ll>> queries;
    vector<string> ans[q];
    for (int i=0;i<q;i++) ans[i].pb("-1");
    for (int i=0;i<q;i++) {
        cin>>x>>k;
        queries.pb({i,x,k});
    }
    sort(queries.begin(),queries.end(),[](const tuple<int,ll,ll>& a,
    const tuple<int,ll,ll>& b) -> bool {return get<1>(a) < get<1>(b);});
    int j = -1; keys2.pb(1e18);
    for (const auto& [i,x,k]:queries) {
        while (x >= keys2[j+1]) j++;
        if (j<0 || best[j].empty()) continue;
        ans[i] = vector<string>();
        for (int z=0;z<min(k,(ll)best[j].size());z++) {
            ans[i].pb(to_string(best[j][z] % INF < 0 ? best[j][z] % INF + INF : best[j][z] % INF));
        }
    }
    for (int i=0;i<q;i++) {
        for (string j:ans[i]) cout<<j<<" "; cout<<"\n";
    }
}