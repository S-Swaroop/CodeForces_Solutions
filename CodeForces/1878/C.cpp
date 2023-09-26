/*
************************************
* Author : SHARAN SWAROOP          *
* https://linktr.ee/sharan_swaroop *
************************************
*/
#include<bits/stdc++.h>
#define endl '\n'
// #define int int64_t
#define int __int128_t
#define debug(x) cerr << #x << " : " << x << endl ;
using namespace std ;

void solve() {
    int64_t n, k, x;
    cin >> n >> k >> x;
    int minSum = k * (k + 1) / 2;
    int maxSum = k * ((2 * n) - k + 1) / 2;
    if (x <= maxSum && x >= minSum) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int32_t main() {
   cin.tie(NULL) ;
   std::ios::sync_with_stdio(false) ;
   
   #ifndef ONLINE_JUDGE
   freopen("INPUT.txt","r",stdin) ;
   freopen("OUTPUT.txt","w",stdout) ;
   #endif
   
   int64_t t = 1 ;
   cin >> t ;/*comment this line if no test cases*/
   for(int i = 1 ; i <= t ; i++)   solve() ; 
    
   double runtime = clock() * 1.0 /CLOCKS_PER_SEC ;
   debug(runtime) ; 
   
   return 0 ;
}