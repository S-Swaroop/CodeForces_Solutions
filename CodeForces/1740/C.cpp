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
    vector<int> a(n) ;
    for (auto &i : a)   cin >> i ;
    sort(a.begin() , a.end()) ;
    int b1 = a[0] , b2 = a[n - 1] ;
    int ans = 0 ; 
    for (int i = 2 ; i < n ; i++) {
        ans = max(ans , abs(b1 - a[i]) + abs(a[i] - a[i - 1])) ;
    }
    for (int i = 0 ; i < n - 2 ; i++) {
        ans = max(ans , abs(b2 - a[i]) + abs(a[i] - a[i + 1])) ;
    }
    cout << ans << endl ;
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