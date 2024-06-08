// Дан массив из N элементов, нужно научиться находить сумму чисел на отрезке.

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
    vector<ll> t, a;

    Fenwik(ll _n, vector<ll> &_a) {
        n = _n;
        a = _a;
        t.resize(ceil(log2(n + 1)));
        build_tree();
    }

    Fenwik(ll _n) {
        n = _n;
        t.resize(n + 100);
        a.resize(n + 100, 0);
    }

    ll func(ll x) {
        return x & -x;
    }

    void build_tree() {
        for (ll i = 0; i < n; ++i) change(i + 1, a[i]);
    }

    ll sum(ll r) {
        ll ans = 0;
        for (; r > 0; r -= func(r)) ans += t[r];
        return ans;
    }

    void change(ll pos, ll x) {
        for (ll i = pos; i <= n; i += func(i)) t[i] += x - a[pos];
        a[pos] = x;
        return;
    }

    void change(ll pos) {
        change(pos, 1);
    }

    ll sum(ll l, ll r) {
        return sum(r) - sum(l - 1);
    }

    ll find(ll x) {
        ll l = 0, p = (1 << (t.size() - 1));
        for (;p > 0; p /= 2) {
            if (t[l + p] < x) {
                l += p;
                x -= t[p];
            } 
        }
        return l + 1;
    }
};

void Solve() {
    ll n, q;
    cin >> n >> q;
    Fenwik t(n + 1);
    while (q--) {
        char type;
        cin >> type;
        if (type == 'A') {
            ll i, x;
            cin >> i >> x;
            t.change(i, x);
        } else {
            ll l, r;
            cin >> l >> r;
            cout << t.sum(l, r) << '\n';
        }
    }
}


signed main() {
    fasttype;
    int t = 1;
    // cin >> t;
    while (t--) Solve();
    return 0;
}
