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
    for (int &i : a)    cin >> i ;
    if (n == 1) {
        cout << 1 << endl ;
        return ;
    } 
    bool alternating = true ;
    for (int i = 0 ; i < n ; i++) {
        alternating &= a[i] == a[(i + 2) % n] ;
    }
    if (alternating) {
        int res = 1 ;
        for (int i = 1 ; i < n ; i++) {
            if (a[i] != a[0]) {
                res++ ;
            }
        }
        cout << res << endl ;
    } else {
        cout << n << endl ;
    }
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