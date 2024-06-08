// Задан массив длины N. А ещё он дал нам M запросов двух типов:
// Присвоить тем элементам на отрезке, которые меньше val, значение val.
// Найти разность максимльного и минимального элементов на отрезке.
// Требуется написать программу, выполняющую эти запросы.

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
    vector<ll> t1;
    vector<ll> lazy;
 
    void build(ll v, ll l, ll r, vector<ll> &a) {
        if (l == r - 1) {
            t[v] = a[l];
            t1[v] = a[l];
            return;
        }
        ll mid = (r + l) / 2;
        build(2 * v, l, mid, a);
        build(2 * v + 1, mid, r, a);
        t[v] = max(t[2 * v], t[2 * v + 1]);
        t1[v] = min(t1[2 * v], t1[2 * v + 1]);
    }
 
    SegTree(ll _n, vector<ll> &a) {
        n = _n;
        t.resize(4 * n);
        t1.resize(4 * n);
        lazy.resize(4 * n, -inf);
        build(1, 0, n, a);
    }
 
    void push(ll v, ll l, ll r) {
        if (lazy[v] != -inf) {
            t[v] = max(lazy[v], t[v]);
            t1[v] = max(lazy[v], t1[v]);
            if (l != r - 1) {
                lazy[2 * v] = max(lazy[v], lazy[v * 2]);
                lazy[2 * v + 1] = max(lazy[v], lazy[v * 2 + 1]);
            }
            lazy[v] = -inf;
        }
    }
 
    void upd(ll v, ll tl, ll tr, ll l, ll r, ll x) {
        push(v, tl, tr);
        if (tl >= r || tr <= l) return;
        if (tl >= l && tr <= r) {
            lazy[v] = x;
            push(v, tl, tr);
            return;
        }
        ll mid = (tr + tl) / 2;
        upd(2 * v, tl, mid, l, r, x);
        upd(2 * v + 1, mid, tr, l, r, x);
        t[v] = max(t[2 * v], t[2 * v + 1]);
        t1[v] = min(t1[2 * v], t1[2 * v + 1]);
    }
 
    ll mx(ll v, ll tl, ll tr, ll l, ll r) {
        push(v, tl, tr);
        if (tl >= r || tr <= l) return -inf;
        if (tl >= l && tr <= r) return t[v];
        ll mid = (tr + tl) / 2;
        return max(mx(2 * v, tl, mid, l, r), mx(2 * v + 1, mid, tr, l, r));
    }
 
    ll mn(ll v, ll tl, ll tr, ll l, ll r) {
        push(v, tl, tr);
        if (tl >= r || tr <= l) return inf;
        if (tl >= l && tr <= r) return t1[v];
        ll mid = (tr + tl) / 2;
        return min(mn(2 * v, tl, mid, l, r), mn(2 * v + 1, mid, tr, l, r));
    }
 
    ll get(ll l, ll r) {
        return mx(1, 0, n, l, r) - mn(1, 0, n, l, r);
    }
};
 
void Solve() {
    ll n, q;
    cin >> n;
    vector<ll> a(n);
    cin >> a;
    SegTree t(n, a);
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        if (s == "ask") {
            ll l, r;
            cin >> l >> r;
            cout << t.get(l - 1, r) << '\n';
        } else {
            ll l, r, x;
            cin >> l >> r >> x;
            t.upd(1, 0, n, l - 1, r, x);
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
