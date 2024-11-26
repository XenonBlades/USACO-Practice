#include <bits/stdc++.h>  // includes all standard libraries
using namespace std;

// Type aliases for convenience
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vi = vector<int>;
using vll = vector<long long>;
#define vpii vector<pair<int, int>>

// Constants
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const ld EPS = 1e-9;

// Macros for easier coding
#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
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
    for (auto& x : v) {
        if constexpr (is_same_v<T, pair<int, int>>) {
            cin >> x.first >> x.second;
        } else {
            cin >> x;
        }
    }
}

// Template for printing any vector
template <typename T>
void print_vector(const vector<T>& v) {
    for (const auto& x : v) {
        if constexpr (is_same_v<T, pair<int, int>>) {
            cout << "(" << x.first << ", " << x.second << ") ";
        } else {
            cout << x << " ";
        }
    }
    cout << '\n';
}
// Function to check if a element is in the vector
template <typename T>
bool element_in(const vector<T>& v, const T& element) {
    return find(v.begin(), v.end(), element) != v.end();
}

int main() {
    fast_io;
    // freopen("speeding.in", "r", stdin);
    // freopen("speeding.out", "w", stdout);
    int N, M;
    vi speed_limit = {}, cow_speed;
    int parts, speed;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> parts >> speed;
        speed_limit.insert(speed_limit.end(), parts, speed);
    }
    for (int i = 0; i < M; i++) {
        cin >> parts >> speed;
        cow_speed.insert(cow_speed.end(), parts, speed);
    }

    int max_cross = 0;

    for (int i = 0; i < 100; i++) {
        if ((cow_speed[i] - speed_limit[i]) >= max_cross) {
            max_cross = (cow_speed[i] - speed_limit[i]);
        }
    }

    cout << max_cross;

    return 0;
}
