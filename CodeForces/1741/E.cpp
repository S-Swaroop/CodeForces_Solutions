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

void solve() {
    int n ;
    cin >> n ;
    vector<int> a(n + 1 , 0) ; 
    for (int i = 1 ; i <= n ; i++)    cin >> a[i] ; 
    vector<int> dp(n + 1 , 0) ;
    dp[0] = 1 ; 
    for(int i = 1 ; i <= n ;i++) {
        if(dp[i - 1]) {
            if(i + a[i] <= n) {
                dp[i + a[i]] = 1 ;
            }
        }
        if(i - a[i] - 1 >= 0 && dp[i - a[i] - 1]) {
            dp[i] = 1 ;
        }
    }
    cout << (dp[n] ? "YES" : "NO") << endl ;
}

int32_t main() {
   cin.tie(NULL) ;
   std::ios::sync_with_stdio(false) ;
   
   #ifndef ONLINE_JUDGE
   freopen("INPUT.txt","r",stdin) ;
   freopen("OUTPUT.txt","w",stdout) ;
   #endif
   
   int t = 1 ;
   cin >> t ;/*comment this line if no test cases*/
   for(int i = 1 ; i <= t ; i++)   solve() ; 
    
   double runtime = clock() * 1.0 /CLOCKS_PER_SEC ;
   debug(runtime) ; 
   
   return 0 ;
}