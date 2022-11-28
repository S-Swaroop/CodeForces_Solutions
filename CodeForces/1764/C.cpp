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
    sort(a.begin() , a.end()) ; 
    if (a[0] == a[n - 1]) {
        cout << (n >> 1) << endl ;
    } else {
        map<int , int> f ;
        for (int &i : a)    f[i]++ ;
        int lower = 0 , higher = n ; 
        int ans = 0 ; 
        for (auto &i : f) {
            higher -= i.second ;
            lower += i.second ;
            ans = max(ans , higher * lower) ;
        }
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