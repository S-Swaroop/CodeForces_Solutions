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

const int mod = 998244353;

void solve() {
    int n; 
    cin >> n; 
    vector<vector<int>> a(n, vector<int> (n)); 
    for(int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cin >> a[i][j]; 
        }
    }
    vector<int> dp(n + 1, 0); // number of good prefix strings 
    dp[0] = 1; // empty string
    for (int r = 1; r <= n; r++) {
        for (int l = 0; l < r; l++) {
            // considering a[l + 1 ...r] to be of same kind and a[0...l] and a[r + 1....n] the opp.
            bool good = true;
            for (int i = 1; i <= n; i++) {
                for (int j = i; j <= n; j++) {
                    if (a[i - 1][j - 1] == 1) { 
                        if (i <= l && j > l) { // violation
                            good = false; 
                        }
                    } else if (a[i - 1][j - 1] == 2) {
                        if (i > l && j <= r) { // violation
                            good = false; 
                        }
                    }
                }
            }
            dp[r] += (good ? 1 : 0) * dp[l]; 
            dp[r] %= mod; 
        }
    }
    cout << (dp[n] << 1) % mod << endl; // 2X because can be 1 or 0
}

int32_t main() {
   cin.tie(NULL) ;
   std::ios::sync_with_stdio(false) ;
   
   #ifndef ONLINE_JUDGE
   freopen("INPUT.txt","r",stdin) ;
   freopen("OUTPUT.txt","w",stdout) ;
   #endif
   
   int t = 1 ;
//    cin >> t ;/*comment this line if no test cases*/
   for(int i = 1 ; i <= t ; i++)   solve() ; 
    
   double runtime = clock() * 1.0 /CLOCKS_PER_SEC ;
   debug(runtime) ; 
   
   return 0 ;
}