// Задана строка s длины n и m пар индексов. Для каждой пары индексов ai,bi найдите длину наибольшего общего префикса строк s[ai..n−1] и s[bi..n−1] (индексы указаны включительно).

#include <bits/stdc++.h>//бесполезный комментарий code by pabL0

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define fasttype ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb push_back
#define pf push_front
#define mp make_pair
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (ll)a.size()
#define ff first    
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace __gnu_pbds;
using namespace std;

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const string NO = "NO\n";
const string YES = "YES\n";
const ll inf = 1e15;
const ll MOD = (ll)1e9 + 7;
const ll MOD2 = 998244353;

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
    for (auto &x : a) out << x << ' ';
    cout << '\n';
    return out;
}

ll gen() { 
    static mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
    return (uniform_int_distribution<ll>(0, LLONG_MAX)(rnd)); 
}

ll t = 127, r = MOD, pw[(ll)1e5 + 10ll];
string s;
vector<ll> h;

ll binpow(ll a, ll n) {
    if (n == 0) return 1;
    if (n % 2) return (a % r * binpow(a, n - 1) % r) % r;
    return (binpow((a % r) * (a % r), n / 2) % r) % r;
}

ll mult(ll a, ll b) {
    ll res = a * b;
    if (res >= r) res %= r;
    return res;
}

ll sum(ll a, ll b) {
    ll res = a + b;
    if (res >= r) res -= r;
    return res;
}

void hashh() {
    ll n = s.size();
    h.pb((ll)s[0] % r);
    for (ll i = 1; i < n; ++i) h.pb(sum(mult(h[i - 1] % r, t % r), s[i] % r));
}   

ll mins(ll a, ll b) {
    ll res = a - b;
    if (res < 0) res += r;
    if (res >= r) res -= r;
    return res;
}

void Solve() {
    pw[0] = 1;
    for (ll i = 1; i <= (ll)1e5 + 3; ++i) pw[i] = mult(pw[i - 1] % r, t % r);
    cin >> s;
    hashh();
    ll q;
    cin >> q;
    while (q--) {
        ll l1, l2;
        cin >> l1 >> l2;
        ll lhs = 0, rhs = s.size() - max(l1, l2) + 1;
        while (rhs - lhs > 1) {
            ll mid = (lhs + rhs) / 2;
            ll r1 = l1 + mid - 1;
            ll r2 = l2 + mid - 1;
            ll h1 = mins(h[r1], mult(l1 ? h[l1 - 1] : 0ll, pw[r1 - l1 + 1]));
            ll h2 = mins(h[r2], mult(l2 ? h[l2 - 1] : 0ll, pw[r1 - l1 + 1]));
            if (h1 == h2) lhs = mid;
            else rhs = mid;
        }
        cout << lhs << '\n';
    }
}

signed main() {
    fasttype;
    ll t = 1;
    // cin >> t; 
    while (t--) Solve();
    return 0;
}
