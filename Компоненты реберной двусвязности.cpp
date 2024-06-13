// Компонентой реберной двусвязности графа ⟨V,E⟩ называется подмножество вершин S⊂V, такое что для любых различных u и v из этого множества существует 
// не менее двух реберно не пересекающихся путей из u в v.
// Дан неориентированный граф. Требуется выделить компоненты реберной двусвязности в нем.

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

// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
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

const ll NMAX = 2e5 + 10;
vector<ll> g[NMAX];
bool used[NMAX] = {false};
ll dp[NMAX] = {inf}, h[NMAX] = {0}, ans[NMAX] = {0};
map<pair<ll, ll>, bool> ms;
map<pair<ll, ll>, ll> cnt;

void dfs(ll v, ll p) {
    h[v] = h[p] + 1;
    used[v] = true;
    dp[v] = h[v];
    for (auto &u : g[v]) {
        if (!used[u]) {
            dfs(u, v);
            dp[v] = min(dp[v], dp[u]);
            if (dp[u] > h[v] && cnt[{min(u, v), max(u, v)}] < 2) {
                ms[{min(u, v), max(u, v)}] = true;
            }
        } else if (u != p) dp[v] = min(dp[v], h[u]);
    }
    return;
}

void find(ll v, ll p, ll c) {
    used[v] = true;
    ans[v] = c;
    for (auto &u : g[v]) {
        if (u != p && !used[u] && !ms[{min(u, v), max(u, v)}]) find(u, v, c);
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
        cnt[{min(u, v), max(u, v)}]++;
    }
    for (ll i = 1; i <= n; ++i) {
        if (!used[i]) dfs(i, 0);
    }
    fill(used, used + n + 5, false);
    ll count = 1;
    for (ll i = 1; i <= n; ++i) {
        if (!used[i]) find(i, 0, count++);
    }
    cout << count - 1 << '\n';
    for (ll i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
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
