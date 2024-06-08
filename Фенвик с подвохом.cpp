// Вам дан массив из n элементов, изначально заполненный нулями. Вам поступают запросы двух типов:
// 1. прибавить ко всем числам на [L:R] число x
// 2. узнать значение i-го элемента.
// Реализуйте дерево Фенвика, которое поддерживает данные операции. Нет, мы не ошиблись. Да, это дерево Фенвика. 
// Да, оно на это способно (а мы верим, что вы способны это придумать). Нет, слишком долго работать не будет. И да, дерево отрезков здесь не зайдет, даже не пытайтесь.

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
        for (ll i = pos; i <= n; i += func(i)) t[i] += x;
        return;
    }

    void change(ll pos) {
        change(pos, 1);
    }

    ll sum(ll l, ll r) {
        return sum(r) - sum(l - 1);
    }

    ll spusk(ll x) {
        ll l = 0, p = (1 << (t.size() - 1));
        for (;p > 0; p /= 2) {
            if (t[l + p] < x) {
                l += p;
                x -= t[p];
            } 
        }
        return l + 1;
    }

    ll check(ll x) {
        ll ans = t[x];
        while (func(x) != 1) {
            x -= func(x);
            ans -= t[x];
        }
        return ans;
    }
};

struct MST {
    ll n;
    vector<vector<int>> t;

    MST(ll _n, vector<int> _a) {
        n = _n;
        t.resize(4 * n + 10);
        build_tree(n, _a, 0, n - 1);
    }

    void build_tree(ll v, vector<int> &a, ll l, ll r) {
        
    }
};

struct F3 {
    ll n;
    vector<ll> t;

    F3(ll _n) {
        n = _n;
        t.resize(4 * n + 10);
    }

    void update(ll i, ll x) {
        for(; i <= n; i = (i | (i + 1))) t[i] += x;
    }
    ll get(ll r){
        ll ans = 0;
        for (;r > 0; r = (r & (r + 1)) - 1) ans += t[r];
        return ans;
    }
};

void Solve() {
    ll n, q;
    cin >> n >> q;
    F3 t(n);
    while(q--) {
        char type;
        cin >> type;
        if (type == '+') {
            ll l, r, x;
            cin >> l >> r >> x;
            t.update(l, x);
            t.update(r + 1, -x);
        } else {
            ll x;
            cin >> x;
            cout << t.get(x) << '\n';
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
