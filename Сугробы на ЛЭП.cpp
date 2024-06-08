// Служба электроснабжения проводит мониторинг уровня снега, лежащего на ЛЭП Нью-Васюки - Москва. Вся ЛЭП разбивается на участки опорами. 
// Снег имеет свойства падать на какой-либо интервал ЛЭП, если там уже лежал какой-либо снег, то высота снежного покрова на этом участке суммируется. 
// Также снег имеет тенденцию таять на участке трассы в результате оттепели, при этом известно, что не бывает сугробов отрицательной высоты. 
// Энергетикам крайне важно уметь узнавать суммарную высоту снежного покрова на некоторых последовательных участках, чтобы знать вероятность обрыва проводов.

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
    vector<ll> lazy;

    SegTree(ll _n) {
        n = _n;
        t.resize(4 * n);
        lazy.resize(4 * n);
    }

    void push(ll v, ll l, ll r) {
        if (lazy[v] != 0) {
            t[v] += lazy[v] * (r - l + 1);
            if (l != r) {
                lazy[2 * v] += lazy[v];
                lazy[2 * v + 1] += lazy[v];
            }
            lazy[v] = 0;
        }
    }

    void update(ll v, ll l, ll r, ll ql, ll qr, ll x) {
        push(v, l, r);
        if (l > r || l > qr || r < ql) return;
        if (l >= ql && r <= qr) {
            lazy[v] += x;
            push(v, l, r);
            return;
        }
        ll m = (l + r) / 2;
        update(2 * v, l, m, ql, qr, x);
        update(2 * v + 1, m + 1, r, ql, qr, x);
        t[v] = t[2 * v] + t[2 * v + 1];
    }

    ll sum(ll v, ll l, ll r, ll ql, ll qr) {
        push(v, l, r);
        if (l > r || l > qr || r < ql) return 0;
        if (l >= ql && r <= qr) return t[v];
        ll m = (l + r) / 2;
        return sum(2 * v, l, m, ql, qr) + sum(2 * v + 1, m + 1, r, ql, qr);
    }

    void upd(ll ql, ll qr, ll x) {
        update(1, 0, n - 1, ql, qr, x);
    }

    ll sum(ll l, ll r) {
        return sum(1, 0, n - 1, l, r);
    }
};
 
void Solve() {
    ll n, q;
    cin >> n >> q;
    SegTree t(n);
    while (q--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll l, r, x;
            cin >> l >> r >> x;
            t.upd(l, r - 1, x);
        } else {
            ll l, r;
            cin >> l >> r;
            cout << t.sum(l, r - 1) << '\n';
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
