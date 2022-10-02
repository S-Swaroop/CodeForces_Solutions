/*
***************************
* Author : SHARAN SWAROOP *
***************************
*/
#include<bits/stdc++.h>
#define endl '\n'
#define int int64_t
#define debug(x) cerr << #x << " : " << x << endl ;
using namespace std ;

const int mod = 998244353 ;
const int N = 60 ;  
int nCr[N + 1][N + 1] ;
int dp[N + 1][3] ;

void precal () {
    memset(nCr , 0 , sizeof(nCr)) ;
    memset(dp , 0 , sizeof(dp)) ;
    for (int i = 0 ; i <= N ; i++) {
        nCr[i][0] = 1 ;
        nCr[i][i] = 1 ;
    }
    for (int i = 1 ; i <= N ; i++) {
        for (int j = 1 ; j < i ; j++) {
            nCr[i][j] += nCr[i - 1][j - 1] + nCr[i - 1][j] ;
            nCr[i][j] %= mod ;
        }
    }
    dp[2][0] = dp[2][2] = 1 ; 
    dp[2][1] = 0 ;
    for (int i = 4 ; i <= N ; i++) {
        dp[i][2] = 1 ;
        dp[i][0] = (dp[i - 2][1] + nCr[i - 1][(i / 2) - 1] + mod) % mod ;
        dp[i][1] = (nCr[i][i / 2] - dp[i][0] - dp[i][2] + mod) % mod ;
    }
}

void solve() {
    int n ; 
    cin >> n ;
    cout << dp[n][0] << " " << dp[n][1] << " " << dp[n][2] << endl ;
}

int32_t main() {
   cin.tie(NULL) ;
   std::ios::sync_with_stdio(false) ;
   
   #ifndef ONLINE_JUDGE
   freopen("INPUT.txt","r",stdin) ;
   freopen("OUTPUT.txt","w",stdout) ;
   #endif
   precal() ;
   int t = 1 ;
   cin >> t ;/*comment this line if no test cases*/
   for(int i = 1 ; i <= t ; i++)   solve() ; 
    
   double runtime = clock() * 1.0 /CLOCKS_PER_SEC ;
   debug(runtime) ; 
   
   return 0 ;
}