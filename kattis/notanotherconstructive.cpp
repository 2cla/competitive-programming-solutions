#include <bits/stdc++.h>

using namespace std;

int n, k;
string s;
bitset<2502> vis[41][41][41*41/4]; 
string ans;

void solve(int idx, int ns, int nas, int nacs) {
    if (nacs+380*(40-idx)<k || nacs > k) return;
    if (idx == n) {
        if (nacs == k) {
            cout << ans << endl;
            exit(0);
        } 
        return;
    }
    if (vis[idx][ns][nas][nacs]) return;
    vis[idx][ns][nas][nacs] = true;
    if (s[idx] != '?') {
        ans.push_back(s[idx]);
        switch (s[idx]) {
            case 'N': 
                solve(idx + 1, ns + 1, nas, nacs);
                break;
            case 'A':
                solve(idx + 1, ns, nas + ns, nacs);
                break;
            case 'C':
                solve(idx + 1, ns, nas, nacs + nas);
                break;
            default: 
                solve(idx + 1, ns, nas, nacs);
                break;
        }
        ans.pop_back();
    }
    else {
        ans.push_back('X');
        solve(idx + 1, ns, nas, nacs);
        ans.pop_back();

        ans.push_back('N');
        solve(idx + 1, ns + 1, nas, nacs);
        ans.pop_back();

        ans.push_back('A');
        solve(idx + 1, ns, nas + ns, nacs);
        ans.pop_back();

        ans.push_back('C');
        solve(idx + 1, ns, nas, nacs + nas);
        ans.pop_back();
    }
}
int main() {
    cin >> n >> k;
    cin >> s;
    solve(0, 0, 0, 0);
    cout << -1 << endl;
}