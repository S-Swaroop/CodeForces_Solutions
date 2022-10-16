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
    vector<int> indexof(n , 0) ;
    vector<int> a(n) ; 
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i] ; 
        indexof[a[i]] = i ;
    }
    int ans = 0 , l = n , r = -1 ; 
    for (int len = 1 ; len <= n ; len++) {
        if (len % 2) {
            l = min(l , indexof[len / 2]) , r = max(r , indexof[len / 2]) ;
        }
        int L = max(0ll , r - len + 1) , R = min(l , n - len) ; 
        ans += max(R - L + 1 , 0ll) ;
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