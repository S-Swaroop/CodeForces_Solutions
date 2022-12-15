/*
************************************
* Author : SHARAN SWAROOP          *
* https://linktr.ee/sharan_swaroop *
************************************
*/
#include<bits/stdc++.h>
#define endl '\n'
#define int int64_t
#define debug(x) cerr << #x << " : " << x << endl ;
using namespace std ;

const int N = 2e5 + 1; 
const int mod = 998244353;

vector<int> fact(N + 1); 

inline int add (int a, int b) {
    return ((a % mod) + (b % mod)) % mod; 
}

inline int mul (int a, int b) {
    return ((a % mod) * (b % mod)) % mod; 
}

int mod_exp (int a, int b) {
    int res = 1; 
    a %= mod; 
    while (b > 0) {
        if (b & 1) {
            res = mul(res, a); 
        }
        b >>= 1; 
        a = mul(a, a); 
    }
    return res; 
}

int mod_inv (int n) {
    return mod_exp(n, mod - 2); 
}

int nCr (int n, int r) {
    if (n < r) {
        return 0; 
    }
    if (r == 0) {
        return 1; 
    }
    return mul(mod_inv(fact[n - r]), mul(fact[n], mod_inv(fact[r])));
}

void precompute () {
    fact[0] = 1; 
    for (int i = 1; i <= N; i++) {
        fact[i] = mul(fact[i - 1], i); 
    }
}

void solve() {
    int n; 
    cin >> n; 
    string s; 
    cin >> s; 
    int ans = 1; 
    int streak = 0; 
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) { // already more than equal i s[i]s so can add either 1 or 0
            streak++; 
        } else { // must add either 1 or 0
            streak = 0;
        }
        ans = add(ans, mod_exp(2, streak)); 
    }
    cout << ans << endl; 
}

int32_t main() {
   cin.tie(NULL) ;
   std::ios::sync_with_stdio(false) ;
   
   #ifndef ONLINE_JUDGE
   freopen("INPUT.txt","r",stdin) ;
   freopen("OUTPUT.txt","w",stdout) ;
   #endif
   precompute(); 
   int t = 1 ;
   cin >> t ;/*comment this line if no test cases*/
   for(int i = 1 ; i <= t ; i++)   solve() ; 
    
   double runtime = clock() * 1.0 /CLOCKS_PER_SEC ;
   debug(runtime) ; 
   
   return 0 ;
}