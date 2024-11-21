#include <bits/stdc++.h>  // includes all standard libraries
using namespace std;

// Type aliases for convenience
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vi = vector<int>;
using vll = vector<long long>;

// Constants
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const ld EPS = 1e-9;

// Macros for easier coding
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
#define Yes cout << "Yes" << '\n'
#define No cout << "No" << '\n'
#define vec_sum(v) (std::accumulate((v).begin(), (v).end(), 0))

// Debugging tools (comment these out in contests)
// #define debug(x) cerr << #x << " = " << (x) << endl

// Functions for modular arithmetic
ll mod_add(ll a, ll b, ll m = MOD) { return ((a % m + b % m) % m + m) % m; }
ll mod_sub(ll a, ll b, ll m = MOD) { return ((a % m - b % m) % m + m) % m; }
ll mod_mul(ll a, ll b, ll m = MOD) { return ((a % m) * (b % m)) % m; }
ll mod_pow(ll base, ll exp, ll m = MOD) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % m;
        base = (base * base) % m;
        exp /= 2;
    }
    return res;
}
// Input - Output Function
template <typename T>
void read_vector(vector<T>& v) {
    for (T& x : v) cin >> x;
}    
template <typename T>
void print_vector(const vector<T>& v) {
    for (const T& x : v) cout << x << " ";
    cout << '\n';
}
// Function to check if a element is in the vector
template <typename T>
bool element_in(const vector<T>& v, const T& element) {
    return find(v.begin(), v.end(), element) != v.end();
}


int main() {
    fast_io;
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    int m, n, k;
    cin >> m >> n >> k;
    string s;
    for (int i = 0; i < m; i++) {
        cin >> s;
        for (int j = 0; j < k; j++) {
            for (char x : s) {
                for (int i = 0; i < k; i++) {
                    cout << x;
                }
            }
            cout << endl;
        }
    }

    return 0;
}

