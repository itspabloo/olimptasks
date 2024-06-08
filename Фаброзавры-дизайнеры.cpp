// Фаброзавры известны своим тонким художественным вкусом и увлечением ландшафтным дизайном. 
// Они живут около очень живописной реки и то и дело перестраивают тропинку, идущую вдоль реки: либо насыпают дополнительной земли, либо срывают то, что есть. 
// Для того, чтобы упростить эти работы, они поделили всю тропинку на горизонтальные участки, пронумерованные от 1 до N, и их переделки устроены всегда одинаково: 
// они выбирают часть дороги от L-ого до R-ого участка (включительно) и изменяют (увеличивают или уменьшают) высоту на всех этих участках на одну и ту же величину 
// (если до начала переделки высоты были разными, то и после переделки они останутся разными).
// Поскольку, как уже говорилось, у фаброзавров тонкий художественный вкус, каждый из них считает, что их река лучше всего выглядит с определенной высоты. 
// Поэтому им хочется знать, есть ли поблизости от их дома место на тропинке, где высота на их взгляд оптимальна. Помогите им в этом разобраться.

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

const ll NMAX = 100010;
const ll K = 150;

ll n, m;

ll a[NMAX], add[1000];
multiset<ll> k[1000];

void diff() {
    ll l, r, x;
    cin >> l >> r >> x;
    l--, r--;
    while (l <= r) {
        if (l % K == 0 && l + K <= r) {
            if (k[l / K].count(x - add[l / K])) {
                cout << YES;
                return;
            }
            l += K;
        } else {
            if (a[l] == x - add[l / K]) {
                cout << YES;
                return;
            }
            l++;
        }
    }
    cout << NO;
    return;
}

void pluss() {
    ll l, r, x;
    cin >> l >> r >> x;
    l--, r--;
    while (l <= r) {
        if (l % K == 0 && l + K <= r) {
            add[l / K] += x;
            l += K;
        } else {
            k[l / K].extract(a[l]);
            k[l / K].insert(a[l] + x);
            a[l] += x;
            l++;
        }
    }
}

void Solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i], k[i / K].insert(a[i]);
    while (m--) {
        char c;
        cin >> c;
        if (c == '?') diff();
        else pluss();
    }
}

signed main() {
    fasttype;
    ll t = 1;
    // cin >> t;
    while (t--) Solve();
    return 0;
}
