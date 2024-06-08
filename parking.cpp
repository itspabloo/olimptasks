// Hа кольцевой парковке есть n мест пронумерованых от 1до n. 
// Есть два вида событий прибытие машину на парковку и отъезд машины с парковки. 
// Если машина приезжает на парковку, а её место занято, то она едет далее по кругу и встаёт на первое свободное место.

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
 
struct ST {
    ll siz;
    vector<ll> t;
    vector<ll> kid;
    bool pon;
    
    void b_t(ll v, ll lb, ll rb) {
        if (lb == rb) {
            kid[v] = 1;
            return;
        }
        ll mid = (lb + rb) / 2;
        b_t(v * 2, lb, mid);
        b_t(v * 2 + 1, mid + 1, rb);
        kid[v] = kid[v * 2] + kid[v * 2 + 1];
    }
 
    void build_tree(ll _n) {
        t.resize(_n * 4);
        kid.resize(_n * 4);
        b_t(1, 0, _n - 1);
    }
 
    void upd(ll v, ll n, ll lb, ll rb) {
        if (rb < lb) return;
        if (lb == rb) {
            t[v] = 0;
            return;
        }
        ll mid = (rb + lb) / 2;
        if (n <= mid) upd(v * 2, n, lb, mid);
        else upd(v * 2 + 1, n, mid + 1, rb);
        t[v] = t[v * 2] + t[v * 2 + 1];
        return;
    }
 
    ll find(ll l, ll r, ll v, ll lb, ll rb) {
        if (rb < l || lb > r) return -1;
        if (t[v] == kid[v]) return -1;
        if (lb == rb) {
            if (t[v] || lb < l) return -1;
            else t[v] = 1;
            return rb;
        }
        ll mid = (lb + rb) / 2;
        ll ans = -1;
        if (mid >= l) ans = find(l, r, v * 2, lb, mid);
        if (ans == -1) ans = find(l, r, v * 2 + 1, mid + 1, rb);
        t[v] = t[v * 2] + t[v * 2 + 1];
        return ans;
    }
};
 
void Solve() {
    ll n, q;
    cin >> n >> q;
    ST t;
    t.build_tree(n);
    while (q--) {
        ll x;
        string s;
        cin >> s >> x;
        if (s == "enter") {
            ll ans = t.find(x, n, 1, 1, n);
            if (ans == -1) ans = t.find(1, x - 1 , 1, 1, n);
            cout << ans << '\n';
        }
        else t.upd(1, x, 1, n);
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
