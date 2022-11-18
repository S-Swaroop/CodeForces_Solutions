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
    int n , m ; 
    cin >> n >> m ;
    int twoes = 0 , fives = 0 ; 
    int N = n ; 
    int num = 1 ; 
    while (n % 2 == 0 && n > 1) {
        twoes++ ; 
        n /= 2 ;
    }
    while (n % 5 == 0 && n > 1) {
        fives++ ; 
        n /= 5 ;
    }
    // cout << twoes << " " << fives << endl ;
    while (twoes < fives && num * 2 <= m) {
        num *= 2 ;
        twoes++ ;
    }
    while (fives < twoes && num * 5 <= m) {
        num *= 5 ;
        fives++ ;
    }
    while (num * 10 <= m) {
        num *= 10 ;
    }

    num *= max(1ll , (m / num)) ;
    N *= num ;
    cout << N << endl ;
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