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
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % m;
        base = (base * base) % m;
        exp /= 2;
    }
    return result;
}

// Input - Output Functions
template <typename T>
void read_vector(vector<T>& v) {
    for (T& element : v) cin >> element;
}    
template <typename T>
void print_vector(const vector<T>& v) {
    for (const T& element : v) cout << element << " ";
    cout << '\n';
}

// Function to check if an element is in the vector
template <typename T>
bool element_in(const vector<T>& v, const T& element) {
    return find(v.begin(), v.end(), element) != v.end();
}

// Function to determine positions after swaps
vi positions_after_swaps(const vector<pii>& swaps, int initial_position) {
    vi positions;
    int current_position = initial_position; 
    for (int i = 0; i < sz(swaps); i++) {
        if (current_position == swaps[i].F) {
            current_position = swaps[i].S;
        } else if (current_position == swaps[i].S) {
            current_position = swaps[i].F;
        }
        positions.pb(current_position);
    }
    return positions;
}

// Function to calculate score based on guesses
int calculate_score(const vi& final_positions, const vi& guesses, int num_guesses) {
    int score = 0;
    for (int i = 0; i < num_guesses; i++) {
        if (final_positions[i] == guesses[i]) {
            score++;
        }
    }
    return score;
}

int main() {
    fast_io; 
    int num_rounds;
    cin >> num_rounds;

    vi guesses(num_rounds);
    vector<pii> swaps(num_rounds);

    for (int i = 0; i < num_rounds; i++) {
        int position1, position2, guessed_position;
        cin >> position1 >> position2 >> guessed_position;
        swaps[i] = {position1, position2};
        guesses[i] = guessed_position;
    }

    int score1 = calculate_score(positions_after_swaps(swaps, 1), guesses, num_rounds);
    int score2 = calculate_score(positions_after_swaps(swaps, 2), guesses, num_rounds);
    int score3 = calculate_score(positions_after_swaps(swaps, 3), guesses, num_rounds);

    cout << max({score1, score2, score3});

    return 0;
}
