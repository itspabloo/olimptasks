// Вася любит наблюдать за звёздами. Но следить за всем небом сразу ему тяжело. Поэтому он наблюдает только за частью пространства, ограниченной кубом размером n×n×n. 
// Этот куб поделен на маленькие кубики размером 1×1×1. 
// // Во время его наблюдений могут происходить следующие события:
// 1. В каком-то кубике появляются или исчезают несколько звёзд.
// 2. К нему может заглянуть его друг Петя и поинтересоваться, сколько видно звезд в части пространства, состоящей из нескольких кубиков.

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
const ll inf = 1e15;

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
 
struct Fenwik {
    ll n;
    vector<vector<vector<ll>>> t;

    Fenwik(ll _n) {
        n = _n;
        t.resize(n + 5, vector<vector<ll>>(n + 5, vector<ll>(n + 5)));
    }

    ll func(ll x) {
        return x & -x;
    }

    ll sum(ll x, ll y, ll z) {
        ll ans = 0;
        for (ll i = x; i > 0; i -= func(i)) {
            for (ll j = y; j > 0; j -= func(j)) {
                for (ll k = z; k > 0; k -= func(k)) {
                    ans += t[i][j][k];
                }
            }
        }
        return ans;
    }

    void change(ll x, ll y, ll z, ll d) {
        for (ll i = x; i <= n; i += func(i)) {
            for (ll j = y; j <= n; j += func(j)) {
                for (ll k = z; k <= n; k += func(k)) {
                    t[i][j][k] += d;
                }
            }
        }
        return;
    }

    ll sum(ll x1, ll y1, ll z1, ll x2, ll y2, ll z2) {
        return sum(x2, y2, z2) - sum(x1 - 1, y2, z2) - sum(x2, y1 - 1, z2) + sum(x1 - 1, y1 - 1, z2) - (sum(x2, y2, z1 - 1) - sum(x1 - 1, y2, z1 - 1) - sum(x2, y1 - 1, z1 - 1) + sum(x1 - 1, y1 - 1, z1 - 1));
    }
};

void Solve() {
    ll n;
    cin >> n;
    Fenwik t(n + 1);
    ll q;
    while (cin >> q, q != 3) {
        if (q == 1) {
            ll x, y, z, k;
            cin >> x >> y >> z >> k;
            t.change(x + 1, y + 1, z + 1, k);
        } else {
            ll x1, y1, z1, x2, y2, z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            cout << t.sum(x1 + 1, y1 + 1, z1 + 1, x2 + 1, y2 + 1, z2 + 1) << '\n';
        }
    }
    return;
}


signed main() {
    fasttype;
    int t = 1;
    // cin >> t;
    while (t--) Solve();
    return 0;
}
