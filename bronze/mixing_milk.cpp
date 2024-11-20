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

//     Initial State: 3  4  5
// 1. Pour 1->2:  0  7  5
// 2. Pour 2->3:  0  0  12
// 3. Pour 3->1:  10 0  2
// 4. Pour 1->2:  0  10 2
// 5. Pour 2->3:  0  0  12
// (The last three states then repeat in a cycle ...)


// 1->2
// 2->3
// 3->1
// 1->2
// 2->3

int main() {
    fast_io; 
    ll max_1,max_2,max_3;
    ll b_1,b_2,b_3,transfer;
    cin >> max_1 >> b_1;
    cin >> max_2 >> b_2;
    cin >> max_3 >> b_3;
    
    transfer = min(b_1,max_2-b_2); // 1->2
    b_1-=transfer;
    b_2+=transfer;
    
    transfer = min(b_2,max_3-b_3); // 2->3
    b_2-=transfer;
    b_3+=transfer;
    
    transfer = min(b_3,max_1-b_1); // 3->1
    b_3-=transfer;
    b_1+=transfer;
    
    transfer = min(b_1,max_2-b_2); // 1->2
    b_1-=transfer;
    b_2+=transfer;
        
    
    cout << b_1 << '\n' << b_2  << '\n'<< b_3;

    return 0;
}
