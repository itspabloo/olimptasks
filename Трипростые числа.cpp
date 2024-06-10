// Будем называть натуральное число трипростым, если в нем любые подряд идущие 3 цифры образуют трехзначное простое число. Требуется по данному N найти количество N-значных трипростых чисел.

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
#define MOD (ll)1e9 + 9;
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

map<pair<ll, ll>, vector<ll>> primes;

bool is_prime(ll x) {
    if (x == 1) return false;
    for (ll i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

void GeneratePrimes() {
    for (ll i = 100; i < 1000; ++i) {
        if (is_prime(i)) primes[make_pair(i / 10 % 10, i % 10)].pb(i / 100);
    }
    return;
}

void Solve() {
    ll n; 
    cin >> n;
    GeneratePrimes();
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(10, vector<ll>(10)));
    for (ll i = 100; i < 1000; ++i) {
        if (is_prime(i)) {
            dp[3][i / 10 % 10][i % 10]++;
        }
    }
    for (ll i = 4; i <= n; ++i) {
        for (ll j = 0; j < 10; ++j) {
            for (ll k = 0; k < 10; ++k) {
                for (auto &x : primes[make_pair(j, k)]) {
                    dp[i][j][k] += dp[i - 1][x][j];
                    dp[i][j][k] %= MOD;
                }
            }
        }
    }
    ll ans = 0;
    for (auto &x : dp[n]) {
        for (auto &y : x) ans += y, ans %= MOD;
    }
    cout << ans << '\n';
    return;
}

signed main() {
    fasttype;
    int t = 1;
    // cin >> t;
    while (t--) Solve();
    return 0;
}
