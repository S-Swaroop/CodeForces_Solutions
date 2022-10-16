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


int f (int need , vector<int> &t) {
    if (need < 0) {
        return INT_MAX ;
    }
    int op = 0 ;
    for (int i = t.size() - 1 ; i >= 0 && need > 0 ; i--) {
        if (need >= t[i]) {
            op++ ; 
            need -= t[i] ;
        }
    }
    if (need > 0) {
        return INT_MAX ;
    } else {
        return op ;
    }
}

void solve() {
    int n ; 
    cin >> n ;
    vector<int> a(n) ; 
    for (int &i : a) cin >> i ;
    int have = 0 ;
    vector<int> t ;
    for (int i = 0 ; i < n ; i++) {
        while (a[i] % 2 == 0) {
            have++ ;
            a[i] /= 2 ;
        }
        int c = 0 ; 
        int x = i + 1 ; 
        while (x % 2 == 0) {
            c++ ;
            x /= 2 ;
        }
        if (c > 0) {
            t.push_back(c) ;
        }
    }
    sort(t.begin() , t.end()) ;
    int ans = f(max(0ll , n - have) , t) ;
    if (ans == INT_MAX) {
        cout << -1 << endl ;
    } else {
        cout << ans << endl ;
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