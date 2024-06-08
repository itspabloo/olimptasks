// Астрономы часто изучают звездные карты, на которых звезды обозначены точками на плоскости, и каждая звезда задана своими декартовыми координатами. 
// Назовем уровнем звезды количество звезд, которые расположены не выше и не правее данной звезды. Астрономы хотят знать распределение уровней звезд.
// В качестве примера рассмотрим карту, показанную на рисунке выше. Уровень звезды 5 равен трем (уровень сформирован звездами с номерами 1,2и 4). Уровни звезд с номерами 2 и 4 равны одному. 
// На данной карте есть единственная звезда с уровнем, равным нулю, две звезды с уровнем, равным одному, одна звезда с уровнем два и одна звезда с уровнем три.
// От вас требуется написать программу, которая посчитает количество звезд каждого уровня на заданной карте.

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
typedef int ll;
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
 
struct Fenwik {
    ll n;
    vector<ll> t, a;
 
    Fenwik(ll _n, vector<ll> &_a) {
        n = _n;
        a = _a;
        t.resize(ceil(log2(n + 1)));
        build_tree();
    }
 
    Fenwik(ll _n) {
        n = _n;
        t.resize(n + 10);
    }
 
    ll func(ll x) {
        return x & -x;
    }
 
    void build_tree() {
        for (ll i = 0; i < n; ++i) change(i + 1, a[i]);
    }
 
    ll sum(ll r) {
        ll ans = 0;
        for (; r > 0; r -= func(r)) ans += t[r];
        return ans;
    }
 
    void change(ll pos, ll x) {
        for (ll i = pos; i <= n; i += func(i)) t[i] += x;
        return;
    }
 
    void change(ll pos) {
        change(pos, 1);
    }
 
    ll sum(ll l, ll r) {
        return sum(r) - sum(l - 1);
    }
 
    ll spusk(ll x) {
        ll l = 0, p = (1 << (t.size() - 1));
        for (;p > 0; p /= 2) {
            if (t[l + p] < x) {
                l += p;
                x -= t[p];
            } 
        }
        return l + 1;
    }
 
    ll check(ll x) {
        ll ans = t[x];
        while (func(x) != 1) {
            x -= func(x);
            ans -= t[x];
        }
        return ans;
    }
};

void compress(vector<pair<ll, ll>> &a) {
    vector<ll> b(a.size()), c(a.size());
    for (ll i = 0; i < a.size(); i++) {
        b[i] = a[i].ff;
        c[i] = a[i].ss;
    }
    sort(all(b));
    sort(all(c));
    unordered_map<ll, ll> mp, mp1;
    b.erase(unique(all(b)), b.end());
    c.erase(unique(all(c)), c.end());
    for (ll i = 0; i < b.size(); ++i) mp[b[i]] = i + 1;
    for (ll i = 0; i < c.size(); ++i) mp1[c[i]] = i + 1;
    for (auto &x : a) {
        x.ff = mp[x.ff], x.ss = mp1[x.ss];
    }
}

void Solve() {
    ll n, ans = 0;
    cin >> n;
    Fenwik t(n + 1);
    vector<pair<ll, ll>> a(n);
    cin >> a;
    compress(a);
    unordered_map<ll, ll> mp;
    sort(all(a), [](const pair<ll, ll> i, const pair<ll, ll> j) {
        return (i.ff == j.ff ? i.ss < j.ss : i.ff < j.ff);
    });
    
    for (ll i = 0; i < n; ++i) {
        mp[t.sum(a[i].ss)]++;
        t.change(a[i].ss);
    }
    for (ll i = 0; i < n; ++i) cout << mp[i] << '\n';
    return;
}


signed main() {
    fasttype;
    int t = 1;
    // cin >> t;
    while (t--) Solve();
    return 0;
}
