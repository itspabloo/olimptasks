// Напишите программу, которая для заданного массива A=⟨a1,a2,…,an⟩ находит количество пар (i,j) таких, что i<j и ai>aj.

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
const string NO = "NO\n";
const string YES = "YES\n";
const ll inf = 1e15;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;

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

struct SegTree {
    ll n;
    vector<ll> t;

    SegTree(ll _n, vector<ll> &a) {
        n = _n;
        t.resize(4 * n);
        build_tree(1, 0, n - 1, a);
    }

    void build_tree(ll v, ll l, ll r, vector<ll> &a) {
        if (l == r) {
            t[v] = a[l];
            return;
        }
        ll m = (l + r) / 2;
        build_tree(2 * v, l, m, a);
        build_tree(2 * v + 1, m + 1, r, a);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }

    ll mx(ll v, ll l, ll r, ll tl, ll tr) {
        if (tl > r || tr < l) return -inf;
        if (tl <= l && r <= tr) return t[v];
        ll m = (l + r) / 2;
        return max(mx(2 * v, l, m, tl, tr), mx(2 * v + 1, m + 1, r, tl, tr));
    }

    void upd(ll v, ll l, ll r, ll p, ll x) {
        if (l > r) return;
        if (l == r) {
            t[v] = x;
            return;
        }
        ll m = (l + r) / 2;
        if (p <= m) upd(2 * v, l, m, p, x);
        else upd(2 * v + 1, m + 1, r, p, x);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }

    ll mx(ll l, ll r) {
        return mx(1, 0, n - 1, l, r);
    }

    void upd(ll p, ll x) {
        upd(1, 0, n - 1, p, x);
    }

    ll find(ll v, ll x, ll l, ll r) {
        if (l == r) return l;
        ll m = (r + l) / 2;
        if (t[v * 2] >= x) return find(v * 2, x, l, m);
        return find(v * 2 + 1, x, m + 1, r);
    }

    ll find_n(ll v, ll x, ll left, ll l, ll r) {
        if (r < left) return -inf;
        if (l >= left) {
            return (t[v] < x ? -inf : find(v, x, l, r));
        }
        ll m = (r + l) / 2;
        ll tmp = find_n(2 * v, x, left, l, m);
        if (tmp != -inf) return tmp; 
        tmp = find_n(2 * v + 1, x, left, m + 1, r);
        if (tmp != inf) return tmp;
        return -inf;
    }
};

void Solve() {
    ll n, ans = 0;
    cin >> n;
    vector<ll> a(n);
    cin >> a;
    ordered_set t;
    for (ll i = n - 1; i >= 0; --i) {
        ans += t.order_of_key(a[i]);
        t.insert(a[i]);
    }
    cout << ans << '\n';
}

signed main() {
    fasttype;
    int t = 1;
    // cin >> t;
    while (t--) Solve();
    return 0;
}
