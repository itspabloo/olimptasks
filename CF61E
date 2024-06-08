// Римляне снова наступают. На этот раз их гораздо больше чем персов, но Шапур готов победить их. Он говорит: «Лев никогда не испугается сотни овец».

// Не смотря на это, Шапур должен найти слабость римской армии чтобы победить ее. Как вы помните, Шапур — математик, поэтому он определяет насколько слаба армии как число — степень слабости.

// Шапур считает, что степень слабости армии равна количеству таких троек i, j, k, что i < j < k и ai > aj > ak, где ax — сила человека, стоящего в строю на месте с номером x. Армия римлян обладает одной особенностью — силы всех людей в ней различны.

// Помогите Шапуру узнать, насколько слаба армия римлян.

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
 
    SegTree(ll _n) : n(_n) {
        t.resize(n * 4, 0);
    }
 
    ll sum(ll v, ll l, ll r, ll ql, ll qr) {
        if (r <= ql || qr <= l) return 0;
        if (ql <= l && r <= qr) return t[v];
        ll m = (l + r) / 2;
        return sum(v * 2, l, m, ql, qr) + sum(v * 2 + 1, m, r, ql, qr);
    }
 
    void update(ll v, ll l, ll r, ll pos, ll val) {
        if (r <= pos || pos < l) return;
        if (l + 1 == r) {
            t[v] += val;
            return;
        }
        ll m = (l + r) / 2;
        update(v * 2, l, m, pos, val);
        update(v * 2 + 1, m, r, pos, val);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
 
    ll sum(ll x) {
        return sum(1, 0, n, 0, x);
    }
 
    void update(ll x) {
        update(1, 0, n, x, 1);
    }
 
    void update(ll pos, ll x) {
        update(1, 0, n, pos, x);
    }
};
 
void compression(vector<ll> &a) {
    auto b = a;
    sort(all(b));
    unordered_map<ll, ll> mp;
    b.erase(unique(all(b)), b.end());
    for (ll i = 0; i < a.size(); ++i) {
        mp[b[i]] = i;
    }
    for (auto &x : a) x = mp[x];
    return;
}
 
void Solve() {
    ll n, ans = 0;
    cin >> n;
    vector<ll> a(n);
    cin >> a;
    SegTree t(n + 10), t1(n + 10);
    compression(a);
    for (ll i = n - 1; i >= 0; --i) {
        ans += t1.sum(a[i]);
        t1.update(a[i], t.sum(a[i]));
        t.update(a[i]);
    }
    cout << ans << '\n';
    return;
}
 
 
signed main() {
    fasttype;
    int t = 1;
    // cin >> t;
    while (t--) Solve();
    return 0;
}
