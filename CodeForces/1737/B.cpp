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
    int l , r ; 
    cin >> l >> r ; 
    int res = 0 ;
    int L = floorl(sqrtl(l)) , R = floorl(sqrtl(r)) ;
    int ans = 0 ;
    int sl = L * L , sr = R * R ;
    if (sl < l) {
        ans += (L * (L + 1)) >= l ;
        ans += (L * (L + 2)) >= l ;
        L++ ;
    }
    if (sr <= r) {
        ans += (R * R) <= r ; 
        ans += (R * (R + 1)) <= r ; 
        ans += (R * (R + 2)) <= r ;
    }
    ans += (R - L) * 3 ;
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