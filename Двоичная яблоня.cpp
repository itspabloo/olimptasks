// Представьте, как должна выглядеть яблоня в двоичном компьютерном мире. 
// Вы правы, она выглядит как двоичное дерево, то есть любая ветка двоичной яблони может ветвиться в точности на две новые ветки. 
// Занумеруем целыми числами корень двоичной яблони, точки ветвления и верхушки верхних ветвей. 
// Пусть корень дерева всегда имеет номер 1, а все числа, используемые при нумерации, лежат в пределах от 1 до N, где N — общее число пронумерованных точек. 
// На рисунке ниже приведён пример нумерации дерева с четырьмя ветвями. N здесь равно 5.
// 2   5
//  \/ 
//   3  4
//    \/
//     1
// Как вы понимаете, не очень удобно собирать яблоки с яблони, у которой много ветвей. 
// Вот почему некоторые ветви следует удалить из дерева. Но вы также заинтересованы в удалении ветвей, которое приведёт к минимальной потере яблок. 
// Известно количество яблок на каждой из ветвей, а также количество ветвей, которые нужно сохранить. 
// Ваша задача — определить, сколько яблок можно оставить на яблоне, удалив лишние ветви.


#include <bits/stdc++.h> // бесполезный комментарий code by pabL0 33798271

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define fasttype ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb push_back
#define pf push_front
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ff first
#define ss second
#define loop(a) for (ll __ = 0; __ < (a); ++__)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef void def;

using namespace __gnu_pbds;
using namespace std;

// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
template<typename T, typename T2 = null_type> struct ordered_set : public tree<T, T2, less<T>, rb_tree_tag, tree_order_statistics_node_update> {};      

const string NO = "NO\n";
const string YES = "YES\n";
const ll inf = 1e15;
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
const pair<ll, ll> NULLPAIR = {0ll, 0ll};
const long double EPS = 1e-7;
const long double PI = 3.14159265358979;

// #pragma GCC optimize("arch=sandybridge")
// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("tx,tx2,fma")
// #pragma GCC optimize("O3")

template <typename X, typename Y>
istream &operator>>(istream &in, pair<X, Y> &a) {
    in >> a.first >> a.second;
    return in;
} 

template <typename X, typename Y>
ostream &operator<<(ostream &out, pair<X, Y> &a) {
    out << a.first << ' ' << a.second << '\n';
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
    return out;
}

ll gen() { 
    static mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
    return (uniform_int_distribution<ll>(0ll, LLONG_MAX)(rnd)); 
}

ll binpow(ll a, ll n) {
    if (n == 0) return 1;
    if (n % 2) return (a % MOD2 * binpow(a, n - 1) % MOD2) % MOD2;
    return (binpow((a % MOD2) * (a % MOD2), n / 2) % MOD2) % MOD2;
}

ll sum(ll a, ll b) {
    ll res = a + b;
    if (res >= MOD2) res -= MOD2;
    return res;
}

ll mins(ll a, ll b) {
    ll res = a - b;
    if (res < 0) res += MOD2;
    if (res >= MOD2) res -= MOD2;
    return res;
}

ll mult(ll a, ll b) {
    ll res = a * b;
    if (res >= MOD2) res %= MOD2;
    return res;
}

ll inverse(ll x) {
    return binpow(x, MOD2 - 2);
}

ll del(ll a, ll b) {
    ll res = mult(a % MOD2, inverse(b) % MOD2); 
    if (res < 0) res += MOD2;
    if (res >= MOD2) res %= MOD2;
    return res;
} 

ll get() {
    ll x;
    cin >> x;
    return x;
} 

ll get(ll &n) {
    return n = get();
}

ll find(ll a, ll b, ll c) {
    if (c % gcd(a, b)) return -inf;
    ll l = 0, r = c / gcd(a, b);
}

void Solve() {  
    ll n, q;
    cin >> n >> q;
    vector<vector<pair<ll, ll>>> g(n + 1);
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
    for (ll i = 0; i < n - 1; ++i) {
        ll u, v, x;
        cin >> u >> v >> x;
        g[u].pb({v, x});
        g[v].pb({u, x});
    }
    if (n & 1 == 0) {
        cout << "0\n";
        return;
    }
    auto fill = [&](ll v, ll p, ll cost, auto f) -> void {
        for (ll i = 1; i <= n; ++i) dp[v][i] = cost;
        for (auto &x : g[v]) {
            if (x.ff == p) continue;
            f(x.ff, v, x.ss, f);
        }
    };
    auto dfs = [&](ll v, ll p, auto f) -> void {
        if (v != p && g[v].size() == 1) return;
        for (auto &[to, cost] : g[v]) {
            if (to == p) continue;
            f(to, v, f);
        }
        ll frst = g[v][0].ff;
        ll scnd = g[v][1].ff;
        if (v != p) {
            frst = (g[v][0].ff == p ? g[v][1] : g[v][0]).ff;
            scnd = (g[v][2].ff == p? g[v][1] : g[v][2]).ff;
        }
        for (ll i = 2; i <= n; ++i) {
            ll pon = dp[v][i];
            for (ll j = 0; j < i; ++j) {
                dp[v][i] = max(dp[v][i], dp[frst][j] + dp[scnd][i - j - 1] + pon);
            }
        }   
    };  
    fill(1, 1, 0, fill);
    dfs(1, 1, dfs);
    cout << dp[1][q + 1];
    return;
}   

signed main() {
    fasttype;
    // freopen("in.txt", "r", stdin);
    ll t = 1;
    // cin >> t;    
    while (t--) Solve();
    return 0;
}
