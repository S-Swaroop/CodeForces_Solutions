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
    vector<int> ones ;
    vector<int> lastof(1001 , -1) ;
    for (int i = 0 , x ; i < n ; i++) {
        cin >> x ; 
        lastof[x] = i ;
        if (x == 1) {
            ones.push_back(i) ;
        }
    }
    int ans = 0 ;
    for (int i = 1 ; i <= 1000 ; i++) {
        for (int j = i ; j <= 1000 ; j++) {
            if (lastof[i] > -1 && lastof[j] > -1 && __gcd(i , j) == 1) {
                ans = max(ans , lastof[i] + lastof[j] + 2) ;
            }
        }
    }
    if (ans == 0) ans-- ;
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