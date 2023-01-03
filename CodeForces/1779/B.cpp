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
    int n; 
    cin >> n; 
    if (n == 3) {
        cout << "NO" << endl; 
    } else if (n % 2 == 0) {
        cout << "YES" << endl; 
        for (int i = 1; i <= n / 2; i++) {
            cout << 1 << " " << -1 << " "; 
        }
        cout << endl; 
    } else {
        cout << "YES" << endl; 
        for (int i = 0; i < n; i++) {
            cout << (i & 1 ? -(n / 2) : (n / 2) - 1) << " ";
        }
        cout << endl; 
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