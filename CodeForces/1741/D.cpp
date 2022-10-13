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
    int ans = 0 ;
    for (int c = 1 ; c <= n ; c <<= 1) {
        for (int i = 0 ; i + c < n ; i += 2 * c) {
            if (a[i] > a[i + c]) {
                ans++ ;
                for (int j = i ; j < i + c ; j++) {
                    swap(a[j] , a[j + c]) ;
                }
            }
        }
    }
    if (is_sorted(a.begin() , a.end())) {
        cout << ans << endl ;
    } else {
        cout << -1 << endl ;
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