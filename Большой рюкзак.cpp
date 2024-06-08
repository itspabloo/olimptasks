// У вас есть N предметов с весами w1,w2,…,wN. Требуется проверить, можно ли выбрать некоторые предметы, суммарный вес которых равен W.

#include <bits/stdc++.h>//бесполезный комментарий code by pabL0
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fasttype ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb push_back
#define pf push_front
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (ll)a.size()
#define ff first
#define ss second
#define MOD (ll)1e9 + 7;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld; 
using namespace __gnu_pbds;
using namespace std;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const string NO = "NO\n";
const string YES = "YES\n";
const ll inf = (ll)1e15;

template <typename X, typename Y>
istream &operator>>(istream &in, pair<X, Y> &a) {
    in >> a.ff >> a.ss;
    return in;
}

template <typename X, typename Y>
ostream &operator<<(ostream &out, pair<X, Y> &a) {
    out << a.ff << ' ' << a.ss;
    return out;
}

template <typename T>
istream &operator>>(istream &in, vector<T> &a) {
    for (auto &x : a) in >> x;
    return in;
}

template <typename T>
ostream &operator<<(ostream &out, vector<T> &a) {
    for (auto &x : a) out << x <<' ';
    return out;
}

bitset<10000000> dp;

void Solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    cin >> a;
    dp[0] = true;
    for (ll i = 0; i < n; ++i) {
        dp |= (dp << a[i]);
    }
    cout << (dp[k] ? YES : NO);
    return;
}

signed main() {
    fasttype;
    int t = 1;
    // cin >> t;
    while (t--) Solve();
    return 0;
}
