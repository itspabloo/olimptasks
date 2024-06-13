// В Бертауне n перекрестков и m двусторонних дорог. Известно, что от любого перекрестка можно добраться до любого другого по существующим дорогам.
// С ростом количества машин в городе возникла проблема пробок. Чтобы решить эту проблему, правительство решило сделать движение на всех дорогах односторонним, таким образом разгрузив движение. 
// Ваша задача — определить, существует ли способ ввести одностороннее движение так, чтобы сохранилась возможность добраться от любого перекрестка до любого другого. 
// В случае положительного ответа также требуется найти один из возможных способов ориентировать дороги.


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
    for (auto &x : a) out << x <<' ';
    return out;
}

ll gen() { 
    static mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
    return (uniform_int_distribution<ll>(0, LLONG_MAX)(rnd)); 
}

const ll NMAX = 1e6 + 10;
vector<ll> g[NMAX];
bool used[NMAX] = {false};
ll dp[NMAX] = {inf}, h[NMAX] = {0};
vector<ll> ans;
map<pair<ll, ll>, ll> edge_to_num;
map<ll, pair<ll, ll>> num_to_edge;
map<pair<ll, ll>, ll> usd1;
 
void dfs(ll v, ll p) {
    h[v] = h[p] + 1;
    used[v] = true;
    dp[v] = h[v];
    for (auto &u : g[v]) {
        if (!used[u]) {
            dfs(u, v);
            dp[v] = min(dp[v], dp[u]);
            if (dp[u] > h[v]) {
                ans.pb(edge_to_num[make_pair(min(u, v), max(u, v))]);
            }
        } else if (u != p) dp[v] = min(dp[v], h[u]);
    }
    return;
}

void find(ll v) {
    used[v] = true;
    for (auto &u : g[v]) {
        if (!usd1[{min(u, v), max(u, v)}]) cout << v << ' ' << u << '\n', usd1[{min(u, v), max(u, v)}] = 1;
        if (!used[u]) find(u);
    }
    return;
}

void Solve() {
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        edge_to_num[make_pair(min(u, v), max(u, v))] = i + 1;
    }
    dfs(1, 0);
    cout << '\n';
    if (!ans.size()) {
        fill(used, used + n + 3, false);
        find(1);
    } else {
        cout << 0;
    }
    cout << '\n';
    return;
}

signed main() {
    fasttype;
    ll t = 1;
    // cin >> t;
    while (t--) Solve();
    return 0;
}
