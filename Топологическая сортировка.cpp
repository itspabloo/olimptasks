// Дан ориентированный граф. Необходимо его топологически отсортировать, т.е. выписать его вершины в таком порядке, чтобы все ребра шли от более ранней вершины к более поздней.

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

const ll NMAX = 3e5;
vector<ll> g[NMAX], order;
bool used[NMAX];
ll usd[NMAX], p[NMAX];
ll end, st;

bool fnd(ll v) {
    usd[v] = 1;
    for (auto &x : g[v]) {
        if (!usd[x]) {
            if (fnd(x)) return true;
        } else if (usd[x] == 1) return true;
    }
    usd[v] = 2;
    return false;
}

void dfs(ll v) {
    used[v] = true;
	for (auto &x : g[v]) {
		if (!used[x]) dfs(x);
	}
	order.push_back(v);
}

void Solve() {
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    fill(p, p + n + 10, 0);
    fill(usd, usd + n + 10, 0);
    fill(used, used + n + 10, false);

    for (ll i = 1; i <= n; ++i) {
        if (fnd(i)) {
            cout << -1 << '\n';
            return;
        }
    }

    for (ll i = 1; i <= n; i++) {
        if (!used[i]) dfs(i);
    }

    reverse(all(order));

    for (auto &x : order) {
        cout << x << ' ';
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
