#include <bits/stdc++.h> // includes all standard libraries

using namespace std;

// Type aliases for convenience
using ll = long long;
using ld = long double;
using pii = pair < int, int > ;
using pll = pair < long long, long long > ;
using vi = vector < int > ;
using vll = vector < long long > ;
#define vpii vector < pair < int, int >>

    // Constants
    const int MOD = 1e9 + 7;
const ll INF = 1e18;
const ld EPS = 1e-9;

// Macros for easier coding
#define fast_io\
ios::sync_with_stdio(false);\
cin.tie(nullptr);
#define pb push_back
#define all(x)(x).begin(), (x).end()
#define rall(x)(x).rbegin(), (x).rend()
#define sz(x)(int)(x).size()
#define F first
#define S second
#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
#define Yes cout << "Yes" << '\n'
#define No cout << "No" << '\n'
#define vec_sum(v)(std::accumulate((v).begin(), (v).end(), 0))

// Debugging tools (comment these out in contests)
// #define debug(x) cerr << #x << " = " << (x) << endl

// Functions for modular arithmetic
ll mod_add(ll a, ll b, ll m = MOD) {
    return ((a % m + b % m) % m + m) % m;
}
ll mod_sub(ll a, ll b, ll m = MOD) {
    return ((a % m - b % m) % m + m) % m;
}
ll mod_mul(ll a, ll b, ll m = MOD) {
    return ((a % m) * (b % m)) % m;
}
ll mod_pow(ll base, ll exp, ll m = MOD) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            res = (res * base) % m;
        base = (base * base) % m;
        exp /= 2;
    }
    return res;
}
// Input - Output Function
template < typename T > void read_vector(vector < T > & v) {
    for (auto & x: v) {
        if constexpr(is_same_v < T, pair < int, int >> ) {
            cin >> x.first >> x.second;
        } else {
            cin >> x;
        }
    }
}

// Template for printing any vector
template < typename T > void print_vector(const vector < T > & v) {
    for (const auto & x: v) {
        if constexpr(is_same_v < T, pair < int, int >> ) {
            cout << "(" << x.first << ", " << x.second << ") ";
        } else {
            cout << x << " ";
        }
    }
    cout << '\n';
}
// Function to check if a element is in the vector
template < typename T > bool element_in(const vector < T > & v,
    const T & element) {
    return find(v.begin(), v.end(), element) != v.end();
}

// DIV-1 = 1600<= x <=2799
// DIV-2 = 1200<= x <=2399

int main() {
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
    fast_io;
    char grid[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> grid[i][j];
        }
    }
    // Check for individuals

    set < char > iws;
    // Diag check
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {

        iws.insert(grid[0][0]);
    }
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
        iws.insert(grid[2][0]);
    }

    // Checking rows for individuls
    for (int i = 0; i < 3; i++) {
        bool allsame = true;
        for (int j = 1; j < 3; j++) {
            if (grid[i][0] != grid[i][j]) {
                allsame = false;
                break;
            }
        }

        if (allsame) iws.insert(grid[i][0]);
    }

    // Checking cols for individuls
    for (int i = 0; i < 3; i++) {
        bool allsame = true;
        for (int j = 1; j < 3; j++) {
            if (grid[0][i] != grid[j][i]) {
                allsame = false;
                break;
            }
        }

        if (allsame) iws.insert(grid[0][i]);
    }

    // Computing Joint matches
    set < set < char >> jws;

    // check diags
    set < char > diag_set;

    // Primary diag
    for (int i = 0; i < 3; i++) {
        diag_set.insert(grid[i][i]);
    }
    if (sz(diag_set) == 2) {

        jws.insert(diag_set);
    }

    diag_set.clear();

    // Secorndary diag
    for (int i = 0; i < 3; i++) {
        diag_set.insert(grid[i][2 - i]);
    }
    if (sz(diag_set) == 2) {

        jws.insert(diag_set);
    }

    // Checking rows
    set < char > row_set;

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {
            row_set.insert(grid[i][j]);
        }

        if (sz(row_set) == 2) {

            jws.insert(row_set);
        }
        row_set.clear();
    }

    // Checking cols
    set < char > col_set;

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {
            col_set.insert(grid[j][i]);
        }

        if (sz(col_set) == 2) {
            jws.insert(col_set);
        }
        col_set.clear();
    }

    cout << sz(iws) << '\n';

    cout << sz(jws);
    return 0;
}
