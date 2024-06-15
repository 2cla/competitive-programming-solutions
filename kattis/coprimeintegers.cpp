#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

struct VectorHasher {
    int operator()(const vector<int> &V) const {
        int hash = V.size();
        for(auto &i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

// Function to calculate the product of prime factors efficiently
int prods(int* te, int n) {
    if (te[n] != 1) return te[n];
    int highest_bit = 1 << (int(log2(n)));
    te[n] = prods(te, n - highest_bit) * te[highest_bit];
    return te[n];
}

// Function implementing the PIE (Principle of Inclusion-Exclusion) logic
ll pie(const unordered_map<vector<int>, int, VectorHasher>& d, int e, int g) {
    ll ans = 0;
    for (const auto& pair : d) {
        const vector<int>& k = pair.first;
        ll v = pair.second;
        ll ta = e - g;
        int te[1 << k.size()];
        for (int i=0; i<1 << k.size();i++) te[i] = 1;
        for (size_t i = 0; i < k.size(); i++) {
            te[1 << i] = k[i];
        }
        for (int i = 1; i < (1 << k.size()); ++i) {
            int t = prods(te, i);
            if (__builtin_popcount(i) & 1) {
                ta -= (e / t) - (g / t);
            } else {
                ta += (e / t) - (g / t);
            }
        }
        ans += ta * v;
    }
    return ans;
}

int main() {
    int a, b, c, f;
    cin >> a >> b >> c >> f;

    const int n = 1e7;
    vector<vector<int>> pfs(n + 1);

    // Sieve of Eratosthenes with prime factor tracking
    for (int p = 2; p <= n; ++p) {
        if (pfs[p].empty()) { // p is prime if its vector is empty
            for (int multiple = p; multiple <= n; multiple += p) {
                pfs[multiple].push_back(p);
            }
        }
    }

    unordered_map<vector<int>, int, VectorHasher> d;
    for (int i = max(2,a); i <= b; ++i) {
        d[pfs[i]]++;
    }
    pfs.clear();
    // Calculate and print the result
    ll bonus = (a == 1) ? (f - c + 1) : 0;
    ll result = pie(d, f, c - 1) + bonus;
    cout << result << endl;
}