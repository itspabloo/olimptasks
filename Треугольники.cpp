// Дан граф. Найдите количество циклов длины 3.

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
    for (auto &x : a) out << x <<' ';
    return out;
}
 
ll gen() { 
    static mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
    return (uniform_int_distribution<ll>(0, LLONG_MAX)(rnd)); 
}
 
const ll NMAX = 3e5 + 10;
 
vector<ll> g[NMAX];
 
bool cmp(const ll &a, const ll &b) {
    return (g[a].size() < g[b].size() || g[a].size() == g[b].size() && a < b);
}
 
void Solve() {
    ll n, m, ans = 0;
    cin >> n >> m;
    vector<ll> p(n), cnt(n);
    iota(all(p), 0ll);
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (auto &x : g) sort(all(x), cmp);
    sort(all(p));
    for (auto &x : p) {
        for (auto &v : g[x]) cnt[v]++;
        for (auto &v : g[x]) {
            if (cmp(x, v)) break;
            for (auto &u : g[v]) {
                if (cmp(v, u)) break;
                ans += cnt[u];
            }
        }
        for (auto &v : g[x]) cnt[v]--;
    }
    cout << ans << '\n';
}
 
 
signed main() {
    fasttype;
    ll t = 1;
    // cin >> t;
    while (t--) Solve();
    return 0;
}
