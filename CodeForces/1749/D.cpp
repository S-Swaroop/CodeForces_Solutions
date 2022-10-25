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

const int mod = 998244353 ;

int add (int x , int y) {
    return (x % mod + y % mod) ;
}

int sub (int x , int y) {
    return (x - y + mod) % mod ;
}

int mul (int x , int y) {
    return ((x % mod) * (y % mod)) % mod ;
}

int exp (int x , int y) {
    int res = 1 ; 
    while (y) {
        if (y & 1) {
            res = mul(res , x) ;
        } 
        x = mul(x , x) ;
        y >>= 1 ; 
    }
    return res ;
}

bool isPrime (int n) {
    for (int i = 2 ; i * i <= n ; i++) {
        if (n % i == 0) {
            return false ;
        }
    }
    return true ;
}

void solve() {
    int n , m ; 
    cin >> n >> m ; 
    int ans = 0 ; 
    for (int i = 1 ; i <= n ; i++) {
        ans = add(ans , exp(m , i)) ;
    }
    int curr = 1 ;
    int count = 1 ;
    for (int i = 1 ; i <= n ; i++) {
        if (curr > m) {
            continue ;
        }
        if (isPrime(i)) {
            curr *= i ; 
        }
        count = mul(count , (m / curr) % mod) ;
        ans = sub(ans , count) ;
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
//    cin >> t ;/*comment this line if no test cases*/
   for(int i = 1 ; i <= t ; i++)   solve() ; 
    
   double runtime = clock() * 1.0 /CLOCKS_PER_SEC ;
   debug(runtime) ; 
   
   return 0 ;
}