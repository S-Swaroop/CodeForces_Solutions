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

inline bool isPowerOfTwo (int n) {
    return n && !(n & (n - 1)) ;
}

int smallestFactor (int x) {
    int smallest = x ; 
    for (int i = 2 ; i * i <= x ; i++) {
        if (x % i == 0) {
            smallest = min({smallest , i , x / i}) ;
        }
    }
    return smallest ;
}

void solve() {
    int n , x ; 
    cin >> n >> x ;
    if (n % x) {
        cout << -1 << endl ;
    } else {
        vector<int> a(n , 0) ;
        iota(a.begin() , a.end() , 1ll) ; 
        a[n - 1] = 1 ; 
        a[0] = x ;
        int curr = x , left = n / x ;
        while (curr != n) {
            int t = smallestFactor(left) ;
            a[curr - 1] = curr * t ;
            curr *= t ;
            left /= t ;
        }
        for (int &i : a)    cout << i << " " ;
        cout << endl ;
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