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

int inversions (int n , vector<int> &a) {
    int ones = 0 , zeros = 0 , inv = 0 ; 
    for (int &i : a) {
        if (i) {
            ones++ ;
        } else {
            inv += ones ;
            zeros++ ;
        }
    }
    return inv ;
}

void solve() {
    int n ;
    cin >> n ; 
    vector<int> a(n) ; 
    for (int &i : a)    cin >> i ;
    int ans = inversions(n , a) ;
    for (int i = 0 ; i < n ; i++) {
        if (a[i] == 0) {
            a[i] = 1 ; 
            ans = max(ans , inversions(n , a)) ;
            a[i] = 0 ; 
            break ;
        }
    }
    for (int i = n - 1 ; i >= 0 ;i--) {
        if (a[i] == 1) {
            a[i] = 0 ; 
            ans = max(ans , inversions(n , a)) ;
            a[i] = 1 ; 
            break ;
        }
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